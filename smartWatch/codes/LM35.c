/*
 * LM35.c
 *
 *  Created on: Nov 20, 2019
 *      Author: sayed
 */
#include"Lm35.h"

uint16 LM35_ReadTemp()
{
	uint16 temp;
	float dig;
	//int dig;
	float volt;
	dig = Adc_readChannel(LM35_ADC_CHANNEL);
	//LCD_goToXY(2,1);
	//LCD_SendIntegerData(dig);
	volt = (dig * 5) / 1023;
	volt = (volt) / 10;
	temp = volt * 1000;
	return temp;
}
