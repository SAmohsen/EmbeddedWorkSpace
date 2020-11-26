/*
 * Button.h
 *
 *  Created on: Feb 17, 2020
 *      Author: SAmohsen
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_


#include "../../std_types.h"
#include "../../common_marcos.h"
#include  "../../micro_config.h"
#include "../../MCAL/DIO/Dio.h"
#include "../../MCAL/PORT/port.h"

#include "button_cfg.h"


#define BUTTON_IS_PRESSED 1
#define BUTTON_IS_REALSED 0


void BUTTON_init();
void BUTTON_refreshState() ;
uint8 BUTTON_getState();
uint8 BUTTON_ReadState();

#endif /* HAL_BUTTON_BUTTON_H_ */
