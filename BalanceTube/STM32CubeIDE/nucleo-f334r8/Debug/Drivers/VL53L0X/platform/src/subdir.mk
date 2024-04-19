################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/VL53L0X/platform/src/vl53l0x_platform.c \
../Drivers/VL53L0X/platform/src/vl53l0x_platform_log.c 

OBJS += \
./Drivers/VL53L0X/platform/src/vl53l0x_platform.o \
./Drivers/VL53L0X/platform/src/vl53l0x_platform_log.o 

C_DEPS += \
./Drivers/VL53L0X/platform/src/vl53l0x_platform.d \
./Drivers/VL53L0X/platform/src/vl53l0x_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/VL53L0X/platform/src/%.o Drivers/VL53L0X/platform/src/%.su Drivers/VL53L0X/platform/src/%.cyclo: ../Drivers/VL53L0X/platform/src/%.c Drivers/VL53L0X/platform/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F334x8 -c -I../Core/Inc -I"C:/Users/unu7fe/STM32CubeIDE/workspace_1.13.22/TestProject2/Drivers/VL53L0X/core/inc" -I"C:/Users/unu7fe/STM32CubeIDE/workspace_1.13.22/TestProject2/Drivers/VL53L0X/platform/inc" -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-VL53L0X-2f-platform-2f-src

clean-Drivers-2f-VL53L0X-2f-platform-2f-src:
	-$(RM) ./Drivers/VL53L0X/platform/src/vl53l0x_platform.cyclo ./Drivers/VL53L0X/platform/src/vl53l0x_platform.d ./Drivers/VL53L0X/platform/src/vl53l0x_platform.o ./Drivers/VL53L0X/platform/src/vl53l0x_platform.su ./Drivers/VL53L0X/platform/src/vl53l0x_platform_log.cyclo ./Drivers/VL53L0X/platform/src/vl53l0x_platform_log.d ./Drivers/VL53L0X/platform/src/vl53l0x_platform_log.o ./Drivers/VL53L0X/platform/src/vl53l0x_platform_log.su

.PHONY: clean-Drivers-2f-VL53L0X-2f-platform-2f-src

