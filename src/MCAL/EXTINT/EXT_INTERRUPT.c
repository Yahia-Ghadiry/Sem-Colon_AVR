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
            break;

        case EXT_INT1_ID:
            MaskReg(MCUCR, MCUCR_ISC1_MASK);
            PostMaskSet(MCUCR, u8SenseControl, MCUCR_ISC10);
            break;
    
        case EXT_INT2_ID:
            MaskReg(MCUCSR, MCUCSR_ISC2_MASK);
            MaskReg(u8SenseControl, IC2_SENSE_MASK);
            PostMaskSet(MCUCSR, u8SenseControl, MCUCSR_ISC2);
            break;
    }
}


