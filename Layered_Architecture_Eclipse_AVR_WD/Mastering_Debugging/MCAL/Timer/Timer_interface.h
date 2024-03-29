#ifndef					TIMER_INTERFACE_H
#define 				TIMER_INTERFACE_H

#include "Timer_config.h"

void Timer0_Counter_Init(void);


void __vector_4 (void)		__attribute__((signal,	used)); // Timer ISR // Timer/Counter2 Compare Match
void __vector_5 (void)		__attribute__((signal,	used)); // Timer ISR // Timer/Counter2 Overflow

void __vector_6 (void)		__attribute__((signal,	used)); // Timer ISR // Timer/Counter1 Capture Event
void __vector_7 (void)		__attribute__((signal,	used)); // Timer ISR // Timer/Counter1 Compare Match A
void __vector_8 (void)		__attribute__((signal,	used)); // Timer ISR // Timer/Counter1 Compare Match B
void __vector_9 (void)		__attribute__((signal,	used)); // Timer ISR // Timer/Counter1 Overflow

void __vector_10 (void)		__attribute__((signal,	used)); // Timer ISR // Timer/Counter0 Compare Match
void __vector_11 (void)		__attribute__((signal,	used)); // Timer ISR // Timer/Counter0 Overflow


#endif
