################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/STM32_USB_OTG_Driver/src/usb_core.c \
../Lib/STM32_USB_OTG_Driver/src/usb_hcd.c \
../Lib/STM32_USB_OTG_Driver/src/usb_hcd_int.c 

OBJS += \
./Lib/STM32_USB_OTG_Driver/src/usb_core.o \
./Lib/STM32_USB_OTG_Driver/src/usb_hcd.o \
./Lib/STM32_USB_OTG_Driver/src/usb_hcd_int.o 

C_DEPS += \
./Lib/STM32_USB_OTG_Driver/src/usb_core.d \
./Lib/STM32_USB_OTG_Driver/src/usb_hcd.d \
./Lib/STM32_USB_OTG_Driver/src/usb_hcd_int.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/STM32_USB_OTG_Driver/src/%.o: ../Lib/STM32_USB_OTG_Driver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7-m -mthumb -mfloat-abi=hard -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DSTM32F40_41xxx -D__FPU_USED -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DSTM32F407VG -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


