################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/OLED/oled.c 

OBJS += \
./Drivers/OLED/oled.o 

C_DEPS += \
./Drivers/OLED/oled.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/OLED/oled.o: ../Drivers/OLED/oled.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"C:/Users/songz/Desktop/cubeMX_pro/OLED/Drivers/OLED" -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/songz/Desktop/cubeMX_pro/OLED/Drivers/u8g2/csrc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/OLED/oled.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

