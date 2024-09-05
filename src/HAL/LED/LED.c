#include "LED.h"

void LED_vInit(u8 u8PortID, u8 u8PinID, u8 u8Mode)
{
    DIO_vSetPinDirection(u8PortID, u8PinID, PIN_OUTPUT);
    DIO_vSetPinValue(u8PortID, u8PinID, u8Mode ^ PIN_HIGH);
}

void LED_vTurnOn(u8 u8PortID, u8 u8PinID, u8 u8Mode)
{
    DIO_vSetPinValue(u8PortID, u8PinID, u8Mode ^ PIN_HIGH);
}
void LED_vTurnOff(u8 u8PortID, u8 u8PinID, u8 u8Mode)
{
    DIO_vSetPinValue(u8PortID, u8PinID, u8Mode ^ PIN_LOW);
}
