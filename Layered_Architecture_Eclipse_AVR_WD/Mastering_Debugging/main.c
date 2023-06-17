#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/Timer/Timer_interface.h"
#include "MCAL/Timer/Timer_private.h"
#include "MCAL/Communication/UART/UART_interface.h"
#include "MCAL/Communication/UART/UART_config.h"
#include "MCAL/DIO/DIO_interface.h"

#ifdef F_CPU
#undef F_CPU
#define F_CPU 8000000
#endif






int main(void)
{
	UART_Init();
	UART_SendByte('1');

	while(1)
	{
	}
}
