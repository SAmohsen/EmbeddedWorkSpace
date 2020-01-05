/*
 * ICU.c
 *
 *  Created on: Nov 12, 2019
 *      Author: sayed
 */

#include "ICU.h"

static volatile  void (*Icu_Handler) (void) =NULL_PTR ;/* Global variables to hold the address of the call back function in the application */

	ISR(TIMER1_CAPT_vect)
{
	if (NULL_PTR != Icu_Handler)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*Icu_Handler)();
	}
}

void Icu_Init(Icu_ConfigChannel *Icu_ConfigPtr) {
	if (NULL_PTR != Icu_ConfigPtr)

	{
		TCCR1A = (1 << FOC1A) | (1 << FOC1B);/*non PWM mode*/

		if (Icu_RISING_EDGE == Icu_ConfigPtr->edge) {
			SET_BIT(TCCR1B, ICES1);/*Rising edge notification*/
		} else if (ICu_FALLING_EDGE == Icu_ConfigPtr->edge) {
			CLR_BIT(TCCR1B, ICES1);/*Falling Edge  notification*/
		} else {

		}

		switch (Icu_ConfigPtr->prescale)/*ICU PRESCALE Value*/
		{
		case Icu_no_prescale:
			SET_BIT(TCCR1B, CS10);
			CLR_BIT(TCCR1B, CS11);
			CLR_BIT(TCCR1B, CS12);

			break;
		case Icu_Prescale_8:
			CLR_BIT(TCCR1B, CS10);
			SET_BIT(TCCR1B, CS11);
			CLR_BIT(TCCR1B, CS12);
			break;

		case Icu_Prescale_64:
			SET_BIT(TCCR1B, CS10);
			SET_BIT(TCCR1B, CS11);
			CLR_BIT(TCCR1B, CS12);
			break;

		case Icu_Prescale_256:
			CLR_BIT(TCCR1B, CS10);
			CLR_BIT(TCCR1B, CS11);
			SET_BIT(TCCR1B, CS12);
			break;
		case Icu_Prescale_1024:
			SET_BIT(TCCR1B, CS10);
			CLR_BIT(TCCR1B, CS11);
			SET_BIT(TCCR1B, CS12);
			break;
		}
		SET_BIT(TIMSK, TICIE1);/*enable icu interrupts*/
		TCNT1 = 0;/* Initial Value for Timer1 */
		ICR1 = 0;/* Initial Value for the input capture register */
	}
}

/*set edge notification*/
void Icu_SetEdgeDetection(Icu_EdgeNotificationType edge) {
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	*/
	if (Icu_RISING_EDGE == edge)
	{
		SET_BIT(TCCR1B, ICES1);
	}
	else if (ICu_FALLING_EDGE == edge)
	{
		CLR_BIT(TCCR1B, ICES1);
	}
	else
	{
		/*no Action Required*/
	}


}
/*
 * Description: Function to set the Call Back function address.
 */
void Icu_SetCallback(void (*a_ptr)(void)) {
	if (a_ptr != NULL_PTR)
	{

		Icu_Handler = a_ptr;
	}
}

void Icu_EnableInterrupts(void) {
		SET_BIT(TIMSK, TICIE1);
}
/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 Icu_getInputCaptureValue(void)
{
	return ICR1;
}
/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void Icu_clearTimeValue(void)
{
	ICR1 = 0 ;
}
/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */

void Icu_Deinit(void) {

	TCNT1 = 0;
	TCCR1A =0 ;
	TCCR1B=0;
	CLR_BIT(TIMSK, TICIE1);/*clear Icu interrupts*/
	Icu_Handler = NULL_PTR;
}
