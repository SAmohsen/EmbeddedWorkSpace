################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ICU.c \
../ICU_PB.c \
../LCD.c \
../main.c \
../pwm0Signalgenrator.c \
../signalMeasurments.c 

OBJS += \
./ICU.o \
./ICU_PB.o \
./LCD.o \
./main.o \
./pwm0Signalgenrator.o \
./signalMeasurments.o 

C_DEPS += \
./ICU.d \
./ICU_PB.d \
./LCD.d \
./main.d \
./pwm0Signalgenrator.d \
./signalMeasurments.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


