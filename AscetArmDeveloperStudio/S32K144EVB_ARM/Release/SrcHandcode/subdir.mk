################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../SrcHandcode/FlashConfig.s 

C_SRCS += \
../SrcHandcode/HA_ADC.c \
../SrcHandcode/HA_CANDriver.c \
../SrcHandcode/HA_FTM.c \
../SrcHandcode/HA_Gpio.c \
../SrcHandcode/OS_Scheduler.c \
../SrcHandcode/OS_Task.c \
../SrcHandcode/exceptions.c \
../SrcHandcode/main.c \
../SrcHandcode/scs.c 

OBJS += \
./SrcHandcode/FlashConfig.o \
./SrcHandcode/HA_ADC.o \
./SrcHandcode/HA_CANDriver.o \
./SrcHandcode/HA_FTM.o \
./SrcHandcode/HA_Gpio.o \
./SrcHandcode/OS_Scheduler.o \
./SrcHandcode/OS_Task.o \
./SrcHandcode/exceptions.o \
./SrcHandcode/main.o \
./SrcHandcode/scs.o 

C_DEPS += \
./SrcHandcode/HA_ADC.d \
./SrcHandcode/HA_CANDriver.d \
./SrcHandcode/HA_FTM.d \
./SrcHandcode/HA_Gpio.d \
./SrcHandcode/OS_Scheduler.d \
./SrcHandcode/OS_Task.d \
./SrcHandcode/exceptions.d \
./SrcHandcode/main.d \
./SrcHandcode/scs.d 


# Each subdirectory must supply rules for building sources it contributes
SrcHandcode/%.o: ../SrcHandcode/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: Arm Assembler 6'
	armclang.exe --target=arm-arm-none-eabi -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SrcHandcode/%.o: ../SrcHandcode/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Arm C Compiler 6'
	armclang.exe --target=arm-arm-none-eabi -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -IC:\work\DSworkspaces\S32K144_ArmIDE_ASCET\S32K144EVB_ARM\include -O2 -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


