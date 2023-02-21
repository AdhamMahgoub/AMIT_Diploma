#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

//DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT)
void DIO_voidSetPinDirection (u8 PORTID, u8 PINID, u8 Direction)
{
	/*range check*/
	if((PORTID < 4) && (PINID < 8))
	{
		if (Direction == OUTPUT)
		{
			switch (PORTID)
			{	
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
			case PORTA	: 	CLR_BIT(DDRA_REG, PINID);		break; 
			case PORTB	: 	CLR_BIT(DDRB_REG, PINID);		break; 
			case PORTC	: 	CLR_BIT(DDRC_REG, PINID);		break; 
			case PORTD	: 	CLR_BIT(DDRD_REG, PINID);		break; 
			}
		}
	}
		
	else 
	{
			/*	return ERROR 	*/
	}
	
}


void DIO_voidSetPinValue (u8 PORTID, u8 PINID, u8 Value)
{
	/*range check*/
	if((PORTID < 4) && (PINID < 8))
	{
		if (Value == HIGH)
		{
			switch (PORTID)
			{	
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
			/*	return ERROR 	*/
	}
	
}


u8 DIO_u8GetPinValue (u8 PORTID, u8 PINID)
{
	u8 Local_u8Data = 0xFF; 
	
	/*range check*/
	if((PORTID < 4) && (PINID < 8))
	{

			switch (PORTID)
			{	
			case PORTA	:	Local_u8Data =  	GET_BIT(PINA_REG, PINID);		break; 
			case PORTB	:	Local_u8Data =  	GET_BIT(PINB_REG, PINID);		break; 
			case PORTC	:	Local_u8Data =  	GET_BIT(PINC_REG, PINID);		break; 
			case PORTD	:	Local_u8Data =  	GET_BIT(PIND_REG, PINID);		break; 
			}
		
	}		

	else 
	{
			/*	return ERROR 	*/
	}
	return Local_u8Data;
}