#include "EXT_INTERRUPT.h"

void EXTINT_vGlobalINT_Enable()
{
    SetBIT(SREG, SREG_I);    
}

void EXTINT_vGlobalINT_Disable()
{

(SREG, SREG_I);    

}
