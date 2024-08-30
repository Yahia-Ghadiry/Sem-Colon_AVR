#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO.h"

#define BUTTON_PULLED_UP 1
#define BUTTON_PULLED_DOWN 0

#define BUTTON_DOWN 1
#define BUTTON_UP 0



void BUTTON_vInitButton(u8 u8Port_ID, u8 u8Pin_ID, u8 u8Pull_UP);
u8 BUTTON_u8ReadButton(u8 u8Port_ID, u8 u8Pin_ID, u8 u8Pull_TYPE);

#endif /* BUTTON_H_ */
