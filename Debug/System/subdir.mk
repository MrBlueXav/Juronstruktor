################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/my_stm32f4_discovery.c \
../System/my_stm32f4_discovery_audio_codec.c \
../System/startup_stm32f4xx.c \
../System/stm32fxxx_it.c \
../System/system_stm32f4xx.c 

OBJS += \
./System/my_stm32f4_discovery.o \
./System/my_stm32f4_discovery_audio_codec.o \
./System/startup_stm32f4xx.o \
./System/stm32fxxx_it.o \
./System/system_stm32f4xx.o 

C_DEPS += \
./System/my_stm32f4_discovery.d \
./System/my_stm32f4_discovery_audio_codec.d \
./System/startup_stm32f4xx.d \
./System/stm32fxxx_it.d \
./System/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
System/%.o: ../System/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7-m -mthumb -mfloat-abi=hard -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DSTM32F40_41xxx -D__FPU_USED -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DSTM32F407VG -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


