/*
 * interrupts.h
 *
 *  Created on: Nov 13, 2019
 *      Author: sayed
 */

#ifndef MCAL_INTERRUPTS_INTERRUPTS_H_
#define MCAL_INTERRUPTS_INTERRUPTS_H_


#include "../../std_types.h"
#include "../../micro_config.h"
#include "../../common_marcos.h"


#define G_Interrupt_Enable_bit 7
#define EINTERRUPTS_CHANNELS 3
#define INT2_pin    5
#define INT0_pin  6
#define INT1_pin  7

typedef enum{
	low,
	logicalChange,
	FallingEdge,
	RisingEdge
}Interrupt_Sense_Control;

typedef enum{
	E_INT0 ,
	E_INT1,
	E_INT2
}interrupt_pin;

typedef struct {
	interrupt_pin interrupt_pin;
	Interrupt_Sense_Control mode ;
}externalInterruptConfigChannel;



void IU_GlobalInterruptEnable(void);
void IU_GlobalInterruptDisable(void);
void IU_ExternalInterruptEnable(externalInterruptConfigChannel *Config_ptr);
void IU_ExternalInt0_setCallback(void (*a_ptr)(void))  ;
void IU_ExternalInt1_setCallback(void (*a_ptr)(void)) ;
void IU_ExternalInt2_setCallback(void (*a_ptr)(void)) ;

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const externalInterruptConfigChannel ExInterrupts_Configurations;

#endif /* MCAL_INTERRUPTS_INTERRUPTS_H_ */
