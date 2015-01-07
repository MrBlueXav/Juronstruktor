################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USB/MIDIstream_class/usbh_midi_core.c 

OBJS += \
./USB/MIDIstream_class/usbh_midi_core.o 

C_DEPS += \
./USB/MIDIstream_class/usbh_midi_core.d 


# Each subdirectory must supply rules for building sources it contributes
USB/MIDIstream_class/%.o: ../USB/MIDIstream_class/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7-m -mthumb -mfloat-abi=hard -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DSTM32F40_41xxx -D__FPU_USED -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DSTM32F407VG -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


