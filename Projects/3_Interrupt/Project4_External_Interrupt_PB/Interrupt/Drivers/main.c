

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "DIO_private.h"

		  

void EXTI0_fun	(void)
{
	TOG_BIT(PORTA_REG, 0);
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
	DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT);
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}