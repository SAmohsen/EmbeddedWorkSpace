/*
 * signalMeasurments.c
 *
 *  Created on: Jan 5, 2020
 *      Author: sayed
 */
#include "signalmeasurents.h"
static volatile uint16 hightime=0;
static volatile uint16 period=0;
static volatile uint16 periodplushigh=0;
static volatile uint8 numberOfEdges =0;
static volatile uint8 measurmentFlag =0;
static void newMeasurment() {
	hightime = 0;
	period = 0;
	periodplushigh = 0;
	numberOfEdges = 0;
	measurmentFlag = 0;
}
static void getsignalMeasurments(void) {
	numberOfEdges++ ;
	if(numberOfEdges==1)
	{
	TCNT1 = 0 ; /*clear timer value*/
	ICR1=0 ;
	Icu_SetEdgeDetection(ICu_FALLING_EDGE) ; /*waiting for falling edge*/
	}
	else if (numberOfEdges==2){
		hightime = Icu_getInputCaptureValue();/*get signal high time*/
		Icu_SetEdgeDetection(Icu_RISING_EDGE);/*waiting for rising edge*/
	}
	else if (numberOfEdges==3){
		period = Icu_getInputCaptureValue();/*get signal total period*/
		Icu_SetEdgeDetection(ICu_FALLING_EDGE) ; /*waiting for falling edge*/
	}
	else if (numberOfEdges==4)
	{
	periodplushigh=	Icu_getInputCaptureValue();
	Icu_SetEdgeDetection(Icu_RISING_EDGE);/*waiting for rising edge*/
	Icu_clearTimeValue();/*clear ICU for new measureMents*/
	measurmentFlag=1;
	}
	else
	{
	/*no Action required*/
	}
}
uint32 calculateSignalDutyCycle() {
	uint32 dutycycle = ((float) (periodplushigh - period)/ (periodplushigh - hightime)) * 100;
	return dutycycle;
}
uint32 claculateSignalFrequency() {
	uint32 frequency = ((1000000) / (periodplushigh - hightime));
	return frequency;
}
uint32 calculateSignalPeriodtime() {
	uint32 signalperiod = periodplushigh - hightime;
	return signalperiod;
}
void captureInputSignal() {
	newMeasurment();
	Icu_SetCallback(getsignalMeasurments);
	Icu_Init(&ICu_configurations);/*initialize ICU driver */
	while (!measurmentFlag);/*wait until capturing input signal measurements*/
	Icu_Deinit();
}
