################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/HAL/ADC.c" \
"../Sources/HAL/ADC_Driver.c" \
"../Sources/HAL/MTIM.c" \

C_SRCS += \
../Sources/HAL/ADC.c \
../Sources/HAL/ADC_Driver.c \
../Sources/HAL/MTIM.c \

OBJS += \
./Sources/HAL/ADC_c.obj \
./Sources/HAL/ADC_Driver_c.obj \
./Sources/HAL/MTIM_c.obj \

OBJS_QUOTED += \
"./Sources/HAL/ADC_c.obj" \
"./Sources/HAL/ADC_Driver_c.obj" \
"./Sources/HAL/MTIM_c.obj" \

C_DEPS += \
./Sources/HAL/ADC_c.d \
./Sources/HAL/ADC_Driver_c.d \
./Sources/HAL/MTIM_c.d \

C_DEPS_QUOTED += \
"./Sources/HAL/ADC_c.d" \
"./Sources/HAL/ADC_Driver_c.d" \
"./Sources/HAL/MTIM_c.d" \

OBJS_OS_FORMAT += \
./Sources/HAL/ADC_c.obj \
./Sources/HAL/ADC_Driver_c.obj \
./Sources/HAL/MTIM_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/HAL/ADC_c.obj: ../Sources/HAL/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/HAL/ADC.args" -ObjN="Sources/HAL/ADC_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/HAL/%.d: ../Sources/HAL/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/HAL/ADC_Driver_c.obj: ../Sources/HAL/ADC_Driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/HAL/ADC_Driver.args" -ObjN="Sources/HAL/ADC_Driver_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/HAL/MTIM_c.obj: ../Sources/HAL/MTIM.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/HAL/MTIM.args" -ObjN="Sources/HAL/MTIM_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


