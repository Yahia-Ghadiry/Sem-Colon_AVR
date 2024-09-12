#ifndef EXT_INTERRUPT_H
#define EXT_INTERRUPT_H

#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"

#define NULL 0

// Global Interrupt Enable
#define SREG *((volatile u8*) 0x5F) 
#define SREG_I  7 

// Prephiral Interrupt Enable
#define GICR *((volatile u8*) 0x5B)
#define GICR_INT0 6
#define GICR_INT1 7
#define GICR_INT2 5

// Prephiral Interrupt Flag
#define GIFR *((volatile u8*) 0x5A)  //General Interrupt Flag Register -------- EXTINT flag
#define GIFR_INT0 6
#define GIFR_INT1 7
#define GIFR_INT2 5


// Sense Control Registers
#define MCUCR *((volatile u8*) 0x55)

#define MCUCR_ISC0_MASK 0b11111100
#define MCUCR_ISC1_MASK 0b11110011

#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3


#define MCUCSR *((volatile u8*) 0x54)
#define MCUCSR_ISC2_MASK 0b10111111
#define MCUCSR_ISC2          6

// Sense Control
#define LOW_LEVEL   0
#define LOGICAL_CHANGE  1
#define FALLNG_EDGE     2
#define RISING_EDGE     3

#define IC2_SENSE_MASK 0b1

// Flag
#define FLAG_ENABLE 1
#define FLAG_DISABLE 0


// Intruput IDs
#define EXT_INT0_ID 1
#define EXT_INT1_ID 2
#define EXT_INT2_ID 3

// Intruput IDs
#define _VECTOR(N)	__vector_ ## N

// Intruputs Vector
#define EXT_INT0_vect _VECTOR(1)
#define EXT_INT1_vect _VECTOR(2)
#define EXT_INT2_vect _VECTOR(3)


#define  ISR(VECT_NO)		\
			void VECT_NO(void) __attribute__((signal));\
			void VECT_NO(void)


#define sei()	__asm__ __volatile__ ("sei")		// Set Global Interrupt Enable
#define cli()	__asm__ __volatile__ ("cli")		// Close Global Interrupt


void EXTINT_vGlobalINT_Enable();
void EXTINT_vGlobalINT_Disable();
void EXTINT_vInit(u8 u8IntID, u8 u8SenseControl);    
void EXTINT_vEnableInterrupt(u8 u8IntID);
void EXTINT_vDisableInterrupt(u8 u8IntID);
u8 EXTINT_u8GetFlag(u8 u8IntID);
void EXTINT_vSetCallBack(void (*pvCallBack)(void) , u8 u8IntID);

#endif
