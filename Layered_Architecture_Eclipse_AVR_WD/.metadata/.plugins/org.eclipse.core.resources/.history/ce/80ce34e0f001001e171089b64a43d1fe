#define F_CPU 8000000UL

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/Communication/UART/UART_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DIO/DIO_private.h"

#ifdef F_CPU
#undef F_CPU
#define F_CPU 8000000
#endif

int main(void)
{

	UART_Init();
	UART_send_string("Hello");

}
