################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BreathTrainerMode.c \
../Core/Src/ColourChangeMode.c \
../Core/Src/MovementController.c \
../Core/Src/OutputController.c \
../Core/Src/SessionController.c \
../Core/Src/console.c \
../Core/Src/consoleCommands.c \
../Core/Src/consoleIo.c \
../Core/Src/gyroI3G450D.c \
../Core/Src/lis3dh_driver.c \
../Core/Src/main.c \
../Core/Src/retarget.c \
../Core/Src/stm32_hal_neopixel.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

C_DEPS += \
./Core/Src/BreathTrainerMode.d \
./Core/Src/ColourChangeMode.d \
./Core/Src/MovementController.d \
./Core/Src/OutputController.d \
./Core/Src/SessionController.d \
./Core/Src/console.d \
./Core/Src/consoleCommands.d \
./Core/Src/consoleIo.d \
./Core/Src/gyroI3G450D.d \
./Core/Src/lis3dh_driver.d \
./Core/Src/main.d \
./Core/Src/retarget.d \
./Core/Src/stm32_hal_neopixel.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 

OBJS += \
./Core/Src/BreathTrainerMode.o \
./Core/Src/ColourChangeMode.o \
./Core/Src/MovementController.o \
./Core/Src/OutputController.o \
./Core/Src/SessionController.o \
./Core/Src/console.o \
./Core/Src/consoleCommands.o \
./Core/Src/consoleIo.o \
./Core/Src/gyroI3G450D.o \
./Core/Src/lis3dh_driver.o \
./Core/Src/main.o \
./Core/Src/retarget.o \
./Core/Src/stm32_hal_neopixel.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../USB_HOST/App -I../USB_HOST/Target -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/BreathTrainerMode.d ./Core/Src/BreathTrainerMode.o ./Core/Src/BreathTrainerMode.su ./Core/Src/ColourChangeMode.d ./Core/Src/ColourChangeMode.o ./Core/Src/ColourChangeMode.su ./Core/Src/MovementController.d ./Core/Src/MovementController.o ./Core/Src/MovementController.su ./Core/Src/OutputController.d ./Core/Src/OutputController.o ./Core/Src/OutputController.su ./Core/Src/SessionController.d ./Core/Src/SessionController.o ./Core/Src/SessionController.su ./Core/Src/console.d ./Core/Src/console.o ./Core/Src/console.su ./Core/Src/consoleCommands.d ./Core/Src/consoleCommands.o ./Core/Src/consoleCommands.su ./Core/Src/consoleIo.d ./Core/Src/consoleIo.o ./Core/Src/consoleIo.su ./Core/Src/gyroI3G450D.d ./Core/Src/gyroI3G450D.o ./Core/Src/gyroI3G450D.su ./Core/Src/lis3dh_driver.d ./Core/Src/lis3dh_driver.o ./Core/Src/lis3dh_driver.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/retarget.d ./Core/Src/retarget.o ./Core/Src/retarget.su ./Core/Src/stm32_hal_neopixel.d ./Core/Src/stm32_hal_neopixel.o ./Core/Src/stm32_hal_neopixel.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

