#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/DIO/DIO_interface.h"

#ifdef F_CPU
#undef F_CPU
#define F_CPU 8000000
#endif

void EXTI0_fun	(void)
{
	DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT);	//	D2 is Input
	DIO_voidToggleBit(PORTA,PIN0);
}

void EXTI1_fun 	(void)
{
	DIO_voidToggleBit(PORTA,PIN1);
}

int main(void)
{

	/*	######################## Initialization part EXTI0	########################	*/

	DIO_voidSetPinDirection(PORTD, PIN2, INPUT);	//	D2 is Input
	DIO_voidSetPinValue(PORTD, PIN2, HIGH);			//	D2 is Pull-Up Pin

	/*	Call Back	*/
	EXTI0_SetCallBack_ptr2func(EXTI0_fun);

	/*	EXTI0 Init							*/
	EXTI0_voidInit();

	/*	Enable EXTI0						*/
	EXTI0_voidEnableInterrupt();

	/*	GIE Enable							*/
	GIE_voidInterruptEnable();

	/*	SET LED Pin Direction				*/
	DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT);


	/*	######################## Initialization part EXTI1	########################	*/

	DIO_voidSetPinDirection(PORTD, PIN3, INPUT);	//	D2 is Input
	DIO_voidSetPinValue(PORTD, PIN3, HIGH);			//	D2 is Pull-Up Pin

	/*	Call Back	*/
	EXTI1_SetCallBack_ptr2func(EXTI1_fun);

	/*	EXTI0 Init							*/
	EXTI1_voidInit();

	/*	Enable EXTI0						*/
	EXTI1_voidEnableInterrupt();

	/*	GIE Enable							*/
	GIE_voidInterruptEnable();

	/*	SET LED Pin Direction				*/
	DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT);



	while(1)
	{
		//TODO:: Please write your application code
	}
}
