#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO.h"




void BUTTON_vInitButton(u8 u8Port_ID, u8 u8Pin_ID, u8 u8Pull_UP);
u8 BUTTon_u8ReadButton(u8 u8Port_ID, u8 u8Pin_ID);

#endif /* BUTTON_H_ */
