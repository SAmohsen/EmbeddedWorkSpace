/*
 * pwm0Signalgenrator.c
 *
 *  Created on: Jan 5, 2020
 *      Author: sayed
 */
#include "signalmeasurents.h"
static uint8 ocrvalue ;
static uint16 N ;

void PWM_Timer0_Init() {
	/*generating a 488 HZ and 50%duty cycle as initial values*/
	TCNT0 = 0; //initial timer value
	OCR0 = 128; //initial value 50% duty cycle
	DDRB = DDRB | (1 << PB3); //set OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
}

void PWM_setOCR0(uint8 duty) {
	OCR0 = duty;
}
uint16 adjustprescalvalue(uint16 N) {
	/*adjust calculated prescale to predefined prescales*/
	uint16 quantiedN;
	if (N <= 1) {
		quantiedN = 1;
	} else if ((N >1) && (N <= 8)) {
		quantiedN = 8;

	} else if ((N > 8) && (N <= 64)) {
		quantiedN = 64;
	} else if ((N > 64) && (N <= 256)) {
		quantiedN = 256;

	} else if (N > 256) {
		quantiedN = 1024;
	} else {

	}
	return quantiedN;
}
void settimer0prescaleValue(uint16 N) {
	switch (N) {
	case 1:
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;
	case 8:
		CLR_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;

	case 64:
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS02);
		break;

	case 256:
		CLR_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
	case 1024:
		SET_BIT(TCCR0, CS00);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS02);
		break;
	}

}
void displaygenratedsignal(){
uint8 duty =((float)(ocrvalue)/256)*100;
uint16 genrated_frequency=((float) (F_CPU) /(256UL * N));
LCD_goToXY(1,1);
LCD_SendString("generated signal");
LCD_goToXY(2,1);
LCD_SendString("Duty= ");
LCD_sendu32Data(duty);
LCD_SendString("freq= ");
LCD_sendu32Data(genrated_frequency);
}
void genratepwmSignal(uint8 dutycycle, uint16 freq) {
	ocrvalue = ((float) (256 * dutycycle) / (100));
	PWM_setOCR0(ocrvalue);
	 N = (float) (F_CPU) / (256UL * freq);
	N=adjustprescalvalue(N);
	settimer0prescaleValue(N);
}
