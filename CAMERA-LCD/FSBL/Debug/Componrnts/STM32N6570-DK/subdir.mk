################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
C_SRCS += \
../Componrnts/STM32N6570-DK/stm32n6570_discovery.c \
../Componrnts/STM32N6570-DK/stm32n6570_discovery_bus.c \
../Componrnts/STM32N6570-DK/stm32n6570_discovery_lcd.c \
../Componrnts/STM32N6570-DK/stm32n6570_discovery_ts.c 

OBJS += \
./Componrnts/STM32N6570-DK/stm32n6570_discovery.o \
./Componrnts/STM32N6570-DK/stm32n6570_discovery_bus.o \
./Componrnts/STM32N6570-DK/stm32n6570_discovery_lcd.o \
./Componrnts/STM32N6570-DK/stm32n6570_discovery_ts.o 

C_DEPS += \
./Componrnts/STM32N6570-DK/stm32n6570_discovery.d \
./Componrnts/STM32N6570-DK/stm32n6570_discovery_bus.d \
./Componrnts/STM32N6570-DK/stm32n6570_discovery_lcd.d \
./Componrnts/STM32N6570-DK/stm32n6570_discovery_ts.d 


# 每个子目录必须为构建它所贡献的源提供规则
Componrnts/STM32N6570-DK/%.o Componrnts/STM32N6570-DK/%.su Componrnts/STM32N6570-DK/%.cyclo: ../Componrnts/STM32N6570-DK/%.c Componrnts/STM32N6570-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Inc -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I"D:/projForSTM32/CAMERA-LCD/FSBL/Componrnts/Common" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Componrnts/imx335" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Componrnts/rk050hr18" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Componrnts/STM32N6570-DK" -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/evision" -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/lib" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/Fonts" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/lcd" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Componrnts-2f-STM32N6570-2d-DK

clean-Componrnts-2f-STM32N6570-2d-DK:
	-$(RM) ./Componrnts/STM32N6570-DK/stm32n6570_discovery.cyclo ./Componrnts/STM32N6570-DK/stm32n6570_discovery.d ./Componrnts/STM32N6570-DK/stm32n6570_discovery.o ./Componrnts/STM32N6570-DK/stm32n6570_discovery.su ./Componrnts/STM32N6570-DK/stm32n6570_discovery_bus.cyclo ./Componrnts/STM32N6570-DK/stm32n6570_discovery_bus.d ./Componrnts/STM32N6570-DK/stm32n6570_discovery_bus.o ./Componrnts/STM32N6570-DK/stm32n6570_discovery_bus.su ./Componrnts/STM32N6570-DK/stm32n6570_discovery_lcd.cyclo ./Componrnts/STM32N6570-DK/stm32n6570_discovery_lcd.d ./Componrnts/STM32N6570-DK/stm32n6570_discovery_lcd.o ./Componrnts/STM32N6570-DK/stm32n6570_discovery_lcd.su ./Componrnts/STM32N6570-DK/stm32n6570_discovery_ts.cyclo ./Componrnts/STM32N6570-DK/stm32n6570_discovery_ts.d ./Componrnts/STM32N6570-DK/stm32n6570_discovery_ts.o ./Componrnts/STM32N6570-DK/stm32n6570_discovery_ts.su

.PHONY: clean-Componrnts-2f-STM32N6570-2d-DK

