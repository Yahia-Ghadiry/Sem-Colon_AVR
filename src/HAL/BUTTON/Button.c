#include "Button.h"

void BUTTON_vInitButton(u8 u8Port_ID, u8 u8Pin_ID, u8 u8Pull_UP)
{
    DIO_vSetPinDirection(u8Port_ID, u8Pin_ID, PIN_INPUT);
    DIO_vSetPinValue(u8Port_ID, u8Pin_ID, u8Pull_UP);

}

u8 BUTTON_u8ReadButton(u8 u8Port_ID, u8 u8Pin_ID)
{
    return DIO_u8GetPinValue(u8Port_ID, u8Pin_ID);
}


