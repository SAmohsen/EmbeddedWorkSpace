################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPT.c \
../KeyPad.c \
../LCD.c \
../UART.c \
../Uart_PB.c \
../door.c \
../main.c \
../passwords.c 

OBJS += \
./GPT.o \
./KeyPad.o \
./LCD.o \
./UART.o \
./Uart_PB.o \
./door.o \
./main.o \
./passwords.o 

C_DEPS += \
./GPT.d \
./KeyPad.d \
./LCD.d \
./UART.d \
./Uart_PB.d \
./door.d \
./main.d \
./passwords.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


