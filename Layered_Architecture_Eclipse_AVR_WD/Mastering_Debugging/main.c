#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/Timer/Timer_interface.h"
#include "MCAL/Timer/Timer_private.h"
#include "MCAL/Communication/UART/UART_interface.h"
#include "MCAL/Communication/UART/UART_config.h".h"
#include "MCAL/DIO/DIO_interface.h"


#ifdef F_CPU
#undef F_CPU
#define F_CPU 8000000
#endif


#ifdef UART_Polling_Interrupt_Mode Interrupt 	/*		To Work using Interrupt 	*/
#include <avr/interrupt.h>
ISR(USART_RXC_vect)	// Receive Complete -- UART Receive ISR
{
	DIO_voidSetPinDirection(PORTA,PIN0, OUTPUT);
	DIO_voidSetPinValue(PORTA, PIN0, HIGH);
}





#endif

int main(void)
{
	UART_Init();

	while(1)
	{

	}
}
