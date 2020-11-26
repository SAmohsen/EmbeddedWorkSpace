/*
 * port.c
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#include "port.h"

#include "port_REGS.h"


void PORT_setPinDirection(Port_PortType PortName, Port_PinType PinNum, Port_PinDirectionType PinDirection) {
	uint8 *DDR_Ptr=NULL_PTR;
	switch (PortName) {
	case PORT_PA:DDR_Ptr = &DIO_PORT1_DIRECTION;
	break;
	case PORT_PB:DDR_Ptr = &DIO_PORT2_DIRECTION;
	break;
	case PORT_PC :DDR_Ptr = &DIO_PORT3_DIRECTION;
	break;
	case PORT_PD :DDR_Ptr = &DIO_PORT4_DIRECTION;
	break;
	}
	if (PinDirection == PORT_PIN_IN)
	{
		CLR_BIT(*DDR_Ptr, PinNum);
	}
	else if (PinDirection == PORT_PIN_OUT)
	{
		SET_BIT(*DDR_Ptr, PinNum);
	}
	else
	{

	}
}


void PORT_setPortDirection(Port_PortType PortName, Port_PinType PinNum, Port_PinDirectionType PinDirection) {
	uint8 *DDR_Ptr;
	switch (PortName) {
	case PORT_PA:DDR_Ptr = &DIO_PORT1_DIRECTION;
	break;
	case PORT_PB:DDR_Ptr = &DIO_PORT2_DIRECTION;
	break;
	case PORT_PC:DDR_Ptr = &DIO_PORT3_DIRECTION;
	break;
	case PORT_PD:DDR_Ptr = &DIO_PORT4_DIRECTION;
	break;
	}
	if (PinDirection == PORT_PIN_IN)
	{
		*DDR_Ptr = 0x00;
	}
	else if (PinDirection == PORT_PIN_OUT)
	{
		*DDR_Ptr = 0xFF;
	}
	else
	{

	}
}


