################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.c 

OBJS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.o 

C_DEPS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/%.o Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/%.su Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/%.cyclo: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/%.c Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src

clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src:
	-$(RM) ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/all_tests.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/main.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/math_helper.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src

