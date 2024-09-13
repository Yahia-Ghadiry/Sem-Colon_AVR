#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "LIB/STD_types.h"
#include "MCAL/INTRUPUTS_COMMON/Intruputs_Common.h"

#define TIMER0_COMP_vect _VECTOR(10)
#define TIMER0_OVF_vect _VECTOR(11)

#define TIMER0_OVF_INT_ID          0
#define TIMER0_CM_INT_ID   1

void Timer0_vInit(void);
void Timer0_vStop(void);
void Timer0_vStart(void);
void Timer0_vEnableInt(u8 u8IntId);
void Timer0_vDisableInt(u8 u8IntId);
void Timer0_vSetTime_ms(u32 u32DesiredTime_ms);

#endif 
