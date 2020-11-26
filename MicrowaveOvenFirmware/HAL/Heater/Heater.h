/*
 * LED.h
 *
 *  Created on: Sep 24, 2019
 *      Author: sayed
 */

#ifndef Heater_Heater_H_
#define Heater_Heater_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include  "../../micro_config.h"
#include "../../MCAL/DIO/Dio.h"
#include "../../MCAL/PORT/port.h"
#include "Heater_cfg.h"


void Heater_init(void);
void Heater_on(void);
void Heater_off(void);
uint8 Heater_State(void);

#endif /* Heater_Heater_H_ */
