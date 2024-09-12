#include "TIMER0_Private.h"
#include "TIMER0_Config.h"
#include "TIMER0_Interface.h"
#include "../../LIB/BitMath.h"
#include "../EXTINT/EXT_INTERRUPT.h"
#include <stdlib.h>

u32  Timer0_NumOfOV = 0;
u32  Timer0_NumOfCM = 0;

void Timer0_vInit(void)
{
    #if (TIMER0_MODE == TIMER0_NORMAL_MODE)
        ClrBit(TCCR0, WGM00);
        ClrBit(TCCR0, WGM01);
    #elif (TIMER0_MODE == TIMER0_CTC_MODE )
        ClrBit(TCCR0, WGM00);
        SetBit(TCCR0, WGM01);
    #elif (TIMER0_MODE == TIMER0_PHASECORRECT_MODE)
        SetBit(TCCR0, WGM00);
        ClrBit(TCCR0, WGM01);
    #elif (TIMER0_MODE == TIMER0_FASTPWM_MODE)
        SetBit(TCCR0, WGM00);
        SetBit(TCCR0, WGM01);
    #endif
}


void Timer0_vEnableInt(u8 u8IntId)
{
    switch (u8IntId)
    {
        case TIMER0_OVF_INT_ID:
            SetBit(TIFR, TOIE0);
            sei();
            break;
        case TIMER0_COMP_MATCH_INT_ID:
            SetBit(TIFR, OCIE0);
            sei();
            break;

    }
}


void Timer0_vDisableInt(u8 u8IntId)
{
    switch (u8IntId)
    {
        case TIMER0_OVF_INT_ID:
            ClrBit(TIFR, TOIE0);
            sei();
            break;
        case TIMER0_COMP_MATCH_INT_ID:
            ClrBit(TIFR, OCIE0);
            sei();
            break;
    }
}


void Timer0_vStart(void)
{
	//step 1 : clear TCNT0
	

	
	//step 2 : insert clock
	#if( TIMER0_PRESCALER ==  TIMER0_PRESCALER_1 )

	
	
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_8 )


	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_64 )

	

	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_256 )


	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_1024)

	
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_EXTCLK_FALLEDGE)

	
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_EXTCLK_RAISEDGE)


	#endif
}

void Timer0_vStop(void)
{
	// Clear all clock selection bits to stop the timer
}


void Timer0_vSetTime(u32 DesiredTime_ms)
{
	// Array of prescaler values --> u32
	

	// Calculate the tick time in microseconds u32---> // result will be in micro 
	

	// Calculate the total number of ticks required u32

	
	// If the timer is in Normal mode
	#if( TIMER0_MODE ==  TIMER0_NORMAL_MODE )
	
	// Calculate the number of overflows required (How many times does it go to the ISR)
	

	// If the timer is in CTC mode
	#elif( TIMER0_MODE ==  TIMER0_CTC_MODE )
	
	u8 Maximum_Count = 255;

	// Find the appropriate compare match value (HINT : % )
	


	// Set the output compare register


	// Calculate the number of compare matches required


	#endif
}

