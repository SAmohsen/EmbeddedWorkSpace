################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../ADC_PBcfg.c \
../DIO.c \
../DIO_PBcfg.c \
../GPT.c \
../Gpt_PBcfg.c \
../Interrupts_PBcfg.c \
../LCD.c \
../LM35.c \
../Os.c \
../SmartWatch.c \
../alarm.c \
../clock.c \
../date.c \
../interrupts.c \
../main.c \
../port.c \
../port_PBcfg.c \
../temperature.c 

OBJS += \
./ADC.o \
./ADC_PBcfg.o \
./DIO.o \
./DIO_PBcfg.o \
./GPT.o \
./Gpt_PBcfg.o \
./Interrupts_PBcfg.o \
./LCD.o \
./LM35.o \
./Os.o \
./SmartWatch.o \
./alarm.o \
./clock.o \
./date.o \
./interrupts.o \
./main.o \
./port.o \
./port_PBcfg.o \
./temperature.o 

C_DEPS += \
./ADC.d \
./ADC_PBcfg.d \
./DIO.d \
./DIO_PBcfg.d \
./GPT.d \
./Gpt_PBcfg.d \
./Interrupts_PBcfg.d \
./LCD.d \
./LM35.d \
./Os.d \
./SmartWatch.d \
./alarm.d \
./clock.d \
./date.d \
./interrupts.d \
./main.d \
./port.d \
./port_PBcfg.d \
./temperature.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


