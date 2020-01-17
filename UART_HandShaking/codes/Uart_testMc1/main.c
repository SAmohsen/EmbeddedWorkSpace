#include "main.h"

int main(int argc, char **argv) {
	/* Create A Receive Buffer */
	uint8 rcv_Buffer [20] ;
	uint8 rcv_Byte;

	/*Initialize UART Driver */
	Uart_init(&UartConfigurations);

	/*Initialize LCD Driver*/
	LCD_Init();

	/*Receive A New Byte From DTE*/
	rcv_Byte = Uart_RecieveU8Data();

	/*Wait Until DTE is Ready To Transmit New Data*/
	while (REQUEST_TO_SEND != rcv_Byte)
	{
		rcv_Byte = Uart_RecieveU8Data();
	}

	/*
	 * Doing Some Operations
	 */

	/*Now DCE IS Ready To Receive Data*/
	Uart_SendU8Data(CLEAR_TO_SEND);

	/*Receive Data From UART*/
	Uart_RecieveString(rcv_Buffer);

	/*Print Received Buffer On LCD */
	LCD_SendString(rcv_Buffer);

	while (1);
}
