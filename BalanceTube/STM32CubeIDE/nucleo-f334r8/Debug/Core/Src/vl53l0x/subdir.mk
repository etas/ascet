################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/vl53l0x/vl53l0x_api.c \
../Core/Src/vl53l0x/vl53l0x_api_calibration.c \
../Core/Src/vl53l0x/vl53l0x_api_core.c \
../Core/Src/vl53l0x/vl53l0x_api_ranging.c \
../Core/Src/vl53l0x/vl53l0x_api_strings.c \
../Core/Src/vl53l0x/vl53l0x_platform_log.c \
../Core/Src/vl53l0x/vl53l0x_tof.c 

OBJS += \
./Core/Src/vl53l0x/vl53l0x_api.o \
./Core/Src/vl53l0x/vl53l0x_api_calibration.o \
./Core/Src/vl53l0x/vl53l0x_api_core.o \
./Core/Src/vl53l0x/vl53l0x_api_ranging.o \
./Core/Src/vl53l0x/vl53l0x_api_strings.o \
./Core/Src/vl53l0x/vl53l0x_platform_log.o \
./Core/Src/vl53l0x/vl53l0x_tof.o 

C_DEPS += \
./Core/Src/vl53l0x/vl53l0x_api.d \
./Core/Src/vl53l0x/vl53l0x_api_calibration.d \
./Core/Src/vl53l0x/vl53l0x_api_core.d \
./Core/Src/vl53l0x/vl53l0x_api_ranging.d \
./Core/Src/vl53l0x/vl53l0x_api_strings.d \
./Core/Src/vl53l0x/vl53l0x_platform_log.d \
./Core/Src/vl53l0x/vl53l0x_tof.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/vl53l0x/%.o Core/Src/vl53l0x/%.su Core/Src/vl53l0x/%.cyclo: ../Core/Src/vl53l0x/%.c Core/Src/vl53l0x/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F334x8 -DESDL_PLATFORM_INTERNAL_BUILD -DOSENV_USER_UNSUPPORTED -DASCET_DELTA_T_SUPPORT=1 -c -I"C:/dev/git/example_projects/embedded-world/nucleo-f334r8/Core/Src/vl53l0x" -I"C:/dev/git/example_projects/embedded-world/nucleo-f334r8/src-gen/include" -I"C:/dev/git/example_projects/embedded-world/nucleo-f334r8/src-gen/src" -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-vl53l0x

clean-Core-2f-Src-2f-vl53l0x:
	-$(RM) ./Core/Src/vl53l0x/vl53l0x_api.cyclo ./Core/Src/vl53l0x/vl53l0x_api.d ./Core/Src/vl53l0x/vl53l0x_api.o ./Core/Src/vl53l0x/vl53l0x_api.su ./Core/Src/vl53l0x/vl53l0x_api_calibration.cyclo ./Core/Src/vl53l0x/vl53l0x_api_calibration.d ./Core/Src/vl53l0x/vl53l0x_api_calibration.o ./Core/Src/vl53l0x/vl53l0x_api_calibration.su ./Core/Src/vl53l0x/vl53l0x_api_core.cyclo ./Core/Src/vl53l0x/vl53l0x_api_core.d ./Core/Src/vl53l0x/vl53l0x_api_core.o ./Core/Src/vl53l0x/vl53l0x_api_core.su ./Core/Src/vl53l0x/vl53l0x_api_ranging.cyclo ./Core/Src/vl53l0x/vl53l0x_api_ranging.d ./Core/Src/vl53l0x/vl53l0x_api_ranging.o ./Core/Src/vl53l0x/vl53l0x_api_ranging.su ./Core/Src/vl53l0x/vl53l0x_api_strings.cyclo ./Core/Src/vl53l0x/vl53l0x_api_strings.d ./Core/Src/vl53l0x/vl53l0x_api_strings.o ./Core/Src/vl53l0x/vl53l0x_api_strings.su ./Core/Src/vl53l0x/vl53l0x_platform_log.cyclo ./Core/Src/vl53l0x/vl53l0x_platform_log.d ./Core/Src/vl53l0x/vl53l0x_platform_log.o ./Core/Src/vl53l0x/vl53l0x_platform_log.su ./Core/Src/vl53l0x/vl53l0x_tof.cyclo ./Core/Src/vl53l0x/vl53l0x_tof.d ./Core/Src/vl53l0x/vl53l0x_tof.o ./Core/Src/vl53l0x/vl53l0x_tof.su

.PHONY: clean-Core-2f-Src-2f-vl53l0x

