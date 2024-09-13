#define F_CPU 8000000UL

#include "LIB/BitMath.h"
#include "LIB/STD_types.h"
#include "HAL/LED/LED.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/TIMER0/TIMER0_Interface.h"
#include <util/delay.h>

#define INFINTE 1

#define REACTION_DELAY 30

#define SEC_MS 1000

#define LEDS_PORT_ID PORTD_ID
#define GREEN_LED_PIN_ID PIN0_ID
#define YELLOW_LED_PIN_ID PIN1_ID
#define RED_LED_PIN_ID PIN2_ID


extern u32 Timer0_NumOfOV;
extern u32 Timer0_NumOfCM;

void vDisplayRemaing();

u32 counterCM = 0;

u8 RemaingSec = 10;
u8 LightMode = 0;

int main(void)
{
    sei();
    
    LED_vInit(LEDS_PORT_ID, GREEN_LED_PIN_ID, LED_MODE_1_ON);
    LED_vInit(LEDS_PORT_ID, YELLOW_LED_PIN_ID, LED_MODE_1_ON);
    LED_vInit(LEDS_PORT_ID, RED_LED_PIN_ID, LED_MODE_1_ON);

    
    LCD_vInit(LCD_FUNCTION_SET_BAISE | LCD_2_LINE | LCD_5x8, LCD_DISPLAY_ON_OFF_CONTROL_BAISE |  LCD_DISPLAY_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF, LCD_ENTRY_MODE_SET_BAISE | LCD_CURSOR_INC_MODE | LCD_SHIFT_DISPLAY_OFF);
    
    Timer0_vInit();
    Timer0_vEnableInt(TIMER0_CM_INT_ID);
    Timer0_vStart();
    
    Timer0_vSetTime_ms(SEC_MS);

    vDisplayRemaing();
    LED_vTurnOn(LEDS_PORT_ID, GREEN_LED_PIN_ID, LED_MODE_1_ON);
    
    while(INFINTE)
    {
        
        _delay_ms(REACTION_DELAY);
    }
}

ISR(TIMER0_COMP_vect)
{
    counterCM++;

    if(counterCM == SEC_MS)
    {
        counterCM = 0;
        RemaingSec--;
        if (RemaingSec == 0)
        {
            LightMode++;
            LightMode %= 3;
            switch (LightMode)
            {
                case 0:
                    RemaingSec = 10;
                    break;
                case 1:
                    RemaingSec = 5;
                    break;
                case 2:
                    RemaingSec = 7;
                    break;
            }
        }
        
        switch(LightMode)
        {
            case 0:
                LED_vTurnOn(LEDS_PORT_ID, GREEN_LED_PIN_ID, LED_MODE_1_ON);
                LED_vTurnOff(LEDS_PORT_ID, YELLOW_LED_PIN_ID, LED_MODE_1_ON);
                LED_vTurnOff(LEDS_PORT_ID, RED_LED_PIN_ID, LED_MODE_1_ON);
                break;

            case 1:
                LED_vTurnOff(LEDS_PORT_ID, GREEN_LED_PIN_ID, LED_MODE_1_ON);
                LED_vTurnOn(LEDS_PORT_ID, YELLOW_LED_PIN_ID, LED_MODE_1_ON);
                LED_vTurnOff(LEDS_PORT_ID, RED_LED_PIN_ID, LED_MODE_1_ON);
                break;

            case 2:
                LED_vTurnOff(LEDS_PORT_ID, GREEN_LED_PIN_ID, LED_MODE_1_ON);
                if (RemaingSec <= 3)
                {
                    LED_vTurnOn(LEDS_PORT_ID, YELLOW_LED_PIN_ID, LED_MODE_1_ON);
                }
                else
                {
                    LED_vTurnOff(LEDS_PORT_ID, YELLOW_LED_PIN_ID, LED_MODE_1_ON);
                }
                LED_vTurnOn(LEDS_PORT_ID, RED_LED_PIN_ID, LED_MODE_1_ON);
                break;
        }
        vDisplayRemaing();
    }
}

void vDisplayRemaing()
{
    LCD_vClearScreen();
    LCD_vSendString("Remaing ");
    LCD_vSendInt(RemaingSec - 1);
    LCD_vSendString(" Sec");
}


