#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

/*			example: DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT)	*/
void DIO_voidSetPinDirection (u8 PORTID, u8 PINID, u8 Direction)
{
	/*		Range Check			*/
	if((PORTID < 4) && (PINID < 8))
	{
		if (Direction == OUTPUT)
		{
			switch (PORTID)
			{	
			//SET 	= 	means set bit to 1 
			case PORTA	: 	SET_BIT(DDRA_REG, PINID);		break; 
			case PORTB	: 	SET_BIT(DDRB_REG, PINID);		break; 
			case PORTC	: 	SET_BIT(DDRC_REG, PINID);		break; 
			case PORTD	: 	SET_BIT(DDRD_REG, PINID);		break; 
			}
		}
			
	
		else if (Direction == INPUT) 
		{
			switch (PORTID)
			{	
			//CLEAR 	= 	means set bit to 0 
			case PORTA	: 	CLR_BIT(DDRA_REG, PINID);		break; 
			case PORTB	: 	CLR_BIT(DDRB_REG, PINID);		break; 
			case PORTC	: 	CLR_BIT(DDRC_REG, PINID);		break; 
			case PORTD	: 	CLR_BIT(DDRD_REG, PINID);		break; 
			}
		}
	}
		
	else 
	{
			/*	Return ERROR 	*/
	}
	
}


/*			example: DIO_voidSetPinValue(PORTA, PIN0, HIGH)			*/
void DIO_voidSetPinValue (u8 PORTID, u8 PINID, u8 value)
{
	/*		Range Check			*/
	if((PORTID < 4) && (PINID < 8))
	{
		if (Value == HIGH)
		{
			switch (PORTID)
			{	
			//PORT REGISTER is responsible for output
			case PORTA	: 	SET_BIT(PORTA_REG, PINID);		break; 
			case PORTB	: 	SET_BIT(PORTB_REG, PINID);		break; 
			case PORTC	: 	SET_BIT(PORTC_REG, PINID);		break; 
			case PORTD	: 	SET_BIT(PORTD_REG, PINID);		break; 
			}
		}
			
		else if (Value == LOW) 
		{
			switch (PORTID)
			{	
			case PORTA	: 	CLR_BIT(PORTA_REG, PINID);		break; 
			case PORTB	: 	CLR_BIT(PORTB_REG, PINID);		break; 
			case PORTC	: 	CLR_BIT(PORTC_REG, PINID);		break; 
			case PORTD	: 	CLR_BIT(PORTD_REG, PINID);		break; 
			}
		}
	}
	else 
	{
			/*	Return ERROR 	*/
	}
	
}


/*			example: DIO_u8GetPinValue(PORTA, PIN0)					*/
u8 DIO_u8GetPinValue (u8 PORTID, u8 PINID)
{
	u8 Local_u8Data = 0xFF; 
	
	/*		Range Check			*/
	if((PORTID < 4) && (PINID < 8))
	{

			switch (PORTID)
			{
			//PIN REGISTER is responsible for input
			case PORTA	:	Local_u8Data =  	GET_BIT(PINA_REG, PINID);		break; 
			case PORTB	:	Local_u8Data =  	GET_BIT(PINB_REG, PINID);		break; 
			case PORTC	:	Local_u8Data =  	GET_BIT(PINC_REG, PINID);		break; 
			case PORTD	:	Local_u8Data =  	GET_BIT(PIND_REG, PINID);		break; 
			}
		
	}		

	else 
	{
			/*	Return ERROR 	*/
	}
	return Local_u8Data;
}


void DIO_SetPortValue(u8 PORTID, u8 Value)
{
	
	/*		Range Check			*/
	if (PORTID < 4)
	{
		switch (PORTID)
			{	
			//SET 	= 	means set bit to 1 
			case PORTA	: 	PORTA_REG = Value;		break; 
			case PORTB	: 	PORTB_REG = Value;		break; 
			case PORTC	: 	PORTC_REG = Value;		break; 
			case PORTD	: 	PORTD_REG = Value;		break; 
			}
	}
	
	else 
	{
		//Return ERROR
	}
	
	
}
