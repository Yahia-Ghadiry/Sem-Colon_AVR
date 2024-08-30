#define F_CPU 8000000UL

#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/BUTTON/Button.h"
#include "../LIB/BitMath.h"
#include "../LIB/STD_types.h"
#include <util/delay.h>

#define BUTTON1_PORT_ID PORTC_ID
#define BUTTON1_PIN_ID PIN0_ID
#define BUTTON2_PORT_ID PORTC_ID
#define BUTTON2_PIN_ID PIN1_ID

#define USER_NAME "Yahia Ghadiry"
#define USER_AGE 19

void vDisplayNameAge(char sName[], u8 u8Age);


int main(void)
{
    BUTTON_vInitButton(BUTTON1_PORT_ID, BUTTON1_PIN_ID, PIN_PULL_UP);
    BUTTON_vInitButton(BUTTON2_PORT_ID, BUTTON2_PIN_ID, PIN_PULL_UP);

    LCD_vInitialize(LCD_FUNCTION_SET_BAISE | LCD_2_LINE | LCD_5x8, LCD_DISPLAY_ON_OFF_CONTROL_BAISE |  LCD_DISPLAY_ON | LCD_CURSOR_ON | LCD_BLINK_ON, LCD_ENTRY_MODE_SET_BAISE | LCD_CURSOR_INC_MODE | LCD_SHIFT_DISPLAY_OFF);

    DDRC = 0xF0;
    DDRD = 0xFF;

    while(1)
    {
        _delay_ms(400);
        PORTC = 0XFF;
        _delay_ms(400);
        PORTC = 0X0F;
        _delay_ms(400);

        u8 u8read_button1 = BUTTON_u8ReadButton(BUTTON1_PORT_ID, BUTTON1_PIN_ID, BUTTON_PULLED_UP);
        
        if(u8read_button1 ==  BUTTON_DOWN)
        {
            LCD_vClearScreen();
            _delay_ms(400);
            char cccc[] = "YAHIA";
            LCD_vSendString();
            continue;
            LCD_vSendInt(USER_AGE);
        }

        _delay_ms(400);
        PORTD = 0x00;
        _delay_ms(400);
        
        u8 u8read_button2 = BUTTON_u8ReadButton(BUTTON2_PORT_ID, BUTTON2_PIN_ID, BUTTON_PULLED_UP);

        if(u8read_button2 ==  BUTTON_DOWN)
        {
            LCD_vClearScreen();
        }

        _delay_ms(30);
    }
}

