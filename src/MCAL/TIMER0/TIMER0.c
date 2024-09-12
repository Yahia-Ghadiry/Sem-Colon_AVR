#include "TIMER0_Private.h"
#include "TIMER0_Config.h"
#include "TIMER0_Interface.h"
#include "LIB/BitMath.h"
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
            break;
        case TIMER0_COMP_MATCH_INT_ID:
            ClrBit(TIFR, OCIE0);
            break;
    }
}


void Timer0_vStart(void)
{
    MaskReg(TCCR0, TIMER0_PRESCALER_MASK);
    PostMaskSet(TCCR0, TIMER0_PRESCALER, CS00);
}

void Timer0_vStop(void)
{
    MaskReg(TCCR0, TIMER0_PRESCALER_MASK);
    PostMaskSet(TCCR0, TIMER0_PRESCALER_DISCONNECT, CS00);
}


void Timer0_vSetTime(u32 u32DesiredTime_ms)
{

	
	#if( TIMER0_MODE ==  TIMER0_NORMAL_MODE )
	#elif( TIMER0_MODE ==  TIMER0_CTC_MODE )
	u8 Maximum_Count = 255;

	#endif
}

