################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/modes/breath_trainer_mode.c \
../Core/Src/modes/colour_change_mode.c 

OBJS += \
./Core/Src/modes/breath_trainer_mode.o \
./Core/Src/modes/colour_change_mode.o 

C_DEPS += \
./Core/Src/modes/breath_trainer_mode.d \
./Core/Src/modes/colour_change_mode.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/modes/%.o Core/Src/modes/%.su: ../Core/Src/modes/%.c Core/Src/modes/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../USB_HOST/App -I../USB_HOST/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/drivers" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Src/drivers" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/console" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Src/console" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/controllers" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Inc/modes" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/rebuild/Core/Src/modes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-modes

clean-Core-2f-Src-2f-modes:
	-$(RM) ./Core/Src/modes/breath_trainer_mode.d ./Core/Src/modes/breath_trainer_mode.o ./Core/Src/modes/breath_trainer_mode.su ./Core/Src/modes/colour_change_mode.d ./Core/Src/modes/colour_change_mode.o ./Core/Src/modes/colour_change_mode.su

.PHONY: clean-Core-2f-Src-2f-modes

