################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Synth/audio.c \
../Synth/chorusFD.c \
../Synth/delay.c \
../Synth/main.c \
../Synth/math_tools.c \
../Synth/midi_interface.c \
../Synth/oscillators.c \
../Synth/phaser.c \
../Synth/random.c \
../Synth/resonantFilter.c \
../Synth/sample_player.c \
../Synth/sequencer.c \
../Synth/sinetable.c \
../Synth/soundGen.c \
../Synth/timers.c 

OBJS += \
./Synth/audio.o \
./Synth/chorusFD.o \
./Synth/delay.o \
./Synth/main.o \
./Synth/math_tools.o \
./Synth/midi_interface.o \
./Synth/oscillators.o \
./Synth/phaser.o \
./Synth/random.o \
./Synth/resonantFilter.o \
./Synth/sample_player.o \
./Synth/sequencer.o \
./Synth/sinetable.o \
./Synth/soundGen.o \
./Synth/timers.o 

C_DEPS += \
./Synth/audio.d \
./Synth/chorusFD.d \
./Synth/delay.d \
./Synth/main.d \
./Synth/math_tools.d \
./Synth/midi_interface.d \
./Synth/oscillators.d \
./Synth/phaser.d \
./Synth/random.d \
./Synth/resonantFilter.d \
./Synth/sample_player.d \
./Synth/sequencer.d \
./Synth/sinetable.d \
./Synth/soundGen.d \
./Synth/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Synth/%.o: ../Synth/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fno-builtin -fsingle-precision-constant -flto -Wall -DSTM32F40_41xxx -D__FPU_USED=1 -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DSTM32F407VG -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32_USB_HOST_Library\Core\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32_USB_OTG_Driver\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32F4xx_StdPeriph_Driver\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Synth" -I"C:\xav_dev\eclipse_luna\Juronstruktor\samples" -I"C:\xav_dev\eclipse_luna\Juronstruktor\System" -I"C:\xav_dev\eclipse_luna\Juronstruktor\USB" -I"C:\xav_dev\eclipse_luna\Juronstruktor\USB\MIDIstream_class" -std=gnu11 -flto -Wbad-function-cast -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


