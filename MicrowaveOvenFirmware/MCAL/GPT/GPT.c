/*
 * GPT.h
 *
 *  Created on: Nov 10, 2019
 *      Author: sayed
 */



#include "GPT.h"


static  void (*Gpt1_g_Ocr_ptr)(void) = NULL_PTR ;

ISR(TIMER1_COMPA_vect){
	if (NULL_PTR !=Gpt1_g_Ocr_ptr)
	{
		(*Gpt1_g_Ocr_ptr)();
	}
}

void Timer1_InitoneSecond() {
	/* Initial Value */
	TCNT1 = 0 ;
	/*
	 * F_CPU = 1000000
	 * F_timer  =  1000000/ (1024)prescale =976.5HZ
	 * res = 1 / Ftimer = 0.001024s
	 * one second = 0.001024 * Top
	 * top = 1000
	 *
	 * */
	OCR1A = 1000;


	/*OCR1A TOP : ctc mode */
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);


	/*a non pwm*/
	SET_BIT(TCCR1A, FOC1A);
	SET_BIT(TCCR1A, FOC1B);

	/*Module interrupt enable */
	SET_BIT(TIMSK, OCIE1A);

	/*1024 PREscale */
	SET_BIT(TCCR1B, CS10);
	CLR_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS12);
}

void Timer1_deInit() {
		TCCR1A = 0x00 ;
		TCCR1B = 0x00 ;
		TCNT1 = 0 ;
		OCR1A = 0;
}
void Gpt1_OcrSetCallback(void (*a_ptr)(void)){
Gpt1_g_Ocr_ptr = a_ptr;
}
