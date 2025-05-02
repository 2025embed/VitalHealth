/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


// 状态读取指令：0x61 0x03 0x00 0x27 0x00 0x01 CRC
uint8_t modbus_status_cmd[] = {0x61, 0x03, 0x00, 0x27, 0x00, 0x01, 0x3D, 0xA1};

// 测量数据读取命令（从 0x0028 开始读取 6 个寄存器）
uint8_t modbus_data_cmd[] = {0x61, 0x03, 0x00, 0x28, 0x00, 0x06, 0x4C, 0x60};

// 软件复位
uint8_t modbus_soft_rst[] = {0x61, 0x06, 0x00, 0x34, 0x00, 0x01, 0x00, 0x64};

//开启连续转换
uint8_t start_continuous_trigger[] = {0x61, 0x06, 0x00, 0x36, 0x00, 0x00, 0x60, 0x64};

//用于接收数据
uint8_t rx_buf[32];

HAL_StatusTypeDef stat;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

float Modbus_Parse_Float(uint8_t*);
void Modbus_Read_Sensor(void);
void Modbus_Soft_Reset(void);
void Start_Continuous_Trigger(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
	Modbus_Soft_Reset();
	HAL_Delay(1000);
	
	Start_Continuous_Trigger();
	HAL_Delay(1000);
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		Modbus_Read_Sensor();
		HAL_Delay(1000); //此处先Delay了，迁移到N6用FreeRTOS
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */



/**
	* @brief		将接受的CO2、温度和湿度的32位数据转换为float型
	* @para		data:32位数据的数组（8位一节）
	* @retval	转换完成的float数据
	**/

float Modbus_Parse_Float(uint8_t *data) {
    union {
        uint8_t b[4];
        float f;
    } u;
    // Modbus 默认是 Big-Endian，高字节在前
    u.b[3] = data[0];
    u.b[2] = data[1];
    u.b[1] = data[2];
    u.b[0] = data[3];
    return u.f;
}

/**
	* @brief	使用ModBus协议读取数据
	* @para		None
	* @retval	None
	**/

void Modbus_Read_Sensor() {
    //读取状态（是否有数据）
		memset(rx_buf, 0, sizeof(rx_buf));
    HAL_UART_Transmit(&huart3, modbus_status_cmd, sizeof(modbus_status_cmd), 100);
		stat =  HAL_UART_Receive(&huart3, rx_buf, 7, 100);
    if (rx_buf[3] == 0x00 && rx_buf[4] == 0x01) {
        //数据就绪，读取6个寄存器
				memset(rx_buf, 0, sizeof(rx_buf));
        HAL_UART_Transmit(&huart3, modbus_data_cmd, sizeof(modbus_data_cmd), 100);
        HAL_UART_Receive(&huart3, rx_buf, 17, 200);

        //解析 CO2、温度、湿度（每个4字节，共12字节）
        float co2 = Modbus_Parse_Float(&rx_buf[3]);
        float temp = Modbus_Parse_Float(&rx_buf[7]);
        float rh = Modbus_Parse_Float(&rx_buf[11]);

        //打印
        char tx_buf[64];
        int len = snprintf(tx_buf, sizeof(tx_buf), "CO2: %.1f ppm, Temp: %.1f C, RH: %.1f%%\r\n", co2, temp, rh);
        HAL_UART_Transmit(&huart1, (uint8_t *)tx_buf, len, 200);
    }
}

/**
	* @brief	对传感器进行软件复位
	* @para		None
	* @retval	None
	**/
void Modbus_Soft_Reset()
{
		memset(rx_buf, 0, sizeof(rx_buf));
		HAL_UART_Transmit(&huart3, modbus_soft_rst, sizeof(modbus_soft_rst), 100);
		HAL_UART_Receive(&huart3, rx_buf, 8, 200);

}


/**
	* @brief	开启连续转换模式
	* @para		None
	* @retval	None
	**/
void Start_Continuous_Trigger()
{
		memset(rx_buf, 0, sizeof(rx_buf));
		HAL_UART_Transmit(&huart3, start_continuous_trigger, sizeof(start_continuous_trigger), 100);
		HAL_UART_Receive(&huart3, rx_buf, 8, 200);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
