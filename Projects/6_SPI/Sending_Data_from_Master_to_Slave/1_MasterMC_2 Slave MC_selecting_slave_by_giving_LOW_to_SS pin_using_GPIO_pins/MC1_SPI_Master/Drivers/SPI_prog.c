
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"

#define slave1 PIN0
#define slave2 PIN1

void	SPI_initMaster(void)
{
		//	Configure SPI Pins
		DIO_voidSetPinDirection(PORTB, SS_bit,		OUTPUT);	//	SS Pin Output
		DIO_voidSetPinDirection(PORTB, MOSI_bit,	OUTPUT);	//	MOSI Pin Output
		DIO_voidSetPinDirection(PORTB, MISO_bit,	INPUT);		//	MISO Pin Input
		DIO_voidSetPinDirection(PORTB, SCK_bit,		OUTPUT);	//	SCK Pin Output
		
		//SS Pins (2 Slaves)
		DIO_voidSetPinDirection(PORTD, 0,	OUTPUT);	//	SCK Pin Output
		DIO_voidSetPinDirection(PORTD, 1,	OUTPUT);	//	SCK Pin Output
		
		DIO_voidSetPinValue(PORTD, slave1, HIGH);
		DIO_voidSetPinValue(PORTD, slave2, HIGH);
		
		//SET_BIT(SREG,7);				//	Global Interrupt Enable
		//SET_BIT(SPCR, SPIE_bit);		//	SPI Interrupt Enable
		//SET_BIT(SPCR, DORD_bit);		//	Data Order
		//Set Clock rate to fso/4
		//CLR_BIT(SPCR, CPOL_bit);		//	Clock Polarity
		//CLR_BIT(SPCR, CPHA_bit);		//	Clock Phase
		//CLR_BIT(SPCR, SPR1_bit);		//	SPI Clock Rate Select
		//CLR_BIT(SPCR, SPR0_bit);		//	SPI Clock Rate Select


		//	Master Mode
		SET_BIT(SPCR, MSTR_bit);	//	Master/Slave Select	(THIS MUST BE BEFORE THE SPI ENABLE)
	
		//	Enable SPI
		SET_BIT(SPCR, SPE_bit);		//	SPI Enable
		
}

void	SPI_initSlave(void)
{
		//	Configure SPI Pins
		DIO_voidSetPinDirection(PORTB, SS_bit,		INPUT);		//	SS Pin INPUT
		DIO_voidSetPinDirection(PORTB, MOSI_bit,	INPUT);		//	MOSI Pin INPUT
		DIO_voidSetPinDirection(PORTB, MISO_bit,	OUTPUT);	//	MISO Pin OUTPUT
		DIO_voidSetPinDirection(PORTB, SCK_bit,		INPUT);		//	SCK Pin INPUT
				
				
		//SET_BIT(SREG,7);				//	Global Interrupt Enable
		//SET_BIT(SPCR, DORD_bit);		//	Data Order
		//SET_BIT(SPCR, SPIE_bit);		//	SPI Interrupt Enable	
		//	Set Clock rate to fso/4
		//CLR_BIT(SPCR, CPOL_bit);		//	Clock Polarity
		//CLR_BIT(SPCR, CPHA_bit);		//	Clock Phase
		//CLR_BIT(SPCR, SPR1_bit);		//	SPI Clock Rate Select
		//CLR_BIT(SPCR, SPR0_bit);		//	SPI Clock Rate Select		//	Master Mode		
		//CLR_BIT(SPCR, MSTR_bit);		//	Master/Slave Select
				
		//	Enable SPI
		SET_BIT(SPCR, SPE_bit);			//	SPI Enable

}

void	SPI_sendByte(u8 data)
{
		//	Send Data by SPI
		SPDR = data; 
		
		//	Wait until SPI Interrupt Flag = 1 (data sent correctly)
		while(GET_BIT(SPSR, SPIF_bit)==0);
}

u8		SPI_recieveByte(void)
{
		//	Wait until SPI Interrupt Flag = 1 (data received correctly)
		while(GET_BIT(SPSR, SPIF_bit)==0);
		
		// Return the Receive Byte from SPI data Register
		return(SPDR);
}
		
		
