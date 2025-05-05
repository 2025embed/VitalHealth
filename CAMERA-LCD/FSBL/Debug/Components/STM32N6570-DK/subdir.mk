################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
C_SRCS += \
../Components/STM32N6570-DK/stm32n6570_discovery.c \
../Components/STM32N6570-DK/stm32n6570_discovery_bus.c \
../Components/STM32N6570-DK/stm32n6570_discovery_camera.c \
../Components/STM32N6570-DK/stm32n6570_discovery_lcd.c \
../Components/STM32N6570-DK/stm32n6570_discovery_ts.c 

OBJS += \
./Components/STM32N6570-DK/stm32n6570_discovery.o \
./Components/STM32N6570-DK/stm32n6570_discovery_bus.o \
./Components/STM32N6570-DK/stm32n6570_discovery_camera.o \
./Components/STM32N6570-DK/stm32n6570_discovery_lcd.o \
./Components/STM32N6570-DK/stm32n6570_discovery_ts.o 

C_DEPS += \
./Components/STM32N6570-DK/stm32n6570_discovery.d \
./Components/STM32N6570-DK/stm32n6570_discovery_bus.d \
./Components/STM32N6570-DK/stm32n6570_discovery_camera.d \
./Components/STM32N6570-DK/stm32n6570_discovery_lcd.d \
./Components/STM32N6570-DK/stm32n6570_discovery_ts.d 


# 每个子目录必须为构建它所贡献的源提供规则
Components/STM32N6570-DK/%.o Components/STM32N6570-DK/%.su Components/STM32N6570-DK/%.cyclo: ../Components/STM32N6570-DK/%.c Components/STM32N6570-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Inc -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/evision" -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/lib" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/Fonts" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/lcd" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/rk050hr18" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/imx335" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/STM32N6570-DK" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/Common" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Components/gt911" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-STM32N6570-2d-DK

clean-Components-2f-STM32N6570-2d-DK:
	-$(RM) ./Components/STM32N6570-DK/stm32n6570_discovery.cyclo ./Components/STM32N6570-DK/stm32n6570_discovery.d ./Components/STM32N6570-DK/stm32n6570_discovery.o ./Components/STM32N6570-DK/stm32n6570_discovery.su ./Components/STM32N6570-DK/stm32n6570_discovery_bus.cyclo ./Components/STM32N6570-DK/stm32n6570_discovery_bus.d ./Components/STM32N6570-DK/stm32n6570_discovery_bus.o ./Components/STM32N6570-DK/stm32n6570_discovery_bus.su ./Components/STM32N6570-DK/stm32n6570_discovery_camera.cyclo ./Components/STM32N6570-DK/stm32n6570_discovery_camera.d ./Components/STM32N6570-DK/stm32n6570_discovery_camera.o ./Components/STM32N6570-DK/stm32n6570_discovery_camera.su ./Components/STM32N6570-DK/stm32n6570_discovery_lcd.cyclo ./Components/STM32N6570-DK/stm32n6570_discovery_lcd.d ./Components/STM32N6570-DK/stm32n6570_discovery_lcd.o ./Components/STM32N6570-DK/stm32n6570_discovery_lcd.su ./Components/STM32N6570-DK/stm32n6570_discovery_ts.cyclo ./Components/STM32N6570-DK/stm32n6570_discovery_ts.d ./Components/STM32N6570-DK/stm32n6570_discovery_ts.o ./Components/STM32N6570-DK/stm32n6570_discovery_ts.su

.PHONY: clean-Components-2f-STM32N6570-2d-DK

