
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
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

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Neural ART Embedded Client API
  *          Re-target of the printf function is out-of-scope.
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\[user_name]\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"

/* USER CODE BEGIN includes */
/* USER CODE END includes */

/* Entry points --------------------------------------------------------------*/

LL_ATON_DECLARE_NAMED_NN_INSTANCE_AND_INTERFACE(tof_module_v3)
LL_ATON_RT_RetValues_t ll_aton_rt_ret = LL_ATON_RT_DONE;
uint8_t *buffer_in;
uint8_t *buffer_out;


void cube_ai_run(void)
{
	  // run 10 inferences
	    /* ------------- */
	    /* - Inference - */
	    /* ------------- */
	    /* Pre-process and fill the input buffer */
	    //_pre_process(buffer_in);
//		float raw_input_data[64] = {
//				1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
//				1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
//				1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
//				1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
//				1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
//				1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
//				1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
//				1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00
//		};
//
//
//		// 假设 buffer_in 是 uint8_t*，要强转为 float*
//		float *input_f32 = (float *)buffer_in;
//
//		for (int i = 0; i < 64; ++i) {
//			input_f32[i] = raw_input_data[i];
//		}

		int8_t raw_input_data[64] = {
				1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1,
		};

		// 假设 buffer_in 是 uint8_t*，要强转为 float*
		int8_t *input_f32 = (int8_t *)buffer_in;

		for (int i = 0; i < 64; ++i) {
			input_f32[i] = raw_input_data[i];
		}


	    /* Perform the inference */
	    LL_ATON_RT_Init_Network(&NN_Instance_tof_module_v3);  // Initialize passed network instance object
	    do {
	      /* Execute first/next step */
	      ll_aton_rt_ret = LL_ATON_RT_RunEpochBlock(&NN_Instance_tof_module_v3);
	      /* Wait for next event */
	      if (ll_aton_rt_ret == LL_ATON_RT_WFE) {
	        LL_ATON_OSAL_WFE();
	      }
	    } while (ll_aton_rt_ret != LL_ATON_RT_DONE);
	    /* Post-process the output buffer */
	    /* Invalidate the associated CPU cache region if requested */
	    //_post_process(buffer_out);

//	    float* output_f32 = (float*)buffer_out;
//	    for(int i=0; i<5 ;i++)
//	    {
//	    	printf("%f,", output_f32[i]);
//	    }
//	    printf("\n");

	    int8_t* output_f32 = (int8_t*)buffer_out;
//	    for(int i=0; i<5 ;i++)
//	    {
//	    	printf("%d,", output_f32[i]);
//	    }
//	    printf("\n");


}

