#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#include "../../LIB/STD_types.h"

// Control Pannel
#define TCCR0 (*((volatile u8*) 0x53))

// Timer Flags
#define TIMSK (*((volatile u8*) 0x59))

// Enable Interrupt
#define TIFR (*((volatile u8*) 0x58))

// Clock Ticks
#define TCNT0 (*((volatile u8*) 0x52))

// Ouput Compare Mode
#define OCR0 (*((volatile u8*) 0x5C))

// TCCR0 BITS
#define FOC0 1 // Force Ouput Compare

#define WGM01 3 // PMW, Normal, CTC
#define WGM00 6 

#define COM01 5 // Ouput Compare Mode 
#define COM00 4

#define CS02 2 // Prescalling, External Clock Source
#define CS01 1
#define CS00 0

// TIMSK BITS
#define TOIE0 0 // Timer Overflow Interrupt Enable
#define OCIE0 1 // Output Compore Interrupt Enable

// Timer Mode
#define TIMER0_NORMAL_MODE 0
#define TIMER0_CTC_MODE 1
#define TIMER0_PHASECORRECT_MODE 2
#define TIMER0_FASTPWM_MODE 3

// Timer Prescaler, Source : CS
#define TIMER0_DISCONNECT 0
#define TIMER0_PRESCALER_1 1
#define TIMER0_PRESCALER_8 2
#define TIMER0_PRESCALER_64 3
#define TIMER0_PRESCALER_256 4
#define TIMER0_PRESCALER_1024 5
#define TIMER0_PRESCALER_EXTCLK_FALLEDGE 6
#define TIMER0_PRESCALER_EXTCLK_RAISEDGE 7

// Compare modes
#define TIMER0_OC0_DISCONNECTED 0
#define TIMER0_OC0_TOG 1
#define TIMER0_OC0_CLEAR 2
#define TIMER0_OC0_SET 3
#define TIMER_OC0_PWM_NON_INVERTING 4
#define TIMER_OC0_PWM_INVERTING 5



#endif
