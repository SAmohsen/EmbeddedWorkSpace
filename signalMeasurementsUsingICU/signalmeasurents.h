/*
 * signalmeasurents.h
 *
 *  Created on: Jan 5, 2020
 *      Author: sayed
 */

#ifndef SIGNALMEASURENTS_H_
#define SIGNALMEASURENTS_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_marcos.h"
#include "ICU.h"

uint32 calculateSignalDutyCycle() ;
uint32 claculateSignalFrequency() ;
uint32 calculateSignalPeriodtime() ;
void captureInputSignal() ;

#endif /* SIGNALMEASURENTS_H_ */
