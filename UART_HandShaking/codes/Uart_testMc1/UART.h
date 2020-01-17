 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: sayed mohsen
 *
 *******************************************************************************/
#ifndef MCAL_USART_UART_H_
#define MCAL_USART_UART_H_


#include "std_types.h"
#include "micro_config.h"
#include "common_marcos.h"


/*
 * macros for UART Status
 */
#define UART_INITALIZED 1
#define UART_NOT_INITIALIZED 0


/*
 * Macros For UART HandShaking
 */

#define REQUEST_TO_SEND 0x09 /* When The DTE Device Has A Byte To Transmit */
#define CLEAR_TO_SEND   0x10 /* It Response TO (RTS) When Modem Has Room To Store Data*/


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*type definition for UART Data Frame */
typedef uint8  Uart_dataFrameType ;

/*type definition for UART Baud Rate */
typedef uint16 Uart_BaudRateType;

/* type definition for parity bit mode type*/
 typedef enum {
	no_parity,
	even_parity=2,
	Odd_pariy
}Uart_ParityBitModeType;

/*type definition for number of stop bits*/
typedef enum {
	One_Stop_Bit,
	Two_Stop_Bits
} Uart_StopBitsType;

/*type definition for data sampling edge*/
typedef enum {
	no_clock,
	Uart_Falling_Edge,
	Uart_Rissing_Edge,
} Uart_ClockPloarityType;

/*type definition for number of data bits in UART Frame*/
typedef enum {
	data_5,
	data_6,
	data_7,
	data_8,
	data_9=7,
}Uart_FrameLengthType;

/*type definition for UART transmission speed */
typedef enum {
	normal_transmission_speed,
	double_transmission_speed
}Uart_TransmissionSpeedType;

/*type definition for UART Transmission Mode*/
typedef enum{
	Asynchronous_operation,
	synchronous_operation,
}Uart_TransmissionModeType;

/*type definition for sending and receiving method*/
typedef enum{
	polling,
	interrupts,
}Uart_sendReceiveMode;


typedef struct {
	Uart_ParityBitModeType parity_mode;
	Uart_StopBitsType stop_bit ;
	Uart_ClockPloarityType clock;
	Uart_FrameLengthType datalength;
	Uart_TransmissionSpeedType speed;
	Uart_BaudRateType baudrate ;
	Uart_sendReceiveMode readwriteMode;
	Uart_TransmissionModeType transmissionMode ;
}Uart_ConfigChannel;

/**************************************************************************************
 * 							Function ProtoTypes
 * ************************************************************************************/
void Uart_init(const Uart_ConfigChannel *config_ptr) ;
void Uart_SendU8Data(uint8 data);
uint8 Uart_RecieveU8Data();
void Uart_SendString(uint8 *str);
void Uart_RecieveString(uint8 *str);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Uart_ConfigChannel UartConfigurations;

#endif /* MCAL_USART_UART_H_ */
