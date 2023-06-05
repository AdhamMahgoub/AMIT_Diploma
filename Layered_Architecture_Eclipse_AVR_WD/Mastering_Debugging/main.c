#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/Timer/Timer_interface.h"
#include "MCAL/Timer/Timer_private.h"
#include "MCAL/Communication/UART/UART_interface.h"
#include "MCAL/DIO/DIO_interface.h"


#ifdef F_CPU
#undef F_CPU
#define F_CPU 8000000
#endif


char x = 0;

int main(void)
{
	Timer0_Counter_Init();
	DIO_voidSetPinDirection(PORTB, PIN3, OUTPUT); // OC0 pin


	UART_Init();

	while(1)
	{
		//TODO:: Please write your application code
	}
}
