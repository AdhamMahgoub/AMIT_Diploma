#ifndef				TIMER_PRIVATE_H
#define 			TIMER_PRIVATE_H

#define 			TCCR0				*(volatile u8*) 0x53
#define 			TCNT0				*(volatile u8*) 0x52
#define 			OCR0				*(volatile u8*) 0x5C
#define 			TIMSK				*(volatile u8*) 0x59
#define 			TIFR				*(volatile u8*) 0x58

/*					Bits in TCCR0		*/
#define 			BIT_CS00			0
#define 			BIT_CS01			1
#define 			BIT_CS02			2
#define 			BIT_WGM01			3
#define 			BIT_COM00			4
#define 			BIT_COM01			5
#define 			BIT_WGM00			6
#define 			BIT_FOC0			7

/*					Bits in TIMSK		*/
#define 			BIT_TOIE0			0		//	Timer/Counter0 Overflow Interrupt Enable
#define 			BIT_OCIE0			1		//	Timer/Counter0 Output Compare Match Interrupt Enable

/*					Bits in TIFR		*/
#define 			BIT_TOV0			0


#endif 
