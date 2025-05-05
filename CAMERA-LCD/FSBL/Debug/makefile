################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# 此处定义了参与生成的所有源
-include sources.mk
-include Util/lcd/subdir.mk
-include Util/Fonts/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include ISP_LIB/lib/subdir.mk
-include Drivers/STM32N6xx_HAL_Driver/subdir.mk
-include Components/imx335/subdir.mk
-include Components/gt911/subdir.mk
-include Components/STM32N6570-DK/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := CAMERA-LCD_FSBL
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# 将这些工具调用的输入和输出添加到构建变量 
EXECUTABLES += \
CAMERA-LCD_FSBL.elf \

MAP_FILES += \
CAMERA-LCD_FSBL.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CAMERA-LCD_FSBL.list \

OBJCOPY_BIN += \
CAMERA-LCD_FSBL.bin \


# 所有目标
all: main-build

# 主构建目标
main-build: CAMERA-LCD_FSBL.elf secondary-outputs

# 工具调用
CAMERA-LCD_FSBL.elf CAMERA-LCD_FSBL.map: $(OBJS) $(USER_OBJS) D:\projForSTM32\CAMERA-LCD\FSBL\STM32N657X0HXQ_AXISRAM2_fsbl.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "CAMERA-LCD_FSBL.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m55 -T"D:\projForSTM32\CAMERA-LCD\FSBL\STM32N657X0HXQ_AXISRAM2_fsbl.ld" --specs=nosys.specs -Wl,-Map="CAMERA-LCD_FSBL.map" -Wl,--gc-sections -static -Wl,--cmse-implib -Wl,--out-implib=./secure_nsclib.o "D:\projForSTM32\CAMERA-LCD\FSBL\ISP_LIB\evision\libn6-evision-st-ae_gcc.a" "D:\projForSTM32\CAMERA-LCD\FSBL\ISP_LIB\evision\libn6-evision-awb_gcc.a" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo '已结束构建目标： $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo '已结束构建： $@'
	@echo ' '

CAMERA-LCD_FSBL.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CAMERA-LCD_FSBL.list"
	@echo '已结束构建： $@'
	@echo ' '

CAMERA-LCD_FSBL.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "CAMERA-LCD_FSBL.bin"
	@echo '已结束构建： $@'
	@echo ' '

# 其他目标
clean:
	-$(RM) CAMERA-LCD_FSBL.bin CAMERA-LCD_FSBL.elf CAMERA-LCD_FSBL.list CAMERA-LCD_FSBL.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
