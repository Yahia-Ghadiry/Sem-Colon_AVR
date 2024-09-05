#define F_CPU 8000000UL

#include "../LIB/BitMath.h"
#include "../LIB/STD_types.h"
#include "../MCAL/EXTINT/EXT_INTERRUPT.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/BUTTON/Button.h"
#include "../HAL/KEYPAD/Keypad.h"
#include <util/delay.h>

#define INFINTE 1

#define REACTION_DELAY 30

#define BUTTON_CONTINUE_PORT_ID PORTC_ID
#define BUTTON_CONTINUE_PIN_ID PIN0_ID

#define LED_PAUSED_PORT_ID PORTC_ID
#define LED_PAUSED_PIN_ID PIN6_ID


#define ON_OFF_KEY 0
#define KEYPAD_SYMBOlS (volatile char[4 * 4]){'7', '8', '9', '/', '4', '5', '6', '*', '1', '2', '3', '-', ON_OFF_KEY, '0', '=', '+'} 
#define ON_OFF_KEY_INDEX 12

#define VOTEING_A_INDEX 3
#define VOTEING_B_INDEX 7
#define VOTEING_C_INDEX 11
#define VOTEING_D_INDEX 15


void vVoting();
void vPauseVoting();
void vFinishVoting();

int main(void)
{
    sei();
    EXTINT_vInit(EXT_INT0_ID, RISING_EDGE);
    EXTINT_vInit(EXT_INT2_ID, RISING_EDGE);
    

    BUTTON_vInitButton(BUTTON_CONTINUE_PORT_ID, BUTTON_CONTINUE_PIN_ID, PIN_PULL_UP);

    LCD_vInit(LCD_FUNCTION_SET_BAISE | LCD_2_LINE | LCD_5x8, LCD_DISPLAY_ON_OFF_CONTROL_BAISE |  LCD_DISPLAY_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF, LCD_ENTRY_MODE_SET_BAISE | LCD_CURSOR_INC_MODE | LCD_SHIFT_DISPLAY_OFF);
    
    KEYPAD_vInit(KEYPAD_PULL_UP); 
    


    while(INFINTE)
    {
        vVoting();
    }
}

ISR(EXT_INT0_vect)
{
    vPauseVoting();
}

ISR(EXT_INT1_vect)
{
    vFinishVoting();
}


void vVoting()
{
    u8 u8KeyPad_pressed = KEYPAD_NO_PRESSED_ALL;
    u8 u8KeyPad_pressed_prev = KEYPAD_NO_PRESSED_ALL;
        
    u8 u8VoterA = 0;
    u8 u8VoterB = 0;
    u8 u8VoterC = 0;
    u8 u8VoterD = 0;

    LCD_vClearScreen();
    
    while(INFINTE)
    {
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


void vPauseVoting()
{
    LCD_vClearScreen();
    LCD_vSendString("Voting Paused");
    u8 u8ContinueButton = BUTTON_UP;

    while (true)
    {
        u8ContinueButton = BUTTON_u8ReadButton(BUTTON_CONTINUE_PORT_ID, BUTTON_CONTINUE_PIN_ID, BUTTON_PULLED_UP);
        
        if (u8ContinueButton == BUTTON_UP)
        {
            LED_
            break;
        }


    }
}

void vFinishVoting()
{

}


