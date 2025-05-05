################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
C_SRCS += \
../Componrnts/imx335/imx335.c \
../Componrnts/imx335/imx335_reg.c 

OBJS += \
./Componrnts/imx335/imx335.o \
./Componrnts/imx335/imx335_reg.o 

C_DEPS += \
./Componrnts/imx335/imx335.d \
./Componrnts/imx335/imx335_reg.d 


# 每个子目录必须为构建它所贡献的源提供规则
Componrnts/imx335/%.o Componrnts/imx335/%.su Componrnts/imx335/%.cyclo: ../Componrnts/imx335/%.c Componrnts/imx335/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Inc -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I"D:/projForSTM32/CAMERA-LCD/FSBL/Componrnts/Common" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Componrnts/imx335" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Componrnts/rk050hr18" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Componrnts/STM32N6570-DK" -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/evision" -I"D:/projForSTM32/CAMERA-LCD/FSBL/ISP_LIB/lib" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/Fonts" -I"D:/projForSTM32/CAMERA-LCD/FSBL/Util/lcd" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Componrnts-2f-imx335

clean-Componrnts-2f-imx335:
	-$(RM) ./Componrnts/imx335/imx335.cyclo ./Componrnts/imx335/imx335.d ./Componrnts/imx335/imx335.o ./Componrnts/imx335/imx335.su ./Componrnts/imx335/imx335_reg.cyclo ./Componrnts/imx335/imx335_reg.d ./Componrnts/imx335/imx335_reg.o ./Componrnts/imx335/imx335_reg.su

.PHONY: clean-Componrnts-2f-imx335

