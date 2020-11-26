/*
 * Dio.h
 *
 *  Created on: Feb 16, 2020
 *      Author: SAmohsen
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include "../../micro_config.h"


typedef enum
{	Dio_PA,
	Dio_PB,
	Dio_PC,
	Dio_PD,
}Dio_portType;

typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
}Dio_pinType;

typedef uint8 Dio_portLevelType;
typedef uint8 Dio_pinLevelType;

void Dio_writePortValue(Dio_portType PortName, Dio_portLevelType portLevel) ;
Dio_portLevelType Dio_readPortValue(Dio_portType PortName) ;
void Dio_writePinValue(Dio_portType PortName , Dio_pinType PinNum ,Dio_pinLevelType  PinLevel);
Dio_pinLevelType Dio_readPinValue(Dio_portType PortName , Dio_pinType PinNum);


#endif /* MCAL_DIO_DIO_H_ */
