#include "EXT_INTERRUPT.h"

void EXTINT_vGlobalINT_Enable()
{
    SetBit(SREG, SREG_I);    
}

void EXTINT_vGlobalINT_Disable()
{
    ClrBit(SREG, SREG_I);
}

void EXTINT_vInit(u8 u8IntID, u8 u8SenseControl)
{
    switch (u8IntID) 
    {
        case EXT_INT0_ID:
            MaskReg(MCUCR, MCUCR_ISC0_MASK);
            PostMaskSet(MCUCR, u8SenseControl, MCUCR_ISC00);
            SetBit(GICR, GICR_INT0);
            break;

        case EXT_INT1_ID:
            MaskReg(MCUCR, MCUCR_ISC1_MASK);
            PostMaskSet(MCUCR, u8SenseControl, MCUCR_ISC10);
            SetBit(GICR, GICR_INT1);
            break;
    
        case EXT_INT2_ID:
            MaskReg(MCUCSR, MCUCSR_ISC2_MASK);
            MaskReg(u8SenseControl, IC2_SENSE_MASK);
            PostMaskSet(MCUCSR, u8SenseControl, MCUCSR_ISC2);
            SetBit(GICR, GICR_INT2);
            break;
    }
}

void EXTINT_vEnableInterrupt(u8 u8IntID)
{
    switch(u8IntID)
    {
        case EXT_INT0_ID:
            SetBit(GICR, GICR_INT0);
            break;
        case EXT_INT1_ID:
            SetBit(GICR, GICR_INT1);
            break;
        case EXT_INT2_ID:
            SetBit(GICR, GICR_INT2);
            break;
    }
}
void EXTINT_vDisableInterrupt(u8 u8IntID)
{
    switch(u8IntID)
    {
        case EXT_INT0_ID:
            ClrBit(GICR, GICR_INT0);
            break;
        case EXT_INT1_ID:
            ClrBit(GICR, GICR_INT1);
            break;
        case EXT_INT2_ID:
            ClrBit(GICR, GICR_INT2);
            break;
    }
}

u8 EXTINT_u8GetFlag(u8 u8IntID)
{
    u8 u8Flag;
    switch (u8IntID)
    {
        case EXT_INT0_ID:
            u8Flag = GetBit(GIFR, GIFR_INT0);
            break;
        case EXT_INT1_ID:
            u8Flag = GetBit(GIFR, GIFR_INT1);
            break;
        case EXT_INT2_ID:
            u8Flag = GetBit(GIFR, GIFR_INT2);
            break;
    }

    return u8Flag;
}


void EXTINT_vSetCallBack(void (*pvCallBack)(void) , u8 u8IntID)
{
 // USE ISR macro
}

