/*
 * LED.h
 *
 *  Created on: Sep 24, 2019
 *      Author: sayed
 */

#ifndef Lamp_Lamp_H_
#define Lamp_Lamp_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include  "../../micro_config.h"
#include "../../MCAL/DIO/Dio.h"
#include "../../MCAL/PORT/port.h"

#include "Lamp_cfg.h"

void Lamp_init(void);
void Lamp_on(void);
void Lamp_off(void);
uint8 Lamp_state(void);

#endif /* Lamp_Lamp_H_ */
