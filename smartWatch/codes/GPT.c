/*
 * GPT.c
 *
 *  Created on: Nov 10, 2019
 *      Author: sayed
 */

#include "GPT.h"

static  void (*Gpt0_g_Ovf_ptr)(void) = NULL_PTR ;
static  void (*Gpt0_g_Ocr_ptr)(void) = NULL_PTR ;
static  void (*Gpt2_g_Ovf_ptr)(void) = NULL_PTR ;
static  void (*Gpt2_g_Ocr_ptr)(void) = NULL_PTR ;
static  void (*Gpt1_g_Ocr_ptr)(void) = NULL_PTR ;
ISR(TIMER0_OVF_vect){

if (NULL_PTR !=Gpt0_g_Ovf_ptr)
{
	(*Gpt0_g_Ovf_ptr)();
}
}

ISR(TIMER0_COMP_vect){
	if (NULL_PTR !=Gpt0_g_Ocr_ptr)
	{
		(*Gpt0_g_Ocr_ptr)();
	}
}

ISR(TIMER2_OVF_vect){

if (NULL_PTR !=Gpt2_g_Ovf_ptr)
{
	(*Gpt2_g_Ovf_ptr)();
}
}

ISR(TIMER2_COMP_vect){
	if (NULL_PTR !=Gpt2_g_Ocr_ptr)
	{
		(*Gpt2_g_Ocr_ptr)();
	}
}
ISR(TIMER1_COMPA_vect){
	if (NULL_PTR !=Gpt1_g_Ocr_ptr)
	{
		(*Gpt1_g_Ocr_ptr)();
	}
}

void Gpt0_init(Gpt_ConfigChannel *Config_ptr){
	boolean error = FALSE;
	if (NULL_PTR == Config_ptr)
	{
		error =TRUE ;

	}
	else
	{

	}
	if (FALSE ==error )
	{
		switch(Config_ptr->mode)
		{
		case timer_mode_Normal :CLR_BIT(TCCR0,WGM00);
								CLR_BIT(TCCR0,WGM01);
		break;

		case timer_mode_CTC :CLR_BIT(TCCR0,WGM00);
							 SET_BIT(TCCR0,WGM01);
		break;
		}

		if (timer_mode_CTC ==Config_ptr->mode )
		{
			switch(Config_ptr->OCR_mode)
			{
			case OC0_disconnected: CLR_BIT(TCCR0,COM00);
								   CLR_BIT(TCCR0,COM01);
			break;
			case toggle_OC0_on_Compare_match: SET_BIT(TCCR0,COM00);
											 CLR_BIT(TCCR0,COM01);
			break;
			case clear_OC0_on_Compare_match: CLR_BIT(TCCR0,COM00);
											 SET_BIT(TCCR0,COM01);
			break;
			case set_OC0_on_Compare_Match:  SET_BIT(TCCR0,COM00);
											SET_BIT(TCCR0,COM01);
			break;
			}

		}
		else
		{

		}

		switch(Config_ptr->prescale)
		{
		case no_prescale: SET_BIT(TCCR0,CS00);
						  CLR_BIT(TCCR0,CS01);
						  CLR_BIT(TCCR0,CS02);
		break;
		case Gpt_Prescale_8:  CLR_BIT(TCCR0,CS00);
						  	  SET_BIT(TCCR0,CS01);
						  	  CLR_BIT(TCCR0,CS02);
		break;

		case Gpt_Prescale_64: SET_BIT(TCCR0,CS00);
						      SET_BIT(TCCR0,CS01);
						      CLR_BIT(TCCR0,CS02);
		break;

		case Gpt_Prescale_256: CLR_BIT(TCCR0,CS00);
						       CLR_BIT(TCCR0,CS01);
						       SET_BIT(TCCR0,CS02);
		break;
		case Gpt_Prescale_1024: SET_BIT(TCCR0,CS00);
							    CLR_BIT(TCCR0,CS01);
							    SET_BIT(TCCR0,CS02);
		break;
		}


		SET_BIT(TCCR0,FOC0);// a non PWM mode
		TCNT0  = 0x00 ;
		OCR0=0;

	}
	else
	{

	}

}

