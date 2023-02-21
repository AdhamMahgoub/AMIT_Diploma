#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include <util/delay.h>

int main(void)
{

    DIO_voidSetPinDirection (PORTA, PIN0, OUTPUT);
	DIO_voidSetPinDirection (PORTA, PIN1, OUTPUT);
    DIO_voidSetPinDirection (PORTA, PIN2, OUTPUT);

	
	while(1)
	{
		DIO_voidSetPinValue(PORTA, PIN0, HIGH); 
		_delay_ms(1000);
		
		DIO_voidSetPinValue(PORTA, PIN0, LOW); 
		_delay_ms(1000);
		
		DIO_voidSetPinValue(PORTA, PIN1, HIGH);
		_delay_ms(1000);
		
		DIO_voidSetPinValue(PORTA, PIN1, LOW);
		_delay_ms(1000);
		
		DIO_voidSetPinValue(PORTA, PIN2, HIGH);
		_delay_ms(1000);
		
		DIO_voidSetPinValue(PORTA, PIN2, LOW);
		_delay_ms(1000);
				
	}
}