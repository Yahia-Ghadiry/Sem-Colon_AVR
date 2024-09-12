#ifndef KEYPAD_H_
#define KEYPAD_H

#include "LIB/BitMath.h"
#include "LIB/STD_types.h"
#include "MCAL/DIO/DIO.h"

#define F_CPU 8000000UL
#include <util/delay.h>

// KeyPad Port

#define KEYPAD_PORT_ID PORTC_ID
#define KEYPAD_PORT_DIRECTION 0xF0

#define KEYPAD_ROW_LENGTH 4
#define KEYPAD_COLUMN_WIDTH 4

#define KEYPAD_PULL_UP 0xFF
#define KEYPAD_PULL_DOWN 0x00

#define KEYPAD_TEST_BEGIN 0x10
#define KEYPAD_TEST_OFFSET 1
#define KEYPAD_TEST_END 0x00

#define KEYPAD_NO_PRESSED_ALL 0xFF
#define KEYPAD_NO_PRESSED_COL 0x00
#define KEYPAD_PRESSED_COL_1 0x10
#define KEYPAD_PRESSED_COL_2 0x20
#define KEYPAD_PRESSED_COL_3 0x40
#define KEYPAD_PRESSED_COL_4 0x80

#define KEYPAD_COLUMN_1 0
#define KEYPAD_COLUMN_2 1
#define KEYPAD_COLUMN_3 2
#define KEYPAD_COLUMN_4 3


#define KEYPAD_SHIFT_READ(x) (x<<4)

void KEYPAD_vInit(u8 u8PullMode);
u8 KEYPAD_u8KeyPressed(u8 u8PullMode);

#endif
