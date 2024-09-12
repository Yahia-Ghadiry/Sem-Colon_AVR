#define F_CPU 8000000UL

#include "LIB/BitMath.h"
#include "LIB/STD_types.h"
#include "MCAL/EXTINT/EXT_INTERRUPT.h"
#include "HAL/LED/LED.h"
#include "HAL/BUTTON/Button.h"
#include "HAL/LCD/LCD.h"
#include "HAL/KEYPAD/Keypad.h"
#include <util/delay.h>

#define INFINTE 1

#define REACTION_DELAY 30

#define BUTTON_CONTINUE_PORT_ID PORTD_ID
#define BUTTON_CONTINUE_PIN_ID PIN5_ID

#define LED_PAUSED_PORT_ID PORTD_ID
#define LED_PAUSED_PIN_ID PIN6_ID
#define LED_FINISHED_PORT_ID PORTD_ID
#define LED_FINISHED_PIN_ID PIN7_ID


#define ON_OFF_KEY 0
#define KEYPAD_SYMBOlS (volatile char[4 * 4]){'7', '8', '9', '/', '4', '5', '6', '*', '1', '2', '3', '-', ON_OFF_KEY, '0', '=', '+'} 
#define ON_OFF_KEY_INDEX 12

#define VOTEING_A_BUTTON_INDEX 3
#define VOTEING_B_BUTTON_INDEX 7
#define VOTEING_C_BUTTON_INDEX 11
#define VOTEING_D_BUTTON_INDEX 15

#define VOTERS_COUNT 4
#define VOTER_A_ID 0
#define VOTER_B_ID 1
#define VOTER_C_ID 2
#define VOTER_D_ID 3


u8 u8Voters[] = {0, 0, 0, 0};
char u8VotersNames[] = {'A', 'B', 'C', 'D'};

void vGetVoting();
void vDisplayVoting();
void vPauseVoting();
void vFinishVoting();

