#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

#include "LCD_interface.h"
#include "Timer_private.h"
#include "Timer_config.h"


#include <avr/interrupt.h>		

u32 ISR_Counter	= 0;
u32 time_counter = 0;

ISR (TIMER0_OVF_vect)				
{
	// do nothing 
}


void Timer_Counter_Init(void)
{
		//Set global interrupt enable bit
		SET_BIT(SREG,7);							
	
		OCR0 = Duty_cycle * 256;
		
		
		//configure the timer modes (normal, pwm, ...) 
		
		/*		Normal Mode 	*/
		if (Timer_Mode == 1) 		
		{
			CLR_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);
		}
		
		/*		PWM, Phase Correct	Mode	*/
		else if (Timer_Mode == 2) 	
		{
			SET_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);
		}
		
		/*		CTC	Mode	*/
		else if (Timer_Mode == 3)
		{
			CLR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
		}
				
		/*		Fast PWM	*/
		else if (Timer_Mode == 4)
		{
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
		}
		
		
		//configure the compare match (Non-PWM)
		
			//check PWM or non PWM//
		if (Compare_Output_Mode_non_pwm == -1)
		{
			// do nothing 
			// this means i'm PWM modes
		}
		
		/*		0C0 Disconnected 			*/
		else if (Compare_Output_Mode_non_pwm == 1)
		{
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}

		/*		Toggle_OC0 			*/
		else if (Compare_Output_Mode_non_pwm == 2)
		{
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}

		/*		Clear_OC0		 	*/
		else if (Compare_Output_Mode_non_pwm == 3)
		{
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}		
			
		/*		Set 0C0  			*/
		else if (Compare_Output_Mode_non_pwm == 4)
		{
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);		
		}
		

		//configure the compare match (PWM)
		
			//check PWM or non PWM//
		if (Compare_Output_Mode_fast_pwm == -1)
		{
			// do nothing 
			// this means i'm non-PWM modes
		}
		
		/*		0C0 Disconnected 			*/
		else if (Compare_Output_Mode_fast_pwm == 1)
		{
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}

		/*		Clear_OC0		 	*/
		else if (Compare_Output_Mode_fast_pwm == 2)
		{
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		}		
			
		/*		Set 0C0  			*/
		else if (Compare_Output_Mode_fast_pwm == 3)
		{
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);		
		}
		

		//configure the Timer Clock Select 		*/
		/*	Falling Edge			*/
		if (Timer_clock_select == 1)
		{
			CLR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);		
			SET_BIT(TCCR0,CS02);	
		}
		
		/*	Rising Edge				*/
		else if (Timer_clock_select == 2)
		{
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		}
		
		/*	No Prescalar 			*/
		else if (Timer_clock_select == 3)
		{
			SET_BIT(TCCR0,CS00);
			CLR_BIT(TCCR0,CS01);
			CLR_BIT(TCCR0,CS02);
		}

		/* 	Prescalar 8			*/
		else if (Timer_clock_select == 4)
		{
			CLR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLR_BIT(TCCR0,CS02);
		}
		
		/* 	Prescalar 64			*/
		else if (Timer_clock_select == 5)
		{
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLR_BIT(TCCR0,CS02);
		}
		
		/* 	Prescalar 256			*/
		else if (Timer_clock_select == 6)
		{
			CLR_BIT(TCCR0,CS00);
			CLR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		}
		
		/* 	Prescalar 1024			*/
		else if (Timer_clock_select == 7)
		{
			SET_BIT(TCCR0,CS00);
			CLR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		}
		
		//enable overflow interrupt 
		SET_BIT(TIMSK,BIT_TOIE0);
}



