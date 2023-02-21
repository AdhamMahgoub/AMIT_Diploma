#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "LCD_interface.h"

#include "Timer_private.h"
#include "Timer_interface.h"


int main(void)
{
  
  
/*	Debugging using the LCD	*/
  	LCD_voidInit();
  	LCD_set_xy(0,0);
	LCD_print_string ("Adham");


  
	//	Timer Initialization 	//
	Timer_Counter_Init(); 
	

    while(1)
    {
        	//	Do Nothing 
			//	CPU will loop here till Interrupt occur 
			//	When Interrupt occur, it'll go to the ISR (in Timer_prog.c) then return here after executing ISR 
    }
}