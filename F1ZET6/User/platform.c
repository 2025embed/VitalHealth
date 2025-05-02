/**
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */



#include "platform.h"
#include "i2c.h"
#include "gpio.h"
#include <string.h>

#define I2C_TIMEOUT 100
#define I2C_CHUNK_SIZE    128

uint8_t VL53L5CX_RdByte(
		VL53L5CX_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_value)
{
	return HAL_I2C_Mem_Read(&hi2c1, p_platform->address, RegisterAdress, I2C_MEMADD_SIZE_16BIT, p_value, 1, I2C_TIMEOUT);
	/* Need to be implemented by customer. This function returns 0 if OK */

}

uint8_t VL53L5CX_WrByte(
		VL53L5CX_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t value)
{
	return HAL_I2C_Mem_Write(&hi2c1, p_platform->address, RegisterAdress, I2C_MEMADD_SIZE_16BIT, &value, 1, I2C_TIMEOUT);
	/* Need to be implemented by customer. This function returns 0 if OK */

}

uint8_t VL53L5CX_WrMulti(
		VL53L5CX_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_values,
		uint32_t size)
{
		uint32_t offset = 0;
    HAL_StatusTypeDef hal_status;
    uint8_t tx_buffer[I2C_CHUNK_SIZE + 2];  // 2字节寄存器地址 + 数据

    while (offset < size)
    {
        uint16_t current_chunk_size = (size - offset > I2C_CHUNK_SIZE)
                                       ? I2C_CHUNK_SIZE
                                       : (size - offset);

        // 设置16位寄存器地址（大端格式）
        tx_buffer[0] = ((RegisterAdress + offset) >> 8) & 0xFF;
        tx_buffer[1] = (RegisterAdress + offset) & 0xFF;

        // 拷贝当前块的数据
        memcpy(&tx_buffer[2], &p_values[offset], current_chunk_size);

        // 执行I2C发送
        hal_status = HAL_I2C_Master_Transmit(
            &hi2c1,
            p_platform->address,           // 设备地址（7位左移由HAL处理）
            tx_buffer,
            current_chunk_size + 2,
            I2C_TIMEOUT
        );

        if (hal_status != HAL_OK) {
            return 0x01;  // 发送失败
        }

        offset += current_chunk_size;
    }

    return 0;  // 成功
		/* Need to be implemented by customer. This function returns 0 if OK */
}
	


uint8_t VL53L5CX_RdMulti(
		VL53L5CX_Platform *p_platform,
		uint16_t RegisterAdress,
		uint8_t *p_values,
		uint32_t size)
{
		uint32_t offset = 0;
    HAL_StatusTypeDef hal_status;
    uint8_t reg_addr[2];

    while (offset < size)
    {
        uint16_t current_chunk_size = (size - offset > I2C_CHUNK_SIZE)
                                       ? I2C_CHUNK_SIZE
                                       : (size - offset);

        // 设置16bit寄存器地址（大端格式）
        reg_addr[0] = ((RegisterAdress + offset) >> 8) & 0xFF;
        reg_addr[1] = (RegisterAdress + offset) & 0xFF;

        // 第一步：发送寄存器地址
        hal_status = HAL_I2C_Master_Transmit(
            &hi2c1,
            p_platform->address,
            reg_addr,
            2,
            I2C_TIMEOUT
        );

        if (hal_status != HAL_OK) {
            return 0x01;
        }

        // 第二步：读取数据
        hal_status = HAL_I2C_Master_Receive(
            &hi2c1,
            p_platform->address,
            &p_values[offset],
            current_chunk_size,
            I2C_TIMEOUT
        );

        if (hal_status != HAL_OK) {
            return 0x02;
        }

        offset += current_chunk_size;
    }

    return 0;
	/* Need to be implemented by customer. This function returns 0 if OK */
	
}

uint8_t VL53L5CX_Reset_Sensor(
		VL53L5CX_Platform *p_platform)
{
	uint8_t status = 0;
	
	/* (Optional) Need to be implemented by customer. This function returns 0 if OK */
	
	/* Set pin LPN to LOW */
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
	/* Set pin AVDD to LOW */
	/* Set pin VDDIO  to LOW */
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, GPIO_PIN_RESET);
	VL53L5CX_WaitMs(p_platform, 100);

	/* Set pin LPN of to HIGH */
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
	/* Set pin AVDD of to HIGH */
	/* Set pin VDDIO of  to HIGH */
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, GPIO_PIN_SET);
	VL53L5CX_WaitMs(p_platform, 100);

	return status;
}

void VL53L5CX_SwapBuffer(
		uint8_t 		*buffer,
		uint16_t 	 	 size)
{
	uint32_t i, tmp;
	
	/* Example of possible implementation using <string.h> */
	for(i = 0; i < size; i = i + 4) 
	{
		tmp = (
		  buffer[i]<<24)
		|(buffer[i+1]<<16)
		|(buffer[i+2]<<8)
		|(buffer[i+3]);
		
		memcpy(&(buffer[i]), &tmp, 4);
	}
}	

uint8_t VL53L5CX_WaitMs(
		VL53L5CX_Platform *p_platform,
		uint32_t TimeMs)
{
	HAL_Delay(TimeMs);
	return 0;
	/* Need to be implemented by customer. This function returns 0 if OK */
	
}
