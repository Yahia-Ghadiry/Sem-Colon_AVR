#define F_CPU 8000000UL

#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/BUTTON/Button.h"
#include "../LIB/BitMath.h"
#include "../LIB/STD_types.h"
#include <util/delay.h>

#define INFINTE 1

#define SWITCH_PORT_ID PORTC_ID
#define SWITCH_PIN_ID PIN0_ID

#define BUTTON1_PORT_ID PORTC_ID
#define BUTTON1_PIN_ID PIN1_ID
#define BUTTON2_PORT_ID PORTC_ID
#define BUTTON2_PIN_ID PIN2_ID

#define USER_NAME "YAHIA"
#define USER_AGE 19
u8 customChar[] = {
  0b00000,
  0b11011,
  0b11011,
  0b00000,
  0b00100,
  0b10001,
  0b01110,
  0b10001
};


void Mode1(u8 u8Mode_ID);
void Mode2(u8 u8Mode_ID);

int main(void)
{
    BUTTON_vInitButton(BUTTON1_PORT_ID, BUTTON1_PIN_ID, PIN_PULL_UP);
    BUTTON_vInitButton(BUTTON2_PORT_ID, BUTTON2_PIN_ID, PIN_PULL_UP);
    BUTTON_vInitButton(SWITCH_PORT_ID, SWITCH_PIN_ID, PIN_PULL_UP);

    LCD_vInitialize(LCD_FUNCTION_SET_BAISE | LCD_2_LINE | LCD_5x8, LCD_DISPLAY_ON_OFF_CONTROL_BAISE |  LCD_DISPLAY_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF, LCD_ENTRY_MODE_SET_BAISE | LCD_CURSOR_INC_MODE | LCD_SHIFT_DISPLAY_OFF);

    LCD_vMakeCustomChar(customChar, LCD_SET_CGRAM_ADDRESS_BAISE | LCD_CHAR1_POSITION);

    u8 u8read_switch = BUTTON_DOWN;


    
    while(INFINTE)
    {
        u8read_switch = BUTTON_u8ReadButton(SWITCH_PORT_ID, SWITCH_PIN_ID, BUTTON_PULLED_UP);
        if (u8read_switch == BUTTON_UP)
        {
            Mode1(BUTTON_UP);
        }
        else if (u8read_switch == BUTTON_DOWN)
        {
            Mode2(BUTTON_DOWN);
            
        }
    }
}
void Mode1(u8 u8Mode_ID)
{
    u8 u8read_button1_prev = BUTTON_UP;
    u8 u8read_button2_prev = BUTTON_UP;
    u8 u8read_button1 = BUTTON_UP;
    u8 u8read_button2 = BUTTON_UP;

    u8 u8read_switch = u8Mode_ID;
    
    LCD_vClearScreen();

    while(INFINTE)
    {
        u8read_switch = BUTTON_u8ReadButton(SWITCH_PORT_ID, SWITCH_PIN_ID, BUTTON_PULLED_UP);
        if (u8read_switch != u8Mode_ID)
            break;

        u8read_button1 = BUTTON_u8ReadButton(BUTTON1_PORT_ID, BUTTON1_PIN_ID, BUTTON_PULLED_UP);    
        
        if(u8read_button1 ==  BUTTON_DOWN && u8read_button1 != u8read_button1_prev)
        {
            LCD_vClearScreen();
            LCD_vSendString(USER_NAME);
            LCD_vMoveCursor(LCD_LINE2_POSITION | LCD_CHAR1_POSITION);
            LCD_vSendInt(USER_AGE);

        }


        u8read_button2 = BUTTON_u8ReadButton(BUTTON2_PORT_ID, BUTTON2_PIN_ID, BUTTON_PULLED_UP);

        if(u8read_button2 ==  BUTTON_DOWN && u8read_button2 != u8read_button2_prev)
        {
            LCD_vClearScreen();
        }

        u8read_button1_prev = u8read_button1;
        u8read_button2_prev = u8read_button2;

        _delay_ms(30);

    }
}

void Mode2(u8 u8Mode_ID)
{
    u8 u8Counter = 0;
    
    u8 u8read_button1_prev = BUTTON_UP;
    u8 u8read_button2_prev = BUTTON_UP;
    u8 u8read_button1 = BUTTON_UP;
    u8 u8read_button2 = BUTTON_UP;

    u8 u8read_switch = u8Mode_ID;
    
    LCD_vClearScreen();
    LCD_vSendInt(u8Counter);

    while(INFINTE)
    {
        u8read_switch = BUTTON_u8ReadButton(SWITCH_PORT_ID, SWITCH_PIN_ID, BUTTON_PULLED_UP);
        if (u8read_switch != u8Mode_ID)
            break;

        u8read_button1 = BUTTON_u8ReadButton(BUTTON1_PORT_ID, BUTTON1_PIN_ID, BUTTON_PULLED_UP);    
        
        if(u8read_button1 ==  BUTTON_DOWN && u8read_button1 != u8read_button1_prev)
        {
            LCD_vClearScreen();
            u8Counter++;
            LCD_vSendInt(u8Counter);
        }

        u8read_button2 = BUTTON_u8ReadButton(BUTTON2_PORT_ID, BUTTON2_PIN_ID, BUTTON_PULLED_UP);

        if(u8read_button2 ==  BUTTON_DOWN && u8read_button2 != u8read_button2_prev)
        {
            LCD_vClearScreen();
            u8Counter = 0;
            LCD_vSendInt(u8Counter);
        }

        u8read_button1_prev = u8read_button1;
        u8read_button2_prev = u8read_button2;

        _delay_ms(30);
    }
}
