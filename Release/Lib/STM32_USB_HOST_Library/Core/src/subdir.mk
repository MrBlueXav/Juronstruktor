################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/STM32_USB_HOST_Library/Core/src/usbh_core.c \
../Lib/STM32_USB_HOST_Library/Core/src/usbh_hcs.c \
../Lib/STM32_USB_HOST_Library/Core/src/usbh_ioreq.c \
../Lib/STM32_USB_HOST_Library/Core/src/usbh_stdreq.c 

OBJS += \
./Lib/STM32_USB_HOST_Library/Core/src/usbh_core.o \
./Lib/STM32_USB_HOST_Library/Core/src/usbh_hcs.o \
./Lib/STM32_USB_HOST_Library/Core/src/usbh_ioreq.o \
./Lib/STM32_USB_HOST_Library/Core/src/usbh_stdreq.o 

C_DEPS += \
./Lib/STM32_USB_HOST_Library/Core/src/usbh_core.d \
./Lib/STM32_USB_HOST_Library/Core/src/usbh_hcs.d \
./Lib/STM32_USB_HOST_Library/Core/src/usbh_ioreq.d \
./Lib/STM32_USB_HOST_Library/Core/src/usbh_stdreq.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/STM32_USB_HOST_Library/Core/src/%.o: ../Lib/STM32_USB_HOST_Library/Core/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fno-builtin -fsingle-precision-constant -flto -Wall -DSTM32F40_41xxx -D__FPU_USED=1 -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DSTM32F407VG -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32_USB_HOST_Library\Core\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32_USB_OTG_Driver\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32F4xx_StdPeriph_Driver\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Synth" -I"C:\xav_dev\eclipse_luna\Juronstruktor\samples" -I"C:\xav_dev\eclipse_luna\Juronstruktor\System" -I"C:\xav_dev\eclipse_luna\Juronstruktor\USB" -I"C:\xav_dev\eclipse_luna\Juronstruktor\USB\MIDIstream_class" -std=gnu11 -flto -Wbad-function-cast -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


