################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/console/console.c \
../Core/Src/console/consoleCommands.c \
../Core/Src/console/consoleIo.c 

OBJS += \
./Core/Src/console/console.o \
./Core/Src/console/consoleCommands.o \
./Core/Src/console/consoleIo.o 

C_DEPS += \
./Core/Src/console/console.d \
./Core/Src/console/consoleCommands.d \
./Core/Src/console/consoleIo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/console/%.o Core/Src/console/%.su: ../Core/Src/console/%.c Core/Src/console/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../USB_HOST/App -I../USB_HOST/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/drivers" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Src/drivers" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/console" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Src/console" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-console

clean-Core-2f-Src-2f-console:
	-$(RM) ./Core/Src/console/console.d ./Core/Src/console/console.o ./Core/Src/console/console.su ./Core/Src/console/consoleCommands.d ./Core/Src/console/consoleCommands.o ./Core/Src/console/consoleCommands.su ./Core/Src/console/consoleIo.d ./Core/Src/console/consoleIo.o ./Core/Src/console/consoleIo.su

.PHONY: clean-Core-2f-Src-2f-console

