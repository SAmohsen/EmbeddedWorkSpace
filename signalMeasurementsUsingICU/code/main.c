#include "main.h"

int main(int argc, char **argv) {
	DDRD &= ~(1 << PD6);/* Configure ICP1/PD6 as i/p pin */
	sei();/*enable Global Interrupts*/
	LCD_Init();/*initialize LCD driver */
	PWM_Timer0_Init();
	genratepwmSignal(33, 488);
	_delay_ms(500);
	captureInputSignal();
	LCD_goToXY(1, 1);
	LCD_SendString("Duty= ");
	LCD_sendu32Data(calculateSignalDutyCycle());
	LCD_SendString(" %");
	LCD_goToXY(2, 1);
	LCD_SendString("freq= ");
	LCD_sendu32Data(claculateSignalFrequency());
	LCD_SendString(" HZ");
	while (1) {

	}
}
