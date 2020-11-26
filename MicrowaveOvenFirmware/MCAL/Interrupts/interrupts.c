/*
 * interrupts.c
 *
 *  Created on: Nov 13, 2019
 *      Author: sayed
 */

#include "interrupts.h"

static  void (*g_Int0Callback)(void) = NULL_PTR;
static  void (*g_Int1Callback)(void) = NULL_PTR;
static  void (*g_Int2Callback)(void) = NULL_PTR;


ISR(INT0_vect) {
	if (*g_Int0Callback != NULL_PTR)
	{
		(*g_Int0Callback)();
	}
}
ISR(INT1_vect) {
	if (*g_Int1Callback != NULL_PTR)
	{
		(*g_Int1Callback)();
	}
}
ISR(INT2_vect) {
	if (*g_Int2Callback != NULL_PTR)
	{
		(*g_Int2Callback)();
	}
}
void IU_GlobalInterruptEnable(void)
{
	SET_BIT(SREG,G_Interrupt_Enable_bit) ;
}

void IU_GlobalInterruptDisable(void)
{
	CLR_BIT(SREG,G_Interrupt_Enable_bit) ;
}

void IU_ExternalInterruptEnable(const externalInterruptConfigChannel *Config_ptr){

	if(NULL_PTR != Config_ptr)
	{
		switch(Config_ptr->mode){
		case low:
		{
			if (E_INT0 ==Config_ptr->interrupt_pin)
			{
				SET_BIT(GICR,INT0_pin) ;
				CLR_BIT(MCUCR,ISC00) ;
				CLR_BIT(MCUCR,ISC01) ;
			}
			else if (E_INT1 ==Config_ptr->interrupt_pin)
			{
				SET_BIT(GICR,INT1_pin) ;
				CLR_BIT(MCUCR,ISC10) ;
				CLR_BIT(MCUCR,ISC11) ;
			}
			else
			{

			}
		}break ;

		case logicalChange:
		{
			if (E_INT0 == Config_ptr->interrupt_pin)
			{
				SET_BIT(GICR,INT0_pin);
				SET_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
			}
			else if (E_INT1 == Config_ptr->interrupt_pin)
			{
				SET_BIT(GICR,INT1_pin);
				SET_BIT(MCUCR,ISC10) ;
				CLR_BIT(MCUCR,ISC11) ;
			}
			else
			{

			}

		}break;

		case FallingEdge:
		{
			if (E_INT0 == Config_ptr->interrupt_pin)
			{
				SET_BIT(GICR, INT0_pin);
				CLR_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
			}
			else if (E_INT1 == Config_ptr->interrupt_pin)
			{
				SET_BIT(GICR, INT1_pin);
				CLR_BIT(MCUCR,ISC10) ;
				SET_BIT(MCUCR,ISC11) ;
			}
			else if (E_INT2 == Config_ptr->interrupt_pin)
			{
				SET_BIT(GICR,INT2_pin);
				CLR_BIT(MCUCSR,ISC2) ;
			}

		}break ;

		case RisingEdge:
		{
			if (E_INT0 == Config_ptr->interrupt_pin)
			{
				SET_BIT(GICR, INT0_pin);
				SET_BIT(MCUCR,ISC01) ;
				SET_BIT(MCUCR,ISC01) ;
			}
			else if (E_INT1 == Config_ptr->interrupt_pin)
			{
				SET_BIT(GICR,INT1_pin);
				SET_BIT(MCUCR,ISC10) ;
				SET_BIT(MCUCR,ISC11) ;
			}
			else if (E_INT2 == Config_ptr->interrupt_pin)
			{
				SET_BIT(MCUCSR,ISC2) ;

			}

		}break;


		}
	}

	else
	{
		/*NO Action Required */

	}

}
void IU_ExternalInt0_setCallback(void (*a_ptr)(void)) {
	if (NULL_PTR != a_ptr)
	{
		g_Int0Callback = a_ptr;
	}
}
void IU_ExternalInt1_setCallback(void (*a_ptr)(void)) {
	if (NULL_PTR != a_ptr)
	{
		g_Int1Callback = a_ptr;
	}
}
void IU_ExternalInt2_setCallback(void (*a_ptr)(void)) {
	if (NULL_PTR != a_ptr)
	{
		g_Int2Callback = a_ptr;
	}
}
