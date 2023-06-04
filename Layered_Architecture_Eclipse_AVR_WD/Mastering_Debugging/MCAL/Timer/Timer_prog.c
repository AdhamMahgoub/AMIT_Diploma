#include "../../LIB/STD_TYPES.H"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/LCD/LCD_interface.h"

#include "Timer_private.h"
#include "Timer_config.h"

#include <avr/interrupt.h>		//	Built-in Interrupt Library

u32 ISR_Counter	= 0;
u32 time_counter = 0;

ISR (TIMER0_OVF_vect)				
{
	// Action when TIMER0 Overflow Occur
	// do nothing 
}

void Timer0_Counter_Init(void)
{
	// Set global interrupt enable bit
	SET_BIT(SREG,7);

	OCR0 = Duty_cycle * 256;



	/* ##########Configure the timer modes (Normal, PWM, ...)########## */

	/*		Normal Mode 	*/
#if TIMER_MODE == NORMAL
	{
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	}
#endif

	/*		CTC	Mode		*/
#if (TIMER_MODE == CTC)
	{
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	}
#endif

	/*		Fast PWM		*/
#if (TIMER_MODE == FAST_PWM)
	{
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	}
#endif

	/*		Phase_Correct	*/
#if (TIMER_MODE == PHASE_CORRECT)
	{
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	}
#endif


	/* ##########Configure the Compare Match########## */

	// Configure the Compare Match (Non-PWM)
#if TIMER_MODE == NORMAL || TIMER_MODE == CTC

	/*	Options
	 * 		OC0_DISCONNECTED
	 * 		TOGGLE_OC0 (for NON-PWM only)
	 * 		CLEAR_OC0
	 * 		SET_OC0
	 */

	/*		0C0 Disconnected 	*/
	if (COMPARE_OUTPUT_MODE == OC0_DISCONNECTED)
	{
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}

	/*		Toggle_OC0 			*/
	else if (COMPARE_OUTPUT_MODE == TOGGLE_OC0)
	{
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}

	/*		Clear_OC0		 	*/
	else if (COMPARE_OUTPUT_MODE == CLEAR_OC0)
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

	/*		Set 0C0  			*/
	else if (COMPARE_OUTPUT_MODE == SET_OC0)
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
#endif


#if TIMER_MODE == FAST_PWM || TIMER_MODE == PHASE_CORRECT

	//configure the compare match (PWM)
	/*	Options
	 * 		OC0_DISCONNECTED
	 * 		CLEAR_OC0
	 * 		SET_OC0
	 */

	/*		0C0 Disconnected 			*/
	else if (COMPARE_OUTPUT_MODE == OC0_DISCONNECTED)
	{
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}

	/*		Clear_OC0		 	*/
	else if (COMPARE_OUTPUT_MODE == CLEAR_OC0)
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

	/*		Set 0C0  			*/
	else if (COMPARE_OUTPUT_MODE == SET_OC0)
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
#endif


	/* ##########Configure the CLK Select########## */

	// Configure the CLK Select 		*/
	/*	Falling Edge			*/
	if (TIMER_CLK_SELECT == FALLING_EDGE)
	{
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

	/*	Rising Edge				*/
	else if (TIMER_CLK_SELECT == RISING_EDGE)
	{
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

	/*	No Prescaler 			*/
	else if (TIMER_CLK_SELECT == NO_PRESCALER)
	{
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

	/* 	Prescaler 8			*/
	else if (TIMER_CLK_SELECT == PRESCALER_8)
	{
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

	/* 	Prescaler 64			*/
	else if (TIMER_CLK_SELECT == PRESCALER_64)
	{
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

	/* 	Prescaler 256			*/
	else if (TIMER_CLK_SELECT == PRESCALER_256)
	{
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

	/* 	Prescaler 1024			*/
	else if (TIMER_CLK_SELECT == PRESCALER_1024)
	{
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

	//enable overflow interrupt
	SET_BIT(TIMSK,BIT_TOIE0);
}



