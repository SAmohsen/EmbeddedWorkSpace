/*
 * port.c
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#include "port.h"
#include "port_REGS.h"

static uint8 port_status = PORT_NOT_INITIALIZED;
static const Port_ConfigChannel *configured_ports = NULL_PTR;



static Port_PortType get_portID(Port_PinType pin){
	Port_PortType port_id ;
	if ((pin >= PORT_A_START) && (pin <= PORT_A_FINISH))
	{
		port_id = PORTA_ID;
	}
	else if ((pin >= PORT_B_START) && (pin <= PORT_B_FINISH))
	{
		port_id = PORTB_ID;
	}
	else if ((pin >= PORT_C_START) && (pin <= PORT_C_FINISH))
	{
		port_id = PORTC_ID;
	}
	else if ((pin >= PORT_D_START) && (pin <= PORT_D_FINISH))
	{
		port_id = PORTD_ID;

	}
	else
	{

	}

	return port_id;
}


static Port_PinType get_pinID(Port_PinType pin){
	Port_PinType pin_id ;
	pin_id = (Port_PortType) pin% PINS_PER_PORT ;
	return pin_id;
}


void Port_Init(const Port_ConfigType *ConfigPtr) {
	Port_PortType *DDR_ptr;
	Port_PortType *port_ptr;

	Port_PortType local_port;
	Port_PinType local_pin;

	boolean error = FALSE;

	/*Error Checking */
	if (NULL_PTR == ConfigPtr)
	{
		/* report Null pointer error */
		error = TRUE;
	}
	else
	{
		/* no action required */
	}


	if (FALSE == error)
	{
		configured_ports = ConfigPtr->port_channels;

		for (uint8 itr = 0; itr < PORT_CONFIGURED_CHANNELS; itr++) {
			local_port = get_portID(configured_ports[itr].pin_num);
			switch (local_port)
			{

			case PORTA_ID:
				DDR_ptr  = &DDRA_REG;
				port_ptr = &PORTA_REG;
				break;

			case PORTB_ID:
				DDR_ptr = &DDRB_REG;
				port_ptr = &PORTB_REG;
				break;

			case PORTC_ID:
				DDR_ptr = &DDRC_REG;
				port_ptr = &PORTC_REG;
				break;

			case PORTD_ID:
				DDR_ptr = &DDRD_REG;
				port_ptr = &PORTD_REG;
				break;
			}
			local_pin  = get_pinID(configured_ports[itr].pin_num) ;

			if (PORT_PIN_OUT == configured_ports[itr].direction)
			{
				SET_BIT(*DDR_ptr,local_pin);

				if (initial_Low == configured_ports[itr].pin_out_mode)
				{
					CLR_BIT(*port_ptr,local_pin);

				}
				else if (initial_High == configured_ports[itr].direction)
				{
					SET_BIT(*port_ptr,local_pin);

				}
				else
				{

				}

			}
			else if (PORT_PIN_IN == configured_ports[itr].direction)
			{
				CLR_BIT(*DDR_ptr,local_pin);

				if (Disable_Pull_up == configured_ports[itr].pin_in_mode)
				{
					CLR_BIT(*port_ptr,local_pin);
				}
				else if (Enable_Pull_up== configured_ports[itr].pin_in_mode)
				{
					SET_BIT(*port_ptr,local_pin);

				}
				else
				{

				}

			}

			else
			{

			}

		}//end  loop

		port_status = PORT_INITIALIZED;
	}
	else
	{
		/* no action required */
	}

}


