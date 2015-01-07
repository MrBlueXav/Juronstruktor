################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/STM32F4xx_StdPeriph_Driver/src/misc.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.c \
../Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.c 

OBJS += \
./Lib/STM32F4xx_StdPeriph_Driver/src/misc.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.o \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.o 

C_DEPS += \
./Lib/STM32F4xx_StdPeriph_Driver/src/misc.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.d \
./Lib/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/STM32F4xx_StdPeriph_Driver/src/%.o: ../Lib/STM32F4xx_StdPeriph_Driver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7-m -mthumb -mfloat-abi=hard -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DSTM32F40_41xxx -D__FPU_USED -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DSTM32F407VG -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


