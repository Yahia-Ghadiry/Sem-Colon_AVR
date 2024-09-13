#define F_CPU 8000000UL

#include "LIB/BitMath.h"
#include "LIB/STD_types.h"
#include "HAL/LED/LED.h"
#include "MCAL/TIMER0/TIMER0_Interface.h"
#include <util/delay.h>

#define INFINTE 1

#define REACTION_DELAY 30


extern u32 Timer0_NumOfOV;
extern u32 Timer0_NumOfCM;


int main(void)
{
    sei();
    
    //LED_vInit(LED_PAUSED_PORT_ID, LED_PAUSED_PIN_ID, LED_MODE_1_ON);
    //LED_vInit(LED_FINISHED_PORT_ID, LED_FINISHED_PIN_ID, LED_MODE_1_ON);


    while(INFINTE)
    {
    }
}

ISR(TIMER0_OVF_vect)
{


}

