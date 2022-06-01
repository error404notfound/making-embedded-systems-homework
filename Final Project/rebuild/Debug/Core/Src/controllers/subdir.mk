################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/controllers/movementInputController.c \
../Core/Src/controllers/sessionController.c \
../Core/Src/controllers/visualOutputController.c 

OBJS += \
./Core/Src/controllers/movementInputController.o \
./Core/Src/controllers/sessionController.o \
./Core/Src/controllers/visualOutputController.o 

C_DEPS += \
./Core/Src/controllers/movementInputController.d \
./Core/Src/controllers/sessionController.d \
./Core/Src/controllers/visualOutputController.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/controllers/%.o Core/Src/controllers/%.su: ../Core/Src/controllers/%.c Core/Src/controllers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../USB_HOST/App -I../USB_HOST/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/drivers" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Src/drivers" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/console" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Src/console" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/controllers" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/modes" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Src/modes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-controllers

clean-Core-2f-Src-2f-controllers:
	-$(RM) ./Core/Src/controllers/movementInputController.d ./Core/Src/controllers/movementInputController.o ./Core/Src/controllers/movementInputController.su ./Core/Src/controllers/sessionController.d ./Core/Src/controllers/sessionController.o ./Core/Src/controllers/sessionController.su ./Core/Src/controllers/visualOutputController.d ./Core/Src/controllers/visualOutputController.o ./Core/Src/controllers/visualOutputController.su

.PHONY: clean-Core-2f-Src-2f-controllers

