################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := clean

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include SrcHandcode/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: S32K144EVB_ARM.axf

# Tool invocations
S32K144EVB_ARM.axf: $(OBJS) ../scatter.scat $(USER_OBJS) $(LIBS)
	@echo 'Building target: $@'
	@echo 'Invoking: Arm Linker 6'
	armlink.exe --scatter="../scatter.scat" --keep="exceptions.o(vectors)" --keep="FlashConfig.o(FlashConfig)" --info=totals --info=unused -o "S32K144EVB_ARM.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS) $(C++_DEPS) $(EXECUTABLES) $(C_UPPER_DEPS) $(CXX_DEPS) $(OBJS) $(C_DEPS) $(CPP_DEPS) S32K144EVB_ARM.axf 
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
