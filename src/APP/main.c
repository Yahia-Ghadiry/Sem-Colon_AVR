#define F_CPU 8000000UL

#include "../MCAL/DIO/DIO.h"
#include "../HDL/LCD/LCD.h"
#include "../LIB/BitMath.h"
#include "../LIB/STD_types.h"
#include <util/delay.h>


int main(void)
{
    LCD_vInitialize(LCD_FUNCTION_SET_BAISE | LCD_2_LINE | LCD_5x8, LCD_DISPLAY_ON_OFF_CONTROL_BAISE |  LCD_DISPLAY_ON | LCD_CURSOR_ON | LCD_BLINK_ON, LCD_ENTRY_MODE_SET_BAISE | LCD_CURSOR_INC_MODE | LCD_SHIFT_DISPLAY_OFF);
    for (int i = 64; i < 90; i++)
        LCD_vSendData(i);
    while (true)
    {}
}
