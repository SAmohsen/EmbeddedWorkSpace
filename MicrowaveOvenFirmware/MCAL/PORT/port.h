/*
 * port.h
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#ifndef PORT_H_
#define PORT_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include"../../micro_config.h"

typedef uint8 Port_PinType ;
typedef uint8 Port_PortType;


typedef enum{
	PORT_PIN_IN ,
	PORT_PIN_OUT
}Port_PinDirectionType;

typedef enum
{	PORT_PA,
	PORT_PB,
	PORT_PC,
	PORT_PD,
}Port_portType;

void PORT_setPinDirection(Port_PortType PortName, Port_PinType PinNum, Port_PinDirectionType PinDirection) ;
void PORT_setPortDirection(Port_PortType PortName, Port_PinType PinNum, Port_PinDirectionType PinDirection) ;
#endif /* PORT_H_ */
