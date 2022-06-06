################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/drivers/accel_LIS3DH_driver.c \
../Core/Src/drivers/gyro_I3G450D_driver.c 

C_DEPS += \
./Core/Src/drivers/accel_LIS3DH_driver.d \
./Core/Src/drivers/gyro_I3G450D_driver.d 

OBJS += \
./Core/Src/drivers/accel_LIS3DH_driver.o \
./Core/Src/drivers/gyro_I3G450D_driver.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/drivers/%.o Core/Src/drivers/%.su: ../Core/Src/drivers/%.c Core/Src/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/EdgeImpulse/Core/Inc/drivers" -I"/Users/jennie.stenhouse/Documents/LEARNING/MAKING EMBEDDED SYSTEMS/making-embedded-systems-homework/Final Project/EdgeImpulse/Core/Src/drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-drivers

clean-Core-2f-Src-2f-drivers:
	-$(RM) ./Core/Src/drivers/accel_LIS3DH_driver.d ./Core/Src/drivers/accel_LIS3DH_driver.o ./Core/Src/drivers/accel_LIS3DH_driver.su ./Core/Src/drivers/gyro_I3G450D_driver.d ./Core/Src/drivers/gyro_I3G450D_driver.o ./Core/Src/drivers/gyro_I3G450D_driver.su

.PHONY: clean-Core-2f-Src-2f-drivers

