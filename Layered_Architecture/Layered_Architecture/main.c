#define F_CPU 8000000UL

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/Communication/UART/UART_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DIO/DIO_private.h"


int main(void)
{
	
	volatile int x = 3; 	
	
	DDRA_REG = 0x00; //Input
	PORTA_REG = 0x01; //Activate Pull Up Resistor

	DIO_voidSetPinDirection(PORTB,PIN0,OUTPUT);							
					
	while(1)
    {	
		if (GET_BIT(PINA_REG,0) == 0) // pressed
			DIO_voidSetPinValue(PORTB,PIN0,HIGH);			
		
		else 
			DIO_voidSetPinValue(PORTB,PIN0,LOW);
	}	
}