void cube_ai_init(void)
{
	  const LL_Buffer_InfoTypeDef * ibuffersInfos = NN_Interface_tof_module_v3.input_buffers_info();
	  const LL_Buffer_InfoTypeDef * obuffersInfos = NN_Interface_tof_module_v3.output_buffers_info();
//		for (int i = 0; ibuffersInfos[i].name != NULL; i++) {
//			printf("----- Buffer %d -----\n", i);
//			printf("Name: %s\n", ibuffersInfos[i].name);
//			printf("Base Address: 0x%x\n", ibuffersInfos[i].addr_base);
//			printf("Offset Start: 0x%x\n", ibuffersInfos[i].offset_start);
//			printf("Offset End: 0x%x\n", ibuffersInfos[i].offset_end);
//			printf("Offset Limit: 0x%x\n", ibuffersInfos[i].offset_limit);
//			printf("Is User Allocated: %d\n", ibuffersInfos[i].is_user_allocated);
//			printf("Is Param: %d\n", ibuffersInfos[i].is_param);
//			printf("Epoch: %u\n", ibuffersInfos[i].epoch);
//			printf("Batch: %u\n", ibuffersInfos[i].batch);
//			printf("Mem NDims: %u\n", ibuffersInfos[i].mem_ndims);
//
//			if (ibuffersInfos[i].mem_shape != NULL) {
//				printf("Mem Shape: ");
//				for (int j = 0; j < ibuffersInfos[i].mem_ndims; j++) {
//					printf("%lu ", ibuffersInfos[i].mem_shape[j]);
//				}
//				printf("\n");
//			} else {
//				printf("Mem Shape: NULL\n");
//			}
//
//			printf("Channel Position: %d\n", ibuffersInfos[i].chpos);
//			printf("Data Type: %d\n", ibuffersInfos[i].type);
//			printf("Quantization Format: Qm=%d, Qn=%d, Qunsigned=%d\n",
//				   ibuffersInfos[i].Qm, ibuffersInfos[i].Qn, ibuffersInfos[i].Qunsigned);
//			printf("NDims: %u\n", ibuffersInfos[i].ndims);
//			printf("NBits: %u\n", ibuffersInfos[i].nbits);
//			printf("Per Channel: %u\n", ibuffersInfos[i].per_channel);
//
//			if (ibuffersInfos[i].shape != NULL) {
//				printf("Shape: ");
//				for (int j = 0; j < ibuffersInfos[i].ndims; j++) {
//					printf("%lu ", ibuffersInfos[i].shape[j]);
//				}
//				printf("\n");
//			} else {
//				printf("Shape: NULL\n");
//			}
//
//			if (ibuffersInfos[i].scale != NULL) {
//				printf("Scale: ");
//				for (int j = 0; j < (ibuffersInfos[i].per_channel ? ibuffersInfos[i].shape[ibuffersInfos[i].chpos] : 1); j++) {
//					printf("%f ", ibuffersInfos[i].scale[j]);
//				}
//				printf("\n");
//			} else {
//				printf("Scale: NULL\n");
//			}
//
//			if (ibuffersInfos[i].offset != NULL) {
//				printf("Offset: ");
//				for (int j = 0; j < (ibuffersInfos[i].per_channel ? ibuffersInfos[i].shape[ibuffersInfos[i].chpos] : 1); j++) {
//					printf("%d ", ibuffersInfos[i].offset[j]);
//				}
//				printf("\n");
//			} else {
//				printf("Offset: NULL\n");
//			}
//			printf("---------------------\n\n");
//		}
//
//
//		for (int i = 0; obuffersInfos[i].name != NULL; i++) {
//			  printf("----- Buffer %d -----\n", i);
//			  printf("Name: %s\n", obuffersInfos[i].name);
//			  printf("Base Address: 0x%x\n", obuffersInfos[i].addr_base);
//			  printf("Offset Start: 0x%x\n", obuffersInfos[i].offset_start);
//			  printf("Offset End: 0x%x\n", obuffersInfos[i].offset_end);
//			  printf("Offset Limit: 0x%x\n", obuffersInfos[i].offset_limit);
//			  printf("Is User Allocated: %d\n", obuffersInfos[i].is_user_allocated);
//			  printf("Is Param: %d\n", obuffersInfos[i].is_param);
//			  printf("Epoch: %u\n", obuffersInfos[i].epoch);
//			  printf("Batch: %u\n", obuffersInfos[i].batch);
//			  printf("Mem NDims: %u\n", obuffersInfos[i].mem_ndims);
//
//			  if (obuffersInfos[i].mem_shape != NULL) {
//				  printf("Mem Shape: ");
//				  for (int j = 0; j < obuffersInfos[i].mem_ndims; j++) {
//					  printf("%lu ", obuffersInfos[i].mem_shape[j]);
//				  }
//				  printf("\n");
//			  } else {
//				  printf("Mem Shape: NULL\n");
//			  }
//
//			  printf("Channel Position: %d\n", obuffersInfos[i].chpos);
//			  printf("Data Type: %d\n", obuffersInfos[i].type);
//			  printf("Quantization Format: Qm=%d, Qn=%d, Qunsigned=%d\n",
//					 obuffersInfos[i].Qm, obuffersInfos[i].Qn, obuffersInfos[i].Qunsigned);
//			  printf("NDims: %u\n", obuffersInfos[i].ndims);
//			  printf("NBits: %u\n", obuffersInfos[i].nbits);
//			  printf("Per Channel: %u\n", obuffersInfos[i].per_channel);
//
//			  if (obuffersInfos[i].shape != NULL) {
//				  printf("Shape: ");
//				  for (int j = 0; j < obuffersInfos[i].ndims; j++) {
//					  printf("%lu ", obuffersInfos[i].shape[j]);
//				  }
//				  printf("\n");
//			  } else {
//				  printf("Shape: NULL\n");
//			  }
//
//			  if (obuffersInfos[i].scale != NULL) {
//				  printf("Scale: ");
//				  for (int j = 0; j < (obuffersInfos[i].per_channel ? obuffersInfos[i].shape[obuffersInfos[i].chpos] : 1); j++) {
//					  printf("%f ", obuffersInfos[i].scale[j]);
//				  }
//				  printf("\n");
//			  } else {
//				  printf("Scale: NULL\n");
//			  }
//
//			  if (obuffersInfos[i].offset != NULL) {
//				  printf("Offset: ");
//				  for (int j = 0; j < (obuffersInfos[i].per_channel ? obuffersInfos[i].shape[obuffersInfos[i].chpos] : 1); j++) {
//					  printf("%d ", obuffersInfos[i].offset[j]);
//				  }
//				  printf("\n");
//			  } else {
//				  printf("Offset: NULL\n");
//			  }
//			  printf("---------------------\n\n");
//		  }
	  buffer_in = (uint8_t *)LL_Buffer_addr_start(&ibuffersInfos[0]);
	  buffer_out = (uint8_t *)LL_Buffer_addr_start(&obuffersInfos[0]);
	  LL_ATON_RT_RuntimeInit();
}