int main(void)
{
    sei();
    EXTINT_vInit(EXT_INT0_ID, RISING_EDGE);
    EXTINT_vInit(EXT_INT1_ID, RISING_EDGE);
    
    LED_vInit(LED_PAUSED_PORT_ID, LED_PAUSED_PIN_ID, LED_MODE_1_ON);
    LED_vInit(LED_FINISHED_PORT_ID, LED_FINISHED_PIN_ID, LED_MODE_1_ON);

    BUTTON_vInitButton(BUTTON_CONTINUE_PORT_ID, BUTTON_CONTINUE_PIN_ID, BUTTON_PULLED_UP);

    LCD_vInit(LCD_FUNCTION_SET_BAISE | LCD_2_LINE | LCD_5x8, LCD_DISPLAY_ON_OFF_CONTROL_BAISE |  LCD_DISPLAY_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF, LCD_ENTRY_MODE_SET_BAISE | LCD_CURSOR_INC_MODE | LCD_SHIFT_DISPLAY_OFF);
    
    KEYPAD_vInit(KEYPAD_PULL_UP); 

    vDisplayVoting();

    while(INFINTE)
    {
        vGetVoting();
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

void vDisplayVoting()
{
    LCD_vClearScreen();
    LCD_vSendString("A=");
    LCD_vSendInt(u8Voters[VOTER_A_ID]);
    LCD_vMoveCursor(LCD_LINE1_POSITION | LCD_CHAR9_POSITION);
    LCD_vSendString("B=");
    LCD_vSendInt(u8Voters[VOTER_B_ID]);
    LCD_vMoveCursor(LCD_LINE2_POSITION | LCD_CHAR1_POSITION);
    LCD_vSendString("C=");
    LCD_vSendInt(u8Voters[VOTER_C_ID]);
    LCD_vMoveCursor(LCD_LINE2_POSITION | LCD_CHAR9_POSITION);
    LCD_vSendString("D=");
    LCD_vSendInt(u8Voters[VOTER_D_ID]);

}

void vGetVoting()
{
    u8 u8KeyPad_pressed = KEYPAD_NO_PRESSED_ALL;
    u8 u8KeyPad_pressed_prev = KEYPAD_NO_PRESSED_ALL;
    
    while(INFINTE)
    {
        u8KeyPad_pressed = KEYPAD_u8KeyPressed(KEYPAD_PULL_UP);
            
        if (u8KeyPad_pressed != KEYPAD_NO_PRESSED_ALL && u8KeyPad_pressed != u8KeyPad_pressed_prev)
        {
            if (u8KeyPad_pressed == ON_OFF_KEY_INDEX)
            {
                for (u8 i = VOTER_A_ID; i < VOTERS_COUNT; i++)
                {
                    u8Voters[i] = 0;
                }
            }
            else
            {
                switch (u8KeyPad_pressed)
                {
                    case VOTEING_A_BUTTON_INDEX:
                        u8Voters[VOTER_A_ID]++;
                        break;
                    case VOTEING_B_BUTTON_INDEX:
                        u8Voters[VOTER_B_ID]++;
                        break;
                    case VOTEING_C_BUTTON_INDEX:
                        u8Voters[VOTER_C_ID]++;
                        break;
                    case VOTEING_D_BUTTON_INDEX:
                        u8Voters[VOTER_D_ID]++;
                        break;
                }
            }
            vDisplayVoting();
        }

        u8KeyPad_pressed_prev = u8KeyPad_pressed;

        _delay_ms(REACTION_DELAY);

    }
}


void vPauseVoting()
{
    LCD_vClearScreen();
    LCD_vSendString("Voting Paused");
    LED_vTurnOn(LED_PAUSED_PORT_ID, LED_PAUSED_PIN_ID, LED_MODE_1_ON);
    
    u8 u8ContinueButton = BUTTON_UP;

    while (true)
    {
        u8ContinueButton = BUTTON_u8ReadButton(BUTTON_CONTINUE_PORT_ID, BUTTON_CONTINUE_PIN_ID, BUTTON_PULLED_UP);
        
        if (u8ContinueButton == BUTTON_DOWN)
        {
            LED_vTurnOff(LED_PAUSED_PORT_ID, LED_PAUSED_PIN_ID, LED_MODE_1_ON);
            vDisplayVoting();
            break;
        }
        
        _delay_ms(REACTION_DELAY);

    }
}

void vFinishVoting()
{
    LCD_vClearScreen();
    LCD_vSendString("Voting Finished");
    LED_vTurnOn(LED_FINISHED_PORT_ID, LED_FINISHED_PIN_ID, LED_MODE_1_ON);
    
    u8 u8HighestVotes = 0;
    u8 u8NumeberTies = 0;
    char u8Winner;

    for (u8 i = VOTER_A_ID; i < VOTERS_COUNT; i++)
    {
        if (u8HighestVotes < u8Voters[i])
        {
            u8HighestVotes = u8Voters[i];
        }
    }
    for (u8 i = VOTER_A_ID; i < VOTERS_COUNT; i++)
    {
        if (u8HighestVotes == u8Voters[i])
        {
            u8NumeberTies++;
            u8Winner = u8VotersNames[i];
        }
    }
    
    LCD_vMoveCursor(LCD_LINE2_POSITION | LCD_CHAR1_POSITION);

    if (u8NumeberTies == 1)
    {
        LCD_vSendData(u8Winner);
        LCD_vSendString(" Is the Winner");
    }
    else if (u8NumeberTies > 1)
    {
        LCD_vSendData('0' + u8NumeberTies);
        LCD_vSendString(" Ties");
    }

    u8 u8ContinueButton = BUTTON_UP;

    while (true)
    {
        u8ContinueButton = BUTTON_u8ReadButton(BUTTON_CONTINUE_PORT_ID, BUTTON_CONTINUE_PIN_ID, BUTTON_PULLED_UP);
        
        if (u8ContinueButton == BUTTON_DOWN)
        {
            LED_vTurnOff(LED_FINISHED_PORT_ID, LED_FINISHED_PIN_ID, LED_MODE_1_ON);
            for (u8 i = VOTER_A_ID; i < VOTERS_COUNT; i++)
            {
                u8Voters[i] = 0;
            }
            vDisplayVoting();
            break;
        }
        
        _delay_ms(REACTION_DELAY);

    }
}


