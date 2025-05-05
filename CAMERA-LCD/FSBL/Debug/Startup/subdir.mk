################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
S_SRCS += \
../Startup/startup_stm32n657x0hxq_fsbl.s 

OBJS += \
./Startup/startup_stm32n657x0hxq_fsbl.o 

S_DEPS += \
./Startup/startup_stm32n657x0hxq_fsbl.d 


# 每个子目录必须为构建它所贡献的源提供规则
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m55 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32n657x0hxq_fsbl.d ./Startup/startup_stm32n657x0hxq_fsbl.o

.PHONY: clean-Startup

