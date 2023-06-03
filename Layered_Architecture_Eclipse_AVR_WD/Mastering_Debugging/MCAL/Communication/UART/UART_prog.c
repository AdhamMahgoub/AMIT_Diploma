#include "../../../LIB/STD_TYPES.H"
#include "../../../LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_Init (void)
{
	//Enable RX and TX 
	SET_BIT(UCSRB,RXEN_bit);
	SET_BIT(UCSRB,TXEN_bit);

	SET_BIT(UCSRC, URSEL_bit);				//	Register Select UCSRC or UBRHH

	//Setting the Frame Format: 8 bits, no parity, one stop bits. 
	SET_BIT(UCSRC, UCSZ0_bit);				//	8 bits character
	SET_BIT(UCSRC, UCSZ1_bit);				//	8 bits character
			
	CLR_BIT(UCSRC, UPM0_bit);				//	No parity
	CLR_BIT(UCSRC, UPM1_bit);				//	No parity
	
	CLR_BIT(UCSRC, USBS_bit);				//	One stop bit

	CLR_BIT(UCSRC, UMSEL_bit);				//	Asynchronous
	
	//Setting the baud rate to 9600
	UBRRH = 0; 
	UBRRL = 103;							//	Filling the low byte (8 bits only) -- this means 9600 (from table)
}

void UART_SendByte (u8 Byte)
{
	/* Wait for empty transmit buffer */
	while ( (GET_BIT(UCSRA, UDRE_bit)) == 0 );
	
	/* Put data into buffer, sends the data */
	UDR = Byte;								//	Data is put into the UDR (Read)
}

u8 UART_RecieveByte (void)
{
	//Wait until the receive is complete  
	while (	GET_BIT(UCSRA,RXC_bit) == 0);	/* Wait till data is received (to the UDR)	*/
	//Return the received data 
	return(UDR);							/* Return the byte (3ashan el Data fel UDR)  */
}

void UART_send_string(const char *s)		//A function to Transmit String
{
	while (*s)
	UART_SendByte(*s++);
}

void UART_send_float(float x)			//A function to Transmit float
{
	char arr[10] = {0};
	sprintf(arr, "%.3f", x);
	UART_send_string(arr);
}
