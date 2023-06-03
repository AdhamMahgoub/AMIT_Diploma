#ifndef			SPI_PRIVATE_H
#define 		SPI_PRIVATE_H
	
#define 		SPCR		*((volatile u8 *)0x2D)
#define 		SPSR		*((volatile u8 *)0x2E)
#define 		SPDR		*((volatile u8 *)0x2F)
				
/*			SPCR Register			*/
#define SPIE_bit	7 
#define SPE_bit		6
#define	DORD_bit	5		
#define	MSTR_bit	4
#define	CPOL_bit	3
#define	CPHA_bit	2
#define	SPR1_bit	1
#define	SPR0_bit	0

/*			SPSR Register			*/
#define SPIF_bit	7
#define WCOL_bit	6
#define	SPI2X_bit	0		
		
						
/*			PINS on MC				*/
#define SS_bit		4
#define MOSI_bit	5
#define MISO_bit	6
#define SCK_bit		7
		  	 
#endif