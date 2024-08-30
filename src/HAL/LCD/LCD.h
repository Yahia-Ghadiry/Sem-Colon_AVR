#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL

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

// Cursor Position

#define LCD_SET_DDRAM_ADDRESS_BAISE 0x80

#define LCD_LINE1_POSITION 0x00
#define LCD_LINE2_POSITION 0x40

#define LCD_CHAR1_POSITION 0x00
#define LCD_CHAR2_POSITION 0x01
#define LCD_CHAR3_POSITION 0x02
#define LCD_CHAR4_POSITION 0x03
#define LCD_CHAR5_POSITION 0x04
#define LCD_CHAR6_POSITION 0x05
#define LCD_CHAR7_POSITION 0x06
#define LCD_CHAR8_POSITION 0x07

// CGRAM
#define LCD_SET_CGRAM_ADDRESS_BAISE 0x40


void LCD_vInitialize(u8 u8FunctionSet, u8 u8DisplayControl, u8 u8EntryMode);
void LCD_vSendCommand(u8 u8Command);
void LCD_vSendData(u8 u8Data);
void LCD_vSendString(const u8 *sStringa);
void LCD_vSendInt(u8 u8Int);
void LCD_vMoveCursor(u8 u8Postion);
void LCD_vClearScreen();
void LCD_vMakeCustomChar(u8 CustomChar[], u8 u8CGPositon);

#endif /**LCD_H_**/
