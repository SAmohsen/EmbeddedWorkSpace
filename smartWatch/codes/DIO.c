/*
 * DIO.c
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#include "DIO.h"
#include "DIO_REGS.h"

static uint8 Dio_status = DIO_NOT_INITIALIZED;
static Dio_ConfigChannel *Dio_configuredChannels = NULL_PTR;



void Dio_Init(const Dio_ConfigType *ConfigPtr) {
	boolean error = FALSE  ;
	/*Error Checking */
	if (NULL_PTR == ConfigPtr)
	{
		/* report Null pointer error */
		error = TRUE ;
	}
	else
	{
		/* no action required */
	}

	if (FALSE == error)
	{
		Dio_configuredChannels = ConfigPtr->Dio_channels ;
		Dio_status = DIO_INITIALIZED ;
	}
	else
	{
		/* no action required */

	}

}



void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
	uint8 *port_ptr = NULL_PTR;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;

	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_CHANNELS <= ChannelId)
	{
		/*report error parameters*/
		error = TRUE;

	}
	else
	{

	}

	if (FALSE == error)
	{
		/*get port address address*/
		switch (Dio_configuredChannels[ChannelId].port_number)
		{
		case 0:port_ptr = &PORTA_REG;
		break;
		case 1:port_ptr = &PORTB_REG;
		break;
		case 2:port_ptr = &PORTC_REG;
		break;
		case 3:port_ptr = &PORTD_REG;
		break;
		}

		if (STD_LOW == Level)
		{
			CLR_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);
		}
		else if (STD_HIGH == Level)
		{
			SET_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);
		}
		else
		{

		}
	}
	else
	{

	}

}
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	uint8 *pin_ptr = NULL_PTR;
	Dio_LevelType ChannelLevel;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;
	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_CHANNELS <= ChannelId)
	{
		/*report error parameters*/
		error = TRUE;
	}
	else
	{

	}

	if (FALSE == error) {
		/*get port address address*/
		switch (Dio_configuredChannels[ChannelId].port_number) {
		case 0:pin_ptr = &PORTA_REG;
		break;
		case 1:pin_ptr = &PORTB_REG;
		break;
		case 2:pin_ptr = &PORTC_REG;
		break;
		case 3:pin_ptr = &PORTD_REG;
		break;
		}
		ChannelLevel = READ_BIT(*pin_ptr,Dio_configuredChannels[ChannelId].channel_number);
		return ChannelLevel;

	}
	else
	{

	}
}


