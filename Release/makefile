################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include samples/subdir.mk
-include USB/MIDIstream_class/subdir.mk
-include USB/subdir.mk
-include System/subdir.mk
-include Synth/subdir.mk
-include Lib/STM32_USB_OTG_Driver/src/subdir.mk
-include Lib/STM32_USB_HOST_Library/Core/src/subdir.mk
-include Lib/STM32F4xx_StdPeriph_Driver/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
Juronstruktor.hex \

SECONDARY_LIST += \
Juronstruktor.lst \

SECONDARY_SIZE += \
Juronstruktor.siz \


# All Target
all: Juronstruktor.elf secondary-outputs

# Tool invocations
Juronstruktor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fno-builtin -fsingle-precision-constant -flto -Wall -T ../System/stm32f407xav.ld -nostartfiles -Xlinker --gc-sections -Wl,-Map,"Juronstruktor.map" -flto --entry=main -o "Juronstruktor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Juronstruktor.hex: Juronstruktor.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "Juronstruktor.elf"  "Juronstruktor.hex"
	@echo 'Finished building: $@'
	@echo ' '

Juronstruktor.lst: Juronstruktor.elf
	@echo 'Invoking: Cross ARM GNU Create Listing'
	arm-none-eabi-objdump --source --all-headers --demangle --line-numbers --wide "Juronstruktor.elf" > "Juronstruktor.lst"
	@echo 'Finished building: $@'
	@echo ' '

Juronstruktor.siz: Juronstruktor.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley --totals "Juronstruktor.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(S_UPPER_DEPS) Juronstruktor.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
