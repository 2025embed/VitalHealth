################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
C_SRCS += \
../ISP_LIB/lib/isp_algo.c \
../ISP_LIB/lib/isp_core.c \
../ISP_LIB/lib/isp_services.c 

OBJS += \
./ISP_LIB/lib/isp_algo.o \
./ISP_LIB/lib/isp_core.o \
./ISP_LIB/lib/isp_services.o 

C_DEPS += \
./ISP_LIB/lib/isp_algo.d \
./ISP_LIB/lib/isp_core.d \
./ISP_LIB/lib/isp_services.d 


# 每个子目录必须为构建它所贡献的源提供规则
ISP_LIB/lib/%.o ISP_LIB/lib/%.su ISP_LIB/lib/%.cyclo: ../ISP_LIB/lib/%.c ISP_LIB/lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Inc -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/evision" -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/lib" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/Fonts" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/lcd" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/rk050hr18" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/imx335" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/STM32N6570-DK" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/Common" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/gt911" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ISP_LIB-2f-lib

clean-ISP_LIB-2f-lib:
	-$(RM) ./ISP_LIB/lib/isp_algo.cyclo ./ISP_LIB/lib/isp_algo.d ./ISP_LIB/lib/isp_algo.o ./ISP_LIB/lib/isp_algo.su ./ISP_LIB/lib/isp_core.cyclo ./ISP_LIB/lib/isp_core.d ./ISP_LIB/lib/isp_core.o ./ISP_LIB/lib/isp_core.su ./ISP_LIB/lib/isp_services.cyclo ./ISP_LIB/lib/isp_services.d ./ISP_LIB/lib/isp_services.o ./ISP_LIB/lib/isp_services.su

.PHONY: clean-ISP_LIB-2f-lib

