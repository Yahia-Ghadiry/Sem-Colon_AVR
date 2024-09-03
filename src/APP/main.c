#define F_CPU 8000000UL

#include "../LIB/BitMath.h"
#include "../LIB/STD_types.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/BUTTON/Button.h"
#include "../HAL/KEYPAD/Keypad.h"
#include <util/delay.h>

#define INFINTE 1

#define REACTION_DELAY 30

#define SWITCH_PORT_ID PORTC_ID
#define SWITCH_PIN_ID PIN0_ID

#define MODE_1 BUTTON_UP
#define MODE_2 BUTTON_DOWN

#define ON_OFF_KEY 0
#define KEYPAD_SYMBOlS (volatile char[4 * 4]){'7', '8', '9', '/', '4', '5', '6', '*', '1', '2', '3', '-', ON_OFF_KEY, '0', '=', '+'} 
#define ON_OFF_KEY_INDEX 12

void Mode1(u8 u8Mode_ID);
void Mode2(u8 u8Mode_ID);

int main(void)
{
    BUTTON_vInitButton(SWITCH_PORT_ID, SWITCH_PIN_ID, PIN_PULL_UP);

    LCD_vInitialize(LCD_FUNCTION_SET_BAISE | LCD_2_LINE | LCD_5x8, LCD_DISPLAY_ON_OFF_CONTROL_BAISE |  LCD_DISPLAY_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF, LCD_ENTRY_MODE_SET_BAISE | LCD_CURSOR_INC_MODE | LCD_SHIFT_DISPLAY_OFF);
    
    KEYPAD_vInit(KEYPAD_PULL_UP); 

    u8 u8read_switch = BUTTON_DOWN;
    
    
    while(INFINTE)
    {
        u8read_switch = BUTTON_u8ReadButton(SWITCH_PORT_ID, SWITCH_PIN_ID, BUTTON_PULLED_UP);
        if (u8read_switch == BUTTON_UP)
        {
            Mode1(MODE_1);
        }
        else if (u8read_switch == BUTTON_DOWN)
        {
            //tmp
            Mode1(MODE_2);
            
        }
    }
}
void Mode1(u8 u8Mode_ID)
{
    u8 u8read_switch = u8Mode_ID;
    u8 u8KeyPad_pressed = KEYPAD_NO_PRESSED_ALL;
    u8 u8KeyPad_pressed_prev = KEYPAD_NO_PRESSED_ALL;
        
    LCD_vClearScreen();
    
    while(INFINTE)
    {
        u8read_switch = BUTTON_u8ReadButton(SWITCH_PORT_ID, SWITCH_PIN_ID, BUTTON_PULLED_UP);
        if (u8read_switch != u8Mode_ID)
            break;
    
        u8KeyPad_pressed = KEYPAD_u8KeyPressed(KEYPAD_PULL_UP);
            
        if (u8KeyPad_pressed != KEYPAD_NO_PRESSED_ALL && u8KeyPad_pressed != u8KeyPad_pressed_prev)
        {
            if (u8KeyPad_pressed == ON_OFF_KEY_INDEX)
            {
                LCD_vClearScreen();
            }
            else
            {
                LCD_vSendData(KEYPAD_SYMBOlS[u8KeyPad_pressed]);
            }
        }


        u8KeyPad_pressed_prev = u8KeyPad_pressed;
        
        _delay_ms(REACTION_DELAY);
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

        
        if(u8read_button1 == BUTTON_DOWN && u8read_button1 != u8read_button1_prev)
        {
            LCD_vClearScreen();
            u8Counter++;
            LCD_vSendInt(u8Counter);
        }


        if(u8read_button2 ==  BUTTON_DOWN && u8read_button2 != u8read_button2_prev)
        {
            LCD_vClearScreen();
            u8Counter = 0;
            LCD_vSendInt(u8Counter);
        }

        u8read_button1_prev = u8read_button1;
        u8read_button2_prev = u8read_button2;

        _delay_ms(REACTION_DELAY);
    }
}
