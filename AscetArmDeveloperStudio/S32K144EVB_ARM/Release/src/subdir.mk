################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/APPInterface_EVB.c \
../src/APP_EVB.c \
../src/APP_LeverLights_EVB.c \
../src/APP_LeverSelection_EVB.c \
../src/APP_LightDutySwitch_EVB.c \
../src/APP_RGBControl_EVB.c \
../src/APP_Sanity_EVB.c \
../src/APP_SwitchInterpretation_EVB.c \
../src/ASCTask100ms.c \
../src/ASCTask10ms.c \
../src/ASCTask1ms.c \
../src/ASCTask5ms.c \
../src/INInterface_EVB.c \
../src/IN_AnaIn_EVB.c \
../src/IN_CANConfig_EVB.c \
../src/IN_CANMessageInit_EVB.c \
../src/IN_CANRxTCM_EVB.c \
../src/IN_DigitalIn_EVB.c \
../src/IN_InputCaptureIn_EVB.c \
../src/IN_Main_EVB.c \
../src/LIB_4BitCountTest_EVB.c \
../src/LIB_4BitCount_EVB.c \
../src/LIB_CANStatus_EVB.c \
../src/LIB_Rise_EVB.c \
../src/LIB_TimerUp_EVB.c \
../src/OUT_CANTxAnalogue_EVB.c \
../src/OUT_CANTxIC_EVB.c \
../src/OUT_CANTxLever_EVB.c \
../src/OUT_DigitalOutput_EVB.c \
../src/OUT_Main_EVB.c \
../src/OUT_PWMOutput_EVB.c \
../src/S32K144Build_ARM_ArithmeticServices_EVB.c \
../src/StartupHook.c 

OBJS += \
./src/APPInterface_EVB.o \
./src/APP_EVB.o \
./src/APP_LeverLights_EVB.o \
./src/APP_LeverSelection_EVB.o \
./src/APP_LightDutySwitch_EVB.o \
./src/APP_RGBControl_EVB.o \
./src/APP_Sanity_EVB.o \
./src/APP_SwitchInterpretation_EVB.o \
./src/ASCTask100ms.o \
./src/ASCTask10ms.o \
./src/ASCTask1ms.o \
./src/ASCTask5ms.o \
./src/INInterface_EVB.o \
./src/IN_AnaIn_EVB.o \
./src/IN_CANConfig_EVB.o \
./src/IN_CANMessageInit_EVB.o \
./src/IN_CANRxTCM_EVB.o \
./src/IN_DigitalIn_EVB.o \
./src/IN_InputCaptureIn_EVB.o \
./src/IN_Main_EVB.o \
./src/LIB_4BitCountTest_EVB.o \
./src/LIB_4BitCount_EVB.o \
./src/LIB_CANStatus_EVB.o \
./src/LIB_Rise_EVB.o \
./src/LIB_TimerUp_EVB.o \
./src/OUT_CANTxAnalogue_EVB.o \
./src/OUT_CANTxIC_EVB.o \
./src/OUT_CANTxLever_EVB.o \
./src/OUT_DigitalOutput_EVB.o \
./src/OUT_Main_EVB.o \
./src/OUT_PWMOutput_EVB.o \
./src/S32K144Build_ARM_ArithmeticServices_EVB.o \
./src/StartupHook.o 

C_DEPS += \
./src/APPInterface_EVB.d \
./src/APP_EVB.d \
./src/APP_LeverLights_EVB.d \
./src/APP_LeverSelection_EVB.d \
./src/APP_LightDutySwitch_EVB.d \
./src/APP_RGBControl_EVB.d \
./src/APP_Sanity_EVB.d \
./src/APP_SwitchInterpretation_EVB.d \
./src/ASCTask100ms.d \
./src/ASCTask10ms.d \
./src/ASCTask1ms.d \
./src/ASCTask5ms.d \
./src/INInterface_EVB.d \
./src/IN_AnaIn_EVB.d \
./src/IN_CANConfig_EVB.d \
./src/IN_CANMessageInit_EVB.d \
./src/IN_CANRxTCM_EVB.d \
./src/IN_DigitalIn_EVB.d \
./src/IN_InputCaptureIn_EVB.d \
./src/IN_Main_EVB.d \
./src/LIB_4BitCountTest_EVB.d \
./src/LIB_4BitCount_EVB.d \
./src/LIB_CANStatus_EVB.d \
./src/LIB_Rise_EVB.d \
./src/LIB_TimerUp_EVB.d \
./src/OUT_CANTxAnalogue_EVB.d \
./src/OUT_CANTxIC_EVB.d \
./src/OUT_CANTxLever_EVB.d \
./src/OUT_DigitalOutput_EVB.d \
./src/OUT_Main_EVB.d \
./src/OUT_PWMOutput_EVB.d \
./src/S32K144Build_ARM_ArithmeticServices_EVB.d \
./src/StartupHook.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Arm C Compiler 6'
	armclang.exe --target=arm-arm-none-eabi -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -IC:\work\DSworkspaces\S32K144_ArmIDE_ASCET\S32K144EVB_ARM\include -O2 -MD -MP -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


