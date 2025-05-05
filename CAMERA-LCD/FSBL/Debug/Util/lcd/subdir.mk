################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
C_SRCS += \
../Util/lcd/stm32_lcd.c 

OBJS += \
./Util/lcd/stm32_lcd.o 

C_DEPS += \
./Util/lcd/stm32_lcd.d 


# 每个子目录必须为构建它所贡献的源提供规则
Util/lcd/%.o Util/lcd/%.su Util/lcd/%.cyclo: ../Util/lcd/%.c Util/lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Inc -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/evision" -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/lib" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/Fonts" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/lcd" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/rk050hr18" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/imx335" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/STM32N6570-DK" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/Common" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/gt911" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Util-2f-lcd

clean-Util-2f-lcd:
	-$(RM) ./Util/lcd/stm32_lcd.cyclo ./Util/lcd/stm32_lcd.d ./Util/lcd/stm32_lcd.o ./Util/lcd/stm32_lcd.su

.PHONY: clean-Util-2f-lcd

