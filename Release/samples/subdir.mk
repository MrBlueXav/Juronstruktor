################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../samples/bon.c \
../samples/ca.c \
../samples/cee.c \
../samples/chiee.c \
../samples/con_.c \
../samples/cu.c \
../samples/de.c \
../samples/dee.c \
../samples/dieu.c \
../samples/du.c \
../samples/en.c \
../samples/fer.c \
../samples/fou.c \
../samples/le.c \
../samples/lee.c \
../samples/mer.c \
../samples/non.c \
../samples/pi.c \
../samples/pu.c \
../samples/ri.c \
../samples/sa.c \
../samples/samples.c \
../samples/su.c \
../samples/tain.c \
../samples/toi.c \
../samples/un.c 

OBJS += \
./samples/bon.o \
./samples/ca.o \
./samples/cee.o \
./samples/chiee.o \
./samples/con_.o \
./samples/cu.o \
./samples/de.o \
./samples/dee.o \
./samples/dieu.o \
./samples/du.o \
./samples/en.o \
./samples/fer.o \
./samples/fou.o \
./samples/le.o \
./samples/lee.o \
./samples/mer.o \
./samples/non.o \
./samples/pi.o \
./samples/pu.o \
./samples/ri.o \
./samples/sa.o \
./samples/samples.o \
./samples/su.o \
./samples/tain.o \
./samples/toi.o \
./samples/un.o 

C_DEPS += \
./samples/bon.d \
./samples/ca.d \
./samples/cee.d \
./samples/chiee.d \
./samples/con_.d \
./samples/cu.d \
./samples/de.d \
./samples/dee.d \
./samples/dieu.d \
./samples/du.d \
./samples/en.d \
./samples/fer.d \
./samples/fou.d \
./samples/le.d \
./samples/lee.d \
./samples/mer.d \
./samples/non.d \
./samples/pi.d \
./samples/pu.d \
./samples/ri.d \
./samples/sa.d \
./samples/samples.d \
./samples/su.d \
./samples/tain.d \
./samples/toi.d \
./samples/un.d 


# Each subdirectory must supply rules for building sources it contributes
samples/%.o: ../samples/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -ffunction-sections -fdata-sections -fno-builtin -fsingle-precision-constant -flto -Wall -DSTM32F40_41xxx -D__FPU_USED=1 -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DSTM32F407VG -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32_USB_HOST_Library\Core\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32_USB_OTG_Driver\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Lib\STM32F4xx_StdPeriph_Driver\inc" -I"C:\xav_dev\eclipse_luna\Juronstruktor\Synth" -I"C:\xav_dev\eclipse_luna\Juronstruktor\samples" -I"C:\xav_dev\eclipse_luna\Juronstruktor\System" -I"C:\xav_dev\eclipse_luna\Juronstruktor\USB" -I"C:\xav_dev\eclipse_luna\Juronstruktor\USB\MIDIstream_class" -std=gnu11 -flto -Wbad-function-cast -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


