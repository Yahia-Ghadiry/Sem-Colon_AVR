#ifndef _LCD_H
#define _LCD_H

#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO.h"

#define LED_MODE_0_ON 0
#define LED_MODE_1_ON 1

void LED_vInit(u8 u8PortID, u8 u8PinID, u8 u8Mode);
void LED_vTurnOn(u8 u8PortID, u8 u8PinID, u8 u8Mode);
void LED_vTurnOff(u8 u8PortID, u8 u8PinID, u8 u8Mode);


#endif
