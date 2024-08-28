#ifndef LCD_H_
#define LCD_H_

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO.h"

#define LCD_DATA_PORT_ID PORTA_ID

#define LCD_E_PORT_ID PORTB_ID
#define LCD_E_PIN_ID PIN0_ID

#define LCD_RS_PORT_ID PORTB_ID
#define LCD_RS_PIN_ID PIN1_ID

// Start up data codes
#define LCD_FUNCTION_SET 0x30
#define LCD_ON_OFF_CONTROL 0x08
#define LCD_CLEAR 0x01
#define LCD_ENTRY_MODE  0x

#endif /**LCD_H_**/
