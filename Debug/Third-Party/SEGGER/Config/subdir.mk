################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-Party/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c 

OBJS += \
./Third-Party/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o 

C_DEPS += \
./Third-Party/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Third-Party/SEGGER/Config/%.o: ../Third-Party/SEGGER/Config/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103RBTx -DNUCLEO_F103RB -DDEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/Utilities/STM32F1xx-Nucleo" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/Third-Party/SEGGER/Config" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/Third-Party/SEGGER/SEGGER" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/Third-Party/SEGGER/OS" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/Config" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/Third-Party/FreeRTOS/org/Source/portable/GCC/ARM_CM3" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/Third-Party/FreeRTOS/org/Source/include" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/StdPeriph_Driver/inc" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/inc" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/CMSIS/device" -I"C:/Users/Lucasfa/workspace/RTOS_workspace/STM32_RTOS/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