void cube_ai_destroy(void)
{
	LL_ATON_RT_DeInit_Network(&NN_Instance_tof_module_v3);
		/* -------------------- */
		/* - End of Inference - */
		/* -------------------- */
	  LL_ATON_RT_RuntimeDeInit();
}

void set_clk_sleep_mode(void)
{
  /* Leave clocks enabled in Low Power modes */
  // Low-power clock enable misc
#if defined (CPU_IN_SECURE_STATE)
  __HAL_RCC_DBG_CLK_SLEEP_ENABLE();
#endif
  __HAL_RCC_XSPIPHYCOMP_CLK_SLEEP_ENABLE();

  // Low-power clock enable for memories
  __HAL_RCC_AXISRAM1_MEM_CLK_SLEEP_ENABLE();
  __HAL_RCC_AXISRAM2_MEM_CLK_SLEEP_ENABLE();
  __HAL_RCC_AXISRAM3_MEM_CLK_SLEEP_ENABLE();
  __HAL_RCC_AXISRAM4_MEM_CLK_SLEEP_ENABLE();
  __HAL_RCC_AXISRAM5_MEM_CLK_SLEEP_ENABLE();
  __HAL_RCC_AXISRAM6_MEM_CLK_SLEEP_ENABLE();
  __HAL_RCC_FLEXRAM_MEM_CLK_SLEEP_ENABLE();
  __HAL_RCC_CACHEAXIRAM_MEM_CLK_SLEEP_ENABLE();
  // LP clock AHB1: None
  // LP clock AHB2: None
  // LP clock AHB3
#if defined (CPU_IN_SECURE_STATE)
  __HAL_RCC_RIFSC_CLK_SLEEP_ENABLE();
  __HAL_RCC_RISAF_CLK_SLEEP_ENABLE();
  __HAL_RCC_IAC_CLK_SLEEP_ENABLE();
#endif
  // LP clock AHB4: None
  // LP clocks AHB5
  __HAL_RCC_XSPI1_CLK_SLEEP_ENABLE();
  __HAL_RCC_XSPI2_CLK_SLEEP_ENABLE();
  __HAL_RCC_CACHEAXI_CLK_SLEEP_ENABLE();
  __HAL_RCC_NPU_CLK_SLEEP_ENABLE();
  // LP clocks APB1: None
  // LP clocks APB2
  __HAL_RCC_USART1_CLK_SLEEP_ENABLE();
  // LP clocks APB4: None
  // LP clocks APB5: None
}

void MX_X_CUBE_AI_Init(void)
{
    __HAL_RCC_AXISRAM2_MEM_CLK_ENABLE();
    __HAL_RCC_AXISRAM3_MEM_CLK_ENABLE();
    __HAL_RCC_AXISRAM4_MEM_CLK_ENABLE();
    __HAL_RCC_AXISRAM5_MEM_CLK_ENABLE();
    __HAL_RCC_AXISRAM6_MEM_CLK_ENABLE();
    set_clk_sleep_mode();
    __HAL_RCC_NPU_CLK_ENABLE();
    __HAL_RCC_NPU_FORCE_RESET();
    __HAL_RCC_NPU_RELEASE_RESET();
    npu_cache_init();
    /* USER CODE BEGIN 5 */
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 6 */
  const LL_Buffer_InfoTypeDef * ibuffersInfos = NN_Interface_tof_module_v3.input_buffers_info();
  const LL_Buffer_InfoTypeDef * obuffersInfos = NN_Interface_tof_module_v3.output_buffers_info();
  buffer_in = (uint8_t *)LL_Buffer_addr_start(&ibuffersInfos[0]);
  buffer_out = (uint8_t *)LL_Buffer_addr_start(&obuffersInfos[0]);
  LL_ATON_RT_RuntimeInit();
  // run 10 inferences
  for (int inferenceNb = 0; inferenceNb<10; ++inferenceNb) {
    /* ------------- */
    /* - Inference - */
    /* ------------- */
    /* Pre-process and fill the input buffer */
    //_pre_process(buffer_in);
    /* Perform the inference */
    LL_ATON_RT_Init_Network(&NN_Instance_tof_module_v3);  // Initialize passed network instance object
    do {
      /* Execute first/next step */
      ll_aton_rt_ret = LL_ATON_RT_RunEpochBlock(&NN_Instance_tof_module_v3);
      /* Wait for next event */
      if (ll_aton_rt_ret == LL_ATON_RT_WFE) {
        LL_ATON_OSAL_WFE();
      }
    } while (ll_aton_rt_ret != LL_ATON_RT_DONE);
    /* Post-process the output buffer */
    /* Invalidate the associated CPU cache region if requested */
    //_post_process(buffer_out);
    LL_ATON_RT_DeInit_Network(&NN_Instance_tof_module_v3);
    /* -------------------- */
    /* - End of Inference - */
    /* -------------------- */
  }
  LL_ATON_RT_RuntimeDeInit();
    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
