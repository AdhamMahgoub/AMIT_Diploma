

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include <util/delay.h>


void EXTI0_fun	(void)
{
	DIO_voidSetPinValue(PORTC, PIN2, HIGH);
	_delay_ms(1000);
	DIO_voidSetPinValue(PORTC, PIN2, LOW);

}


int main(void)
{
		
	/* 	Initialization part					*/
	/*	D2 is Input and Pull-Up Pin			*/
	DIO_voidSetPinDirection(PORTD, PIN2, INPUT);
	DIO_voidSetPinValue(PORTD, PIN2, HIGH);
	
	/*	Call Back	*/
	EXTI0_SetCallBack(EXTI0_fun);
	
	/*	EXTI0 Init							*/
	EXTI0_voidInit();	
	/*	Enable EXTI0						*/
	EXTI0_voidEnableInterrupt(); 	
	/*	GIE Enable							*/
	GIE_voidInterruptEnable(); 	
		
	
	
	/*	SET LED Pin Direction				*/
	DIO_voidSetPinDirection(PORTC, PIN2, OUTPUT);
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}