void Gpt2_init(Gpt_ConfigChannel *Config_ptr){
	boolean error = FALSE;
	if (NULL_PTR == Config_ptr)
	{
		error =TRUE ;

	}
	else
	{

	}
	if (FALSE ==error )
	{
		switch(Config_ptr->mode)
		{
		case timer_mode_Normal :CLR_BIT(TCCR2,WGM20);
								CLR_BIT(TCCR2,WGM21);
		break;

		case timer_mode_CTC :CLR_BIT(TCCR2,WGM20);
							 SET_BIT(TCCR2,WGM21);
		break;
		}

		if (timer_mode_CTC ==Config_ptr->mode )
		{
			switch(Config_ptr->OCR_mode)
			{
			case OC0_disconnected: CLR_BIT(TCCR2,COM20);
								   CLR_BIT(TCCR2,COM21);
			break;
			case toggle_OC0_on_Compare_match: SET_BIT(TCCR2,COM20);
											 CLR_BIT(TCCR2,COM21);
			break;
			case clear_OC0_on_Compare_match: CLR_BIT(TCCR2,COM20);
											 SET_BIT(TCCR2,COM21);
			break;
			case set_OC0_on_Compare_Match:  SET_BIT(TCCR2,COM20);
											SET_BIT(TCCR2,COM21);
			break;
			}

		}
		else
		{

		}

		switch(Config_ptr->prescale)
		{
		case no_prescale: SET_BIT(TCCR2,CS20);
						  CLR_BIT(TCCR2,CS21);
						  CLR_BIT(TCCR2,CS22);
		break;
		case Gpt_Prescale_8:  CLR_BIT(TCCR2,CS20);
						  	  SET_BIT(TCCR2,CS21);
						  	  CLR_BIT(TCCR2,CS22);
		break;

		case Gpt_Prescale_64: CLR_BIT(TCCR2,CS20);
						      CLR_BIT(TCCR2,CS21);
						      SET_BIT(TCCR2,CS22);
		break;

		case Gpt_Prescale_256: CLR_BIT(TCCR2,CS20);
						       SET_BIT(TCCR2,CS21);
						       SET_BIT(TCCR2,CS22);
		break;
		case Gpt_Prescale_1024: SET_BIT(TCCR2,CS20);
							    SET_BIT(TCCR2,CS21);
							    SET_BIT(TCCR2,CS22);
		break;
		}


		SET_BIT(TCCR2,FOC2);// a non PWM mode
		TCNT2  = 0x00 ;
	}
	else
	{

	}

}
void Gpt2_deinit(){
	TCNT2 = 0 ;
	OCR2 = 0 ;
	TCCR2 = 0 ;
}
void Timer1_InitoneSecond() {

	TCCR1A = 0x00 ;
	TCCR1B = 0x00 ;
	/*1024 PREscale */
	CLR_BIT(TCCR1B, CS10);
	SET_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS12);

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

	/* Initial Value */
	TCNT1 = 0 ;
	/*
	 * F_CPU = 1000000
	 * F_timer  =  1000000/ (1024)prescale =976.5HZ
	 * res = 1 / F_timer = 0.001024s
	 * one second = 0.001024 * Top
	 * top = 1/0.001024 = 976.5
	 *
	 * */
	OCR1A = 1000;
}


void Gpt0_SetOcrValue(uint8 ocr_value){

	OCR0 = ocr_value ;
}
void Gpt2_SetOcrValue(uint8 ocr_value){
	OCR2 = ocr_value ;
}
void Gpt0_OvfInterruptEnable(){
SET_BIT(TIMSK,TOIE0) ;
}
void Gpt2_OvfInterruptEnable(){
SET_BIT(TIMSK,TOIE2) ;
}

void Gpt0_OcrInterruptEnable(){
SET_BIT(TIMSK,OCIE0) ;
}
void Gpt2_OcrInterruptEnable(){
SET_BIT(TIMSK,OCIE2) ;
}
void Gpt2_OcrInterruptDisable(){
CLR_BIT(TIMSK,OCIE2) ;
}
void Gpt0_OvfSetCallback(void (*a_ptr)(void)){
Gpt0_g_Ovf_ptr =a_ptr ;
}

void Gpt2_OvfSetCallback(void (*a_ptr)(void)){
Gpt2_g_Ovf_ptr =a_ptr ;
}

void Gpt0_OcrSetCallback(void (*a_ptr)(void)){
Gpt0_g_Ocr_ptr = a_ptr;

}
void Gpt2_OcrSetCallback(void (*a_ptr)(void)){
Gpt2_g_Ocr_ptr = a_ptr;
}


void Gpt1_OcrSetCallback(void (*a_ptr)(void)){
Gpt1_g_Ocr_ptr = a_ptr;
}
