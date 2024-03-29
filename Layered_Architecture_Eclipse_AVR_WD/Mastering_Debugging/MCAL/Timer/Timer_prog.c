#include "../../LIB/STD_TYPES.H"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/LCD/LCD_interface.h"

#include "Timer_private.h"
#include "Timer_config.h"

#include <avr/interrupt.h>		//	Built-in Interrupt Library

/*
ISR (TIMER0_OVF_vect)				
{
	// Action when TIMER0 Overflow Occur
	// We can use the timer as (counter || timer)

	if (COUNTER_or_TIMER == TIMER)
	{
		// Do the Following
		// ISR Code
	}

	if (COUNTER_or_TIMER == COUNTER)
	{
		// Set TCNT0 to 254 when ISR occur
		// Counts Twice then achieves ISR again
		// Make sure that the following is chosen: (easiest to work with)
		// TIMER_MODE == NORMAL
		// TIMER_CLK_SELECT is falling_edge or rising_edge (of a push button on T0 pin)
		TCNT0 = 254; // Assuming TIMER_MODE == NORMAL // if CTC, we need to adjust value
	}
}
 */

void Timer0_Counter_Init(void)
{
	/*	Steps
	 * 		Global Interrupt Enable
	 * 		Set Timer Initial Value
	 * 		Configure Timer Mode
	 * 		Configure Compare Match
	 * 		Enable Overflow Interrupt
	 */

	// Set global interrupt enable bit
	SET_BIT(SREG,7);

	// Timer Initial Value
	//OCR0 = Duty_cycle * 256;





	/* #################Configure the timer modes (Normal, PWM, ...)################# */
	/*	Options
	 * 		NORMAL
	 * 		CTC
	 * 		FAST_PWM
	 * 		PHASE_CORRECT
	 */

	/*		Normal Mode 	*/
	if (TIMER_MODE == NORMAL)
	{
		/*	Select Normal Mode	*/
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);


		/* #################Configure the Compare Match################# */
		/*	Options
		 * 		OC0_DISCONNECTED
		 * 		TOGGLE_OC0
		 * 		CLEAR_OC0
		 * 		SET_OC0
		 */

		/*		0C0 Disconnected 	*/
		if (NORMAL_COMPARE_OUTPUT_MODE == OC0_DISCONNECTED)
		{
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}

		/*		Toggle_OC0 			*/
		else if (NORMAL_COMPARE_OUTPUT_MODE == TOGGLE_OC0 && (TIMER_MODE == NORMAL || TIMER_MODE == CTC) )	// Toggle is in NON-PWM modes only
		{
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}

		/*		Clear_OC0		 	*/
		else if (NORMAL_COMPARE_OUTPUT_MODE == CLEAR_OC0)
		{
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}

		/*		Set 0C0  			*/
		else if (NORMAL_COMPARE_OUTPUT_MODE == SET_OC0)
		{
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}
	}

	/*		CTC	Mode		*/
	else if (TIMER_MODE == CTC)
	{
		/*	Select CTC Mode	*/
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);



		/* #################Configure the Compare Match################# */
		/*	Options
		 * 		OC0_DISCONNECTED
		 * 		TOGGLE_OC0
		 * 		CLEAR_OC0
		 * 		SET_OC0
		 */

		/*		0C0 Disconnected 	*/
		if (CTC_COMPARE_OUTPUT_MODE == OC0_DISCONNECTED)
		{
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}

		/*		Toggle_OC0 			*/
		else if (CTC_COMPARE_OUTPUT_MODE == TOGGLE_OC0 && (TIMER_MODE == NORMAL || TIMER_MODE == CTC) )	// Toggle is in NON-PWM modes only
		{
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}

		/*		Clear_OC0		 	*/
		else if (CTC_COMPARE_OUTPUT_MODE == CLEAR_OC0)
		{
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}

		/*		Set 0C0  			*/
		else if (CTC_COMPARE_OUTPUT_MODE == SET_OC0)
		{
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}


		/*	Adjust Compare Match	*/
		OCR0 = CTC_OCR0_Value;
	}

	/*		Fast PWM		*/
	else if (TIMER_MODE == FAST_PWM)
	{
		/*	Select FAST PWM Mode	*/
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);

		/* #################Configure the Compare Match################# */
		/*	Options
		 * 		OC0_DISCONNECTED
		 * 		CLEAR_OC0
		 * 		SET_OC0
		 */

		/*		0C0 Disconnected 	*/
		if (FAST_PWM_COMPARE_OUTPUT_MODE == OC0_DISCONNECTED)
		{
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}


		/*		Clear_OC0		 	*/
		else if (FAST_PWM_COMPARE_OUTPUT_MODE == CLEAR_OC0)
		{
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}

		/*		Set 0C0  			*/
		else if (FAST_PWM_COMPARE_OUTPUT_MODE == SET_OC0)
		{
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}



		OCR0 = FAST_PWM_OCR0_Value;
	}

	/*		Phase_Correct	*/
	else if  (TIMER_MODE == PHASE_CORRECT)
	{
		/*	Select Phase Correct Mode	*/
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);


		/* #################Configure the Compare Match################# */
		/*	Options
		 * 		OC0_DISCONNECTED
		 * 		CLEAR_OC0
		 * 		SET_OC0
		 */

		/*		0C0 Disconnected 	*/
		if (PHASE_CORRECT_COMPARE_OUTPUT_MODE == OC0_DISCONNECTED)
		{
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}


		/*		Clear_OC0		 	*/
		else if (PHASE_CORRECT_COMPARE_OUTPUT_MODE == CLEAR_OC0)
		{
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}

		/*		Set 0C0  			*/
		else if (PHASE_CORRECT_COMPARE_OUTPUT_MODE == SET_OC0)
		{
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}


		OCR0 = PHASE_CORRECT_OCR0_Value;


	}














	/* #################Configure the CLK Select################# */
	/*	Options
	 * 		FALLING_EDGE
	 * 		RISING_EDGE
	 * 		NO_PRESCALER
	 * 		PRESCALER_8
	 * 		PRESCALER_64
	 * 		PRESCALER_256
	 * 		PRESCALER_1024
	 */

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



