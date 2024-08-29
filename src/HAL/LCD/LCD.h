#ifndef LCD_H_
#define LCD_H_

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>

// LCD Ports

#define LCD_DATA_PORT_ID PORTA_ID

#define LCD_E_PORT_ID PORTB_ID
#define LCD_E_PIN_ID PIN0_ID

#define LCD_RS_PORT_ID PORTB_ID
#define LCD_RS_PIN_ID PIN1_ID

// Function set
#define LCD_FUNCTION_SET_BAISE 0x30

#define LCD_1_LINE 0x00
#define LCD_2_LINE 0x08

#define LCD_5x8 0x00
#define LCD_5x11 0x04

// Display ON/OFF control
#define LCD_DISPLAY_ON_OFF_CONTROL_BAISE 0x08

#define LCD_DISPLAY_OFF 0x00
#define LCD_DISPLAY_ON 0x04

#define LCD_CURSOR_OFF 0x00
#define LCD_CURSOR_ON 0x02

#define LCD_BLINK_OFF 0x00
#define LCD_BLINK_ON 0x01


#define LCD_CLEAR_SCREEN 0x01

// Entry mode set
#define LCD_ENTRY_MODE_SET_BAISE 0x04

#define LCD_CURSOR_INC_MODE 0x02
#define LCD_CURSOR_DEC_MODE 0x00

#define LCD_SHIFT_DISPLAY_OFF 0x00
#define LCD_SHIFT_DISPLAY_ON 0x01

void LCD_vInitialize(u8 u8FunctionSet, u8 u8DisplayControl, u8 u8EntryMode);
void LCD_vSendCommand(u8 u8Command);
void LCD_vSendData(u8 u8Data);
//void LCD_vSendString();
//void LCD_vMoveCursor()
void LCD_vClearScreen();

#endif /**LCD_H_**/
