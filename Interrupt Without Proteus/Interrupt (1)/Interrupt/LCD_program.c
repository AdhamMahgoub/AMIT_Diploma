#include "STD_TYPES.H"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"

#include <util/delay.h>


//need to include delay -- will be added in the main.c file 
//note that i didn't need to include the DIO_private.h -- because i didn't need it 

void LCD_voidInit(void)
{ 
	DIO_voidSetPortDirection(LCD_DATA_PORT, 0xFF); 		//all pins are OUTPUT (DATA_PORT)
	DIO_voidSetPortDirection(LCD_CONTROL_PORT, 0xFF); 	//all pins are OUTPUT (CONTROL_PORT)
	
	_delay_ms(40); 				/*	LCD Power ON delay always > 15ms	*/
	
	
												
	LCD_voidSendCMD (function_set);		    	//function set 					Initialization of 16x2 LCD in 8 bit mode 
	LCD_voidSendCMD (display_on_off_control);	//display on/off control      	Display ON Cursor OFF  
	LCD_voidSendCMD (entry_mode_set);		    //entry mode set              	Auto Increment Cursor 
	LCD_voidSendCMD (clear_display);		    //clear display              	Clear display  
	LCD_voidSendCMD (set_DDRAM_address);		//set DDRAM address         	Cursor at home position 
											
}

void LCD_voidSendCMD(u8 CMD)
{
	/*- Conditions to send cmd 
    1. RS 	= 0 
    2. RW 	= 0
    3. EN 	= pulse 
    4. DATA =  CMD
	*/
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS, LOW);		/*		1- RS = 0		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW, LOW);		/*		2- RW = 0		*/
	/*		3- EN pulse		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN, HIGH);
	/*		4- SEND CMD		*/
	DIO_voidSetPortValue(LCD_DATA_PORT, CMD);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN, LOW);
	_delay_ms(5);										
}

void LCD_voidWriteData(u8 Data)
{
	/*- Conditions to send cmd 
    1. RS 	= 1 
    2. RW 	= 0
    3. EN 	= pulse 
    4. DATA =  CMD
	*/
	

	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS, HIGH); 	/*		1- RS = 1		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW, LOW);		/*		2- RW = 0		*/
	/*		3- EN pulse		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN, HIGH);
	/*		4- SEND CMD		*/
	DIO_voidSetPortValue(LCD_DATA_PORT, Data);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN, LOW); 
	_delay_ms(5);										
}

void LCD_cursor_shift_right (void)
{
	LCD_voidSendCMD(cursor_shift_right);
}

void LCD_set_xy (u8 row, u8 column)
{	
	
	//shifting y (row -- horizontal) 
	if (row == 1)
		LCD_voidSendCMD(DDRAM_to_2nd_row); //sends the DDRAM to the 2nd row 

	
	//shifting x (column -- vertical)
	for (int i=0; i<column; i++)
	{
		LCD_cursor_shift_right();
	}
	
}


