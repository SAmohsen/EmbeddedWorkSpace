/*
 * squarewavegenrator.c
 *
 *  Created on: Dec 13, 2019
 *      Author: sayed
 */
#include"squarewavegenrator.h"
static uint16 genratedfreq = 0;
static void displayFreq() {
	LCD_goToXY(1, 1);
	LCD_SendString("FREQ : ");
	LCD_SendIntegerData(genratedfreq);
	LCD_SendString(" KHZ");
	LCD_goToXY(2, 1);
	LCD_SendString("OCR value : ");
	LCD_SendIntegerData(OCR0);
}
static void update_freq() {
	/*
	 * FREQ generated = F_cpu / 2*N(1+OCR0)
	 */
	genratedfreq = (F_CPU) / (2U * (1 + OCR0));
	// maxfreq at ocr = 0 ;/*TODO : handle overflow cases*/
	// mini att ocr =255 ;
}
void setup() {
	LCD_Init();
	timer0_squareWaveCTCInit();
	enable_globalInterrupts();
	Int0_Init();
	Int1_Init();

	//update_freq();
	//displayFreq();
}
void loop() {
	update_freq();
	displayFreq();
}
