################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USB/usb_bsp.c \
../USB/usbh_usr.c 

OBJS += \
./USB/usb_bsp.o \
./USB/usbh_usr.o 

C_DEPS += \
./USB/usb_bsp.d \
./USB/usbh_usr.d 


# Each subdirectory must supply rules for building sources it contributes
USB/%.o: ../USB/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fno-builtin -fsingle-precision-constant -flto -Wall -DSTM32F40_41xxx -D__FPU_USED=1 -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DSTM32F407VG -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32_USB_HOST_Library\Core\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32_USB_OTG_Driver\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32F4xx_StdPeriph_Driver\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Synth" -I"C:\xav_dev\eclipse_luna\Juronstruktor\samples" -I"C:\xav_dev\eclipse_luna\Juronstruktor\System" -I"C:\xav_dev\eclipse_luna\Juronstruktor\USB" -I"C:\xav_dev\eclipse_luna\Juronstruktor\USB\MIDIstream_class" -std=gnu11 -flto -Wbad-function-cast -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


