#include "main.h"


int main(int argc, char **argv) {
	Uart_init(&UartConfigurations);
	DDRB = 0xFF;
	DCMotor_Init();
	sei();
	while (1) {
		if(uart_data=='O')
		{
			DCMotor_RotateClockwise();
			roll_leds();
		}
		else if(uart_data=='L')
		{
			DCMotor_Stop();
			turnoffLeds();

		}
		else
		{

		}

	}
}
