/*
 * DC_Motor.h
 *
 *  Created on: Nov 11, 2019
 *      Author: sayed
 */

#ifndef HAL_MOTORS_DCMOTOR_H_
#define HAL_MOTORS_DCMOTOR_H_

#include "std_types.h"
#include "common_marcos.h"
#include "micro_config.h"

#include "DCMotor_cfg.h"

void DCMotor_Init();
void DCMotor_RotateClockwise();
void DCMotor_RotateAntiClockwise();
void DCMotor_Stop();

#endif /* HAL_MOTORS_DCMOTOR_H_ */
