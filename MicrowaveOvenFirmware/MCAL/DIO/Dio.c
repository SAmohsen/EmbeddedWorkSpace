/*
 * Dioo.c
 *
 *  Created on: Feb 16, 2020
 *      Author: SAmohsen
 */


#include "Dio.h"

#include "Dio_Regs.h"


void Dio_writePortValue(Dio_portType PortName, Dio_portLevelType portLevel) {
	 uint8 *port_Ptr = NULL_PTR;
	switch (PortName) {
	case Dio_PA:port_Ptr = &DIO_OUTPUT_PORT1;
	break;
	case Dio_PB:port_Ptr = &DIO_OUTPUT_PORT2;
	break;
	case Dio_PC:port_Ptr = &DIO_OUTPUT_PORT3;
	break;
	case Dio_PD:port_Ptr = &DIO_OUTPUT_PORT4;
	break;
	}
	*port_Ptr=portLevel;
}


Dio_portLevelType Dio_readPortValue(Dio_portType PortName) {
	uint8 * pin_Ptr ;
	Dio_portLevelType portLevel;
	switch (PortName) {
	case Dio_PA:pin_Ptr = &DIO_INPUT_PORT1;
	break;
	case Dio_PB:pin_Ptr = &DIO_INPUT_PORT2;
	break;
	case Dio_PC:pin_Ptr = &DIO_INPUT_PORT3;
	break;
	case Dio_PD:pin_Ptr = &DIO_INPUT_PORT4;
	break;
	}
	portLevel = *pin_Ptr;
	return portLevel;
}

void Dio_writePinValue(Dio_portType PortName , Dio_pinType PinNum ,Dio_pinLevelType  PinLevel){
	uint8 *port_Ptr = NULL_PTR;
	switch (PortName)
	{
	case Dio_PA : port_Ptr = &DIO_OUTPUT_PORT1 ;
	break;
	case Dio_PB : port_Ptr = &DIO_OUTPUT_PORT2 ;
	break;
	case Dio_PC : port_Ptr = &DIO_OUTPUT_PORT3 ;
	break;
	case Dio_PD : port_Ptr = &DIO_OUTPUT_PORT4 ;
	break;
	}
	if (STD_LOW==PinLevel)
	{
		CLR_BIT(*port_Ptr,PinNum);
	}
	else if (STD_HIGH==PinLevel)
	{
		SET_BIT(*port_Ptr,PinNum);
	}
	else
	{
		/* no Action Required*/
	}

}

Dio_pinLevelType Dio_readPinValue(Dio_portType PortName , Dio_pinType PinNum){
	uint8 *pin_ptr = NULL_PTR;
	Dio_pinLevelType  PinLevel;
	switch (PortName) {
	case Dio_PA:pin_ptr = &DIO_INPUT_PORT1;
	break;
	case Dio_PB:pin_ptr = &DIO_INPUT_PORT2;
	break;
	case Dio_PC:pin_ptr = &DIO_INPUT_PORT3;
	break;
	case Dio_PD:pin_ptr = &DIO_INPUT_PORT4;
	break;
	}
	PinLevel = READ_BIT(*pin_ptr, PinNum);
	return PinLevel;
}

