 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.c
 *
 * Description: Source file for the UART AVR driver
 *
 * Author: sayed mohsen
 *
 *******************************************************************************/

#include "UART.h"



/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

static uint8 Uart_status = UART_NOT_INITIALIZED ;/*static global variable for UART status */
static const  Uart_ConfigChannel *uart_configChannel = NULL_PTR ;/*static global variable for UART Configurations*/
static volatile Uart_dataFrameType uart_data=0 ;/*global variable to hold UART data Frame */



/*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/
ISR(USART_TXC_vect){

}
ISR(USART_RXC_vect){
	uart_data = UDR;
}


/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
void Uart_init(const Uart_ConfigChannel *config_ptr)
{
	uint16 desired_baudRate;/*variable to set baud rate in UBBR register */
	if (config_ptr != NULL_PTR)
	{
		uart_configChannel = config_ptr ;
		SET_BIT(UCSRC, URSEL);/*Writing in USRC Register */
		UCSRC = (UCSRC & 0xBF) | ((config_ptr->transmissionMode) << 6);/*select USART Transmission Mode (synchronous/Asynchronous)*/
		UCSRC = (UCSRC & 0xE7) | ((config_ptr->parity_mode & 0x03) << 4);/*select Type Of Parity Bits (disable / odd parity /even parity)*/
		UCSRC = (UCSRC & 0xFB) | (config_ptr->stop_bit << 3);/*select number of stop bits (one / two) stop bits*/

		switch (config_ptr->datalength)/*select number of data bits  in yoour frame */
		{
		case data_5:/*5-bits data*/
			CLR_BIT(UCSRC, UCSZ0);
			CLR_BIT(UCSRC, UCSZ1);
			CLR_BIT(UCSRB, UCSZ2);
			break;
		case data_6:/*6-bits data*/
			SET_BIT(UCSRC, UCSZ0);
			CLR_BIT(UCSRC, UCSZ1);
			CLR_BIT(UCSRB, UCSZ2);
			break;
		case data_7:/*7-bits data*/
			CLR_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			CLR_BIT(UCSRB, UCSZ2);
			break;
		case data_8:/*8-bits data*/
			SET_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			CLR_BIT(UCSRB, UCSZ2);
			break;
		case data_9:/*9-bits data*/
			SET_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			SET_BIT(UCSRB, UCSZ2);
			break;
		}
		/*setting BaudRate by calculating value to be loaded into UBBR register */
		if (normal_transmission_speed == config_ptr->speed)
		{
			CLR_BIT(UCSRA, U2X);/*normal transmission speed*/
			desired_baudRate = (((F_CPU) / (16UL * config_ptr->baudrate)) - 1);

		} else if (double_transmission_speed == config_ptr->speed)
		{
			SET_BIT(UCSRA, U2X);/*double transmission speed*/
			desired_baudRate = (((F_CPU) / (8UL * config_ptr->baudrate)) - 1);
		}
		else
		{
			/*no Action Required */

		}

		if (config_ptr->readwriteMode == interrupts)
		{
			SET_BIT(UCSRB,RXCIE); /*receive interrupt Enable*/
			SET_BIT(UCSRB, TXCIE);/*transmit interrupt enable*/
		}
		/*set desired BaudRate in UBRR register*/
		UBRRH = desired_baudRate >> 8;
		UBRRL = desired_baudRate;

		/*transmitter Enable */
		SET_BIT(UCSRB, TXEN);
		/*Receiver Enable */
		SET_BIT(UCSRB, RXEN);

		/*update UART Status*/
		Uart_status = UART_INITALIZED;

	}
}

/*
 * Function To Send  UART Byte
 */
void Uart_SendU8Data(uint8 data)
{
	if (uart_configChannel->readwriteMode == polling)
	{
		UDR = data;/*Send Data From UART*/
		while (BIT_IS_CLEAR(UCSRA, TXC));/*Wait until the transmission is complete TXC = 1*/
		SET_BIT(UCSRA, TXC);/*clear flag by writing one in it */
	}
	else if (uart_configChannel->readwriteMode == interrupts)
	{
		UDR = data;/*Initiate Send Request */
	}
	else{
		/*no Action Required */
	}

}

/*
 * Function To Receive UART Byte
 */

Uart_dataFrameType Uart_RecieveU8Data()
{
	Uart_dataFrameType data = 0xFF;/*dummy data*/
	if (uart_configChannel->readwriteMode == polling)
	{
		while (BIT_IS_CLEAR(UCSRA, RXC));/*wait until receive complete */
		data =  UDR;/* read Data From UART*/
	}
	return data ;
}


/*
 * Function To Return UART global Data
 */

Uart_dataFrameType Uart_getU8data()
{
	return uart_data ;
}

/*
 * Function To Send String
 */

void Uart_SendString(uint8 *str)
{
	uint8 itr = 0;
	while (str[itr] != '\0')
	{
		Uart_SendU8Data(str[itr]);
		itr++;
	}
}

/*
 * Function To receive String
 */
void Uart_RecieveString(uint8 *str)
{
	uint8 itr = 0;
	str[itr]=Uart_RecieveU8Data();
	while (str[itr] != '#')/*special End Character */
	{
		itr++;
		str[itr] = Uart_RecieveU8Data();
	}
	str[itr] = '\0';/*Terminate String */
}



