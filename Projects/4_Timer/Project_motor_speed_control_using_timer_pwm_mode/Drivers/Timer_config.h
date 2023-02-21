#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/*		The user chooses from here		*/								/*		Possible Options (spelling not correct)			*/
#define Timer_Mode						Fast_PWM						//	normal, pwm, phase correct, ctc, fast pwm
#define Compare_Output_Mode_non_pwm		not_used						//	not used (using pwm "fast or phase"), disconnected, toggle, clear, set
#define Compare_Output_Mode_fast_pwm	Set_Oc0_fast_pwm				//	not used (using non-pwm or phase pwm), disconnected, toggle, clear, set
#define Timer_clock_select				prescalar_1024					//	falling_edge, rising_edge, prescalar 
#define Duty_cycle						0.5
/*		End of user config				*/



//#define Timer_Mode (WGM00,01)			Normal 
#define Normal							1
#define PWM								2
#define Phase_Correct					2
#define CTC								3
#define Fast_PWM						4

//#define Compare_Output_Mode_non_pwm	OC0_Disconnected_non_pwm
#define not_used						0
#define OC0_Disconnected_non_pwm		1
#define Toggle_OC0_non_pwm				2
#define Clear_OC0_non_pwm				3
#define Set_Oc0_non_pwm					4

//#define Compare_Output_Mode_fast_pwm	OC0_Disconnected_fast_pwm
#define OC0_Disconnected_fast_pwm		1
#define Clear_OC0_fast_pwm				2
#define Set_Oc0_fast_pwm				3


//#define Timer_clock_select			falling_edge
#define falling_edge					1
#define rising_edge						2
#define no_prescalar 					3
#define prescalar_8						4
#define prescalar_64					5
#define prescalar_256					6
#define	prescalar_1024					7





#endif /* TIMER_CONFIG_H_ */