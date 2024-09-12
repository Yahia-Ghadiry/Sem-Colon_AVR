#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "../../LIB/STD_types.h"

#define TIMER0_OVF_INT_ID          0
#define TIMER0_COMP_MATCH_INT_ID   1

void Timer0_vInit(void);
void Timer0_vStop(void);
void Timer0_vStart(void);
void Timer0_vEnableInt(u8 IntId);
void Timer0_vDisableInt(u8 IntId);
void Timer0_vSetTime(u32 DesiredTime_ms);

#endif 
