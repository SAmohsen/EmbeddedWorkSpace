#include "main.h"

int main(void)
{

	LCD_Init(); /* initialize LCD driver */
	LCD_Clear(); /* clear LCD at the beginning */
	LCD_SendString("ADC Result = ");
	Adc_init(&Adc_configuration); /* initialize ADC driver */
	IU_ExternalInterruptEnable(&ExInterrupts_Configurations);/*initialize External Interrupts*/
	SREG  |= (1<<7); /* Enable interrupts by setting I-bit*/
	Adc_readChannel(Adc_channel3);
	while(1)
    {
    	LCD_goToXY(1,12);
    	LCD_sendu32Data(Adc_getAdcResult()); /* display the ADC value on LCD screen */
    }
}

