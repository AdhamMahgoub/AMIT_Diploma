#ifndef					TIMER_INTERFACE_H
#define 				TIMER_INTERFACE_H

void Timer_Counter_Init(void);
void __vector_11 (void)		__attribute__((signal,	used)); //to avoid compiler optimization 


#endif