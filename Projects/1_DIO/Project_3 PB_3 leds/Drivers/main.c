#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include <util/delay.h>

int main(void)
{

    DIO_voidSetPinDirection (PORTA, PIN0, OUTPUT);
	DIO_voidSetPinDirection (PORTA, PIN1, OUTPUT);
    DIO_voidSetPinDirection (PORTA, PIN2, OUTPUT);
	
	DIO_voidSetPinDirection (PORTB, PIN0, INPUT);
	DIO_voidSetPinDirection (PORTB, PIN1, INPUT);
	DIO_voidSetPinDirection (PORTB, PIN2, INPUT);


	
	while(1)
	{
		
		DIO_voidSetPinValue(PORTA, PIN0, DIO_u8GetPinValue(PORTB, PIN0)); 
		_delay_ms(3000);
		
		DIO_voidSetPinValue(PORTA, PIN0, LOW); 
		_delay_ms(3000);
		

		
		DIO_voidSetPinValue(PORTA, PIN1, DIO_u8GetPinValue(PORTB, PIN1));
		_delay_ms(3000);
		
		DIO_voidSetPinValue(PORTA, PIN1, LOW);
		_delay_ms(3000);
		
		
		DIO_voidSetPinValue(PORTA, PIN2, DIO_u8GetPinValue(PORTB, PIN2));
		_delay_ms(3000);
		
		DIO_voidSetPinValue(PORTA, PIN2, LOW);
		_delay_ms(3000);
				
	}
}