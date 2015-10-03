################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/HIL/Speed_Manager.c" \

C_SRCS += \
../Sources/HIL/Speed_Manager.c \

OBJS += \
./Sources/HIL/Speed_Manager_c.obj \

OBJS_QUOTED += \
"./Sources/HIL/Speed_Manager_c.obj" \

C_DEPS += \
./Sources/HIL/Speed_Manager_c.d \

C_DEPS_QUOTED += \
"./Sources/HIL/Speed_Manager_c.d" \

OBJS_OS_FORMAT += \
./Sources/HIL/Speed_Manager_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/HIL/Speed_Manager_c.obj: ../Sources/HIL/Speed_Manager.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/HIL/Speed_Manager.args" -ObjN="Sources/HIL/Speed_Manager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/HIL/%.d: ../Sources/HIL/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


