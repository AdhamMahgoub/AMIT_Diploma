#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "LCD_interface.h"

#include "Timer_private.h"
#include "Timer_interface.h"


int main(void)
{
  
  	//	LCD Initialization		//
  	LCD_voidInit();

	//	Timer Initialization 	//
	Timer_Counter_Init(); 
	
	//	LED						//
	DIO_voidSetPinDirection(PORTA, 0, OUTPUT);

	//	OC0 Initialization		//
	DIO_voidSetPinDirection(PORTB, 3, OUTPUT);
	

    while(1)
    {
        	//	Do Nothing 
			//	CPU will loop here till Interrupt occur 
			//	When Interrupt occur, it'll go to the ISR (in Timer_prog.c) then return here after executing ISR 
    }
}