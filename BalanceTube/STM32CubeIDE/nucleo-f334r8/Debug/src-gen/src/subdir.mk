################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src-gen/src/BalanceTube_STMicro_Automatic.c \
../src-gen/src/SystemLib_CounterTimer_StopWatch_Automatic.c \
../src-gen/src/SystemLib_CounterTimer_Timer_Automatic.c \
../src-gen/src/SystemLib_Miscellaneous_DeltaTimeService_Automatic.c \
../src-gen/src/SystemLib_Miscellaneous_EdgeRising_Impl.c \
../src-gen/src/Task_5ms.c \
../src-gen/src/model_GameController_Automatic.c \
../src-gen/src/model_LedController_stm32f334r8.c \
../src-gen/src/model_MainClass_stm32f334r8.c \
../src-gen/src/model_ServoController_Automatic.c \
../src-gen/src/model_Signals_stm32f334r8.c 

OBJS += \
./src-gen/src/BalanceTube_STMicro_Automatic.o \
./src-gen/src/SystemLib_CounterTimer_StopWatch_Automatic.o \
./src-gen/src/SystemLib_CounterTimer_Timer_Automatic.o \
./src-gen/src/SystemLib_Miscellaneous_DeltaTimeService_Automatic.o \
./src-gen/src/SystemLib_Miscellaneous_EdgeRising_Impl.o \
./src-gen/src/Task_5ms.o \
./src-gen/src/model_GameController_Automatic.o \
./src-gen/src/model_LedController_stm32f334r8.o \
./src-gen/src/model_MainClass_stm32f334r8.o \
./src-gen/src/model_ServoController_Automatic.o \
./src-gen/src/model_Signals_stm32f334r8.o 

C_DEPS += \
./src-gen/src/BalanceTube_STMicro_Automatic.d \
./src-gen/src/SystemLib_CounterTimer_StopWatch_Automatic.d \
./src-gen/src/SystemLib_CounterTimer_Timer_Automatic.d \
./src-gen/src/SystemLib_Miscellaneous_DeltaTimeService_Automatic.d \
./src-gen/src/SystemLib_Miscellaneous_EdgeRising_Impl.d \
./src-gen/src/Task_5ms.d \
./src-gen/src/model_GameController_Automatic.d \
./src-gen/src/model_LedController_stm32f334r8.d \
./src-gen/src/model_MainClass_stm32f334r8.d \
./src-gen/src/model_ServoController_Automatic.d \
./src-gen/src/model_Signals_stm32f334r8.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/src/%.o src-gen/src/%.su src-gen/src/%.cyclo: ../src-gen/src/%.c src-gen/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F334x8 -DESDL_PLATFORM_INTERNAL_BUILD -DOSENV_USER_UNSUPPORTED -DASCET_DELTA_T_SUPPORT=1 -c -I"C:/dev/git/example_projects/embedded-world/nucleo-f334r8/Core/Src/vl53l0x" -I"C:/dev/git/example_projects/embedded-world/nucleo-f334r8/src-gen/include" -I"C:/dev/git/example_projects/embedded-world/nucleo-f334r8/src-gen/src" -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2d-gen-2f-src

clean-src-2d-gen-2f-src:
	-$(RM) ./src-gen/src/BalanceTube_STMicro_Automatic.cyclo ./src-gen/src/BalanceTube_STMicro_Automatic.d ./src-gen/src/BalanceTube_STMicro_Automatic.o ./src-gen/src/BalanceTube_STMicro_Automatic.su ./src-gen/src/SystemLib_CounterTimer_StopWatch_Automatic.cyclo ./src-gen/src/SystemLib_CounterTimer_StopWatch_Automatic.d ./src-gen/src/SystemLib_CounterTimer_StopWatch_Automatic.o ./src-gen/src/SystemLib_CounterTimer_StopWatch_Automatic.su ./src-gen/src/SystemLib_CounterTimer_Timer_Automatic.cyclo ./src-gen/src/SystemLib_CounterTimer_Timer_Automatic.d ./src-gen/src/SystemLib_CounterTimer_Timer_Automatic.o ./src-gen/src/SystemLib_CounterTimer_Timer_Automatic.su ./src-gen/src/SystemLib_Miscellaneous_DeltaTimeService_Automatic.cyclo ./src-gen/src/SystemLib_Miscellaneous_DeltaTimeService_Automatic.d ./src-gen/src/SystemLib_Miscellaneous_DeltaTimeService_Automatic.o ./src-gen/src/SystemLib_Miscellaneous_DeltaTimeService_Automatic.su ./src-gen/src/SystemLib_Miscellaneous_EdgeRising_Impl.cyclo ./src-gen/src/SystemLib_Miscellaneous_EdgeRising_Impl.d ./src-gen/src/SystemLib_Miscellaneous_EdgeRising_Impl.o ./src-gen/src/SystemLib_Miscellaneous_EdgeRising_Impl.su ./src-gen/src/Task_5ms.cyclo ./src-gen/src/Task_5ms.d ./src-gen/src/Task_5ms.o ./src-gen/src/Task_5ms.su ./src-gen/src/model_GameController_Automatic.cyclo ./src-gen/src/model_GameController_Automatic.d ./src-gen/src/model_GameController_Automatic.o ./src-gen/src/model_GameController_Automatic.su ./src-gen/src/model_LedController_stm32f334r8.cyclo ./src-gen/src/model_LedController_stm32f334r8.d ./src-gen/src/model_LedController_stm32f334r8.o ./src-gen/src/model_LedController_stm32f334r8.su ./src-gen/src/model_MainClass_stm32f334r8.cyclo ./src-gen/src/model_MainClass_stm32f334r8.d ./src-gen/src/model_MainClass_stm32f334r8.o ./src-gen/src/model_MainClass_stm32f334r8.su ./src-gen/src/model_ServoController_Automatic.cyclo ./src-gen/src/model_ServoController_Automatic.d ./src-gen/src/model_ServoController_Automatic.o ./src-gen/src/model_ServoController_Automatic.su ./src-gen/src/model_Signals_stm32f334r8.cyclo ./src-gen/src/model_Signals_stm32f334r8.d ./src-gen/src/model_Signals_stm32f334r8.o ./src-gen/src/model_Signals_stm32f334r8.su

.PHONY: clean-src-2d-gen-2f-src

