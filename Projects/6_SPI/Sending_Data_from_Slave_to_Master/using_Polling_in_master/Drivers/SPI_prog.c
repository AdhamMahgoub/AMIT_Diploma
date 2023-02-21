#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "EXTI_private.h"	//	For Global Interrupt Enable


void	SPI_initMaster(void)
{
	//	Configure SPI Pins
	DIO_voidSetPinDirection(PORTB, SS_bit,		OUTPUT);	//	SS Pin Output
	DIO_voidSetPinDirection(PORTB, MOSI_bit,	OUTPUT);	//	MOSI Pin Output
	DIO_voidSetPinDirection(PORTB, MISO_bit,	INPUT);		//	MISO Pin Input
	DIO_voidSetPinDirection(PORTB, SCK_bit,		OUTPUT);	//	SCK Pin Output

	//	Master Mode
	SET_BIT(SPCR, MSTR_bit);	//	Master/Slave Select	(THIS MUST BE BEFORE THE SPI ENABLE)
	
	//	Enable SPI
	SET_BIT(SPCR, SPE_bit);		//	SPI Enable
	
	//	Global Interrupt Enable
	SET_BIT(SREG, 7);
	
	// 	SPI Interrupt Enable
	SET_BIT(SPCR, SPIE_bit);

	/*			The Pins that are not written are Zeroes		*/
	
}

void	SPI_initSlave(void)
{
	//	Configure SPI Pins
	DIO_voidSetPinDirection(PORTB, SS_bit,		INPUT);		//	SS Pin INPUT
	DIO_voidSetPinDirection(PORTB, MOSI_bit,	INPUT);		//	MOSI Pin INPUT
	DIO_voidSetPinDirection(PORTB, MISO_bit,	OUTPUT);	//	MISO Pin OUTPUT
	DIO_voidSetPinDirection(PORTB, SCK_bit,		INPUT);		//	SCK Pin INPUT

	//	Enable SPI
	SET_BIT(SPCR, SPE_bit);			//	SPI Enable
	
	
	//	Global Interrupt Enable
	SET_BIT(SREG, 7);
	
	// 	SPI Interrupt Enable
	SET_BIT(SPCR, SPIE_bit);
	
	/*			The Pins that are not written are Zeroes		*/
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


