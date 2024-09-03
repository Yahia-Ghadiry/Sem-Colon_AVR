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

#define VOTEING_A_INDEX 3
#define VOTEING_B_INDEX 7
#define VOTEING_C_INDEX 11
#define VOTEING_D_INDEX 15


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
            Mode2(MODE_2);
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
    u8 u8read_switch = u8Mode_ID;
    u8 u8KeyPad_pressed = KEYPAD_NO_PRESSED_ALL;
    u8 u8KeyPad_pressed_prev = KEYPAD_NO_PRESSED_ALL;
        
    u8 u8VoterA = 0;
    u8 u8VoterB = 0;
    u8 u8VoterC = 0;
    u8 u8VoterD = 0;

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
                u8VoterA = 0;
                u8VoterB = 0;
                u8VoterC = 0;
                u8VoterD = 0;
            }
            else
            {
                switch (u8KeyPad_pressed)
                {
                    case VOTEING_A_INDEX:
                        u8VoterA++;
                        break;
                    case VOTEING_B_INDEX:
                        u8VoterB++;
                        break;
                    case VOTEING_C_INDEX:
                        u8VoterC++;
                        break;
                    case VOTEING_D_INDEX:
                        u8VoterD++;
                        break;
                }
            }
            
            LCD_vClearScreen();
            LCD_vSendString("A=");
            LCD_vSendInt(u8VoterA);
            LCD_vMoveCursor(LCD_LINE1_POSITION | LCD_CHAR9_POSITION);
            LCD_vSendString("B=");
            LCD_vSendInt(u8VoterB);
            LCD_vMoveCursor(LCD_LINE2_POSITION | LCD_CHAR1_POSITION);
            LCD_vSendString("C=");
            LCD_vSendInt(u8VoterC);
            LCD_vMoveCursor(LCD_LINE2_POSITION | LCD_CHAR9_POSITION);
            LCD_vSendString("D=");
            LCD_vSendInt(u8VoterD);
        }

        u8KeyPad_pressed_prev = u8KeyPad_pressed;

        _delay_ms(REACTION_DELAY);

    }
}
