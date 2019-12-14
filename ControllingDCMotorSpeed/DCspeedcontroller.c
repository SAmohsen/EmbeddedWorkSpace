/*
 * DCspeedcontroller.c
 *
 *  Created on: Dec 14, 2019
 *      Author: sayed
 */
#include "DCspeedcontoller.h"
uint16 advalue = 0 ;
uint8 speed = 0 ;
Adc_ConfigChannel confgs = {Aref,Prescale_8,ADC_ALIGN_RIGHT};
void setup(){
	/* configure pin PA0, PA1 and PA2 as input pins */
		DDRA &= ~(1<<PB0);
		DDRA &= ~(1<<PB1);
		DDRA &= ~(1<<PB2);

		/* configure pin PD0 and PD1 as output pins */
		DDRD |= (1<<PD0);
		DDRD |= (1<<PD1);

		/* Motor is stop at the beginning */
		PORTD &= ~(1<<PD0);
		PORTD &= ~(1<<PD1);

		/*Configure ADC*/
		Adc_Init(&confgs);
		/*LCD_INIT*/
		LCD_Init();
		PWM_Timer0_Init(128);


}
void updatespeed(uint8 ocr_value){
	speed = ((float)ocr_value/255)*100;
}
void displayMotorSpeed(){
	uint8 lcdspeed[2];
	LCD_goToXY(1,1);
	LCD_SendString("MSpeed: ");
	if (speed== 100){
		LCD_SendIntegerData(speed);
	}
	else
	{
		lcdspeed[0]=speed%10;
		lcdspeed[1]=speed/10;
		LCD_SendIntegerData(lcdspeed[1]);
		LCD_SendIntegerData(lcdspeed[0]);
	}
	LCD_SendU8Data('%');
}
void loop(){
	advalue = Adc_StartConversion(Adc_channel2);
	advalue =(advalue)/4 ;
	PWM_setOCR0(advalue);
	updatespeed(OCR0);
	displayMotorSpeed();

	/* check if the first switch is pressed (Rotate clock wise) */
			if(PINB & (1<<PB0))
			{
				PORTD &= (~(1<<PD0));
				PORTD |= (1<<PD1);
			}

			/* check if the second switch is pressed (Rotate anti-clock wise) */
			else if(PINB & (1<<PB1))
			{
				PORTD |= (1<<PD0);
				PORTD &= (~(1<<PD1));
			}

			/* check if the third switch is pressed (turn off the motor) */
			else if(PINB & (1<<PB2))
			{
				PORTD &= (~(1<<PD0));
				PORTD &= (~(1<<PD1));
			}
}

