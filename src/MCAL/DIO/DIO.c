#include "DIO.h"

void DIO_vSetPinDirection (u8 u8Port_ID, u8 u8Pin_ID, u8 u8Direction)
{
    if (u8Direction == PIN_INPUT)
    {
        switch (u8Port_ID)
        {
            case PORTA_ID:
                ClrBit(DDRA, u8Pin_ID);
                break;
            case PORTB_ID:
                ClrBit(DDRB, u8Pin_ID);
                break;
            case PORTC_ID:
                ClrBit(DDRC, u8Pin_ID);
                break;
            case PORTD_ID:
                ClrBit(DDRD, u8Pin_ID);
                break;
        }
    }
    else if  (u8Direction == PIN_OUTPUT)
    {
        switch (u8Port_ID)
        {
            case PORTA_ID:
                SetBit(DDRA, u8Pin_ID);
                break;
            case PORTB_ID:
                SetBit(DDRB, u8Pin_ID);
                break;
            case PORTC_ID:
                SetBit(DDRC, u8Pin_ID);
                break;
            case PORTD_ID:
                SetBit(DDRD, u8Pin_ID);
                break;
        }

    }

}

void DIO_vSetPortDirection (u8 u8Port_ID, u8 u8Direction)
{
    switch (u8Port_ID)
    {
        case PORTA_ID:
            DDRA = u8Direction;
            break;
        case PORTB_ID:
            DDRB = u8Direction;
            break;
        case PORTC_ID:
            DDRC = u8Direction;
            break;
        case PORTD_ID:
            DDRD = u8Direction;
            break;
    } 
}

void DIO_vSetPinValue(u8 u8Port_ID, u8 u8Pin_ID, u8 u8Value)
{
    if (u8Value == PIN_LOW)
    {
        switch (u8Port_ID)
        {
            case PORTA_ID:
                ClrBit(PORTA, u8Pin_ID);
                break;
            case PORTB_ID:
                ClrBit(PORTB, u8Pin_ID);
                break;
            case PORTC_ID:
                ClrBit(PORTC, u8Pin_ID);
                break;
            case PORTD_ID:
                ClrBit(PORTD, u8Pin_ID);
                break;
        }
    }
    else if (u8Value == PIN_HIGH)
    {
        switch (u8Port_ID)
        {
            case PORTA_ID:
                SetBit(PORTA, u8Pin_ID);
                break;
            case PORTB_ID:
                SetBit(DDRB, u8Pin_ID);
                break;
            case PORTC_ID:
                SetBit(DDRC, u8Pin_ID);
                break;
            case PORTD_ID:
                SetBit(DDRD, u8Pin_ID);
                break;
        }
    }
}

void DIO_vSetPortValue(u8 u8Port_ID, u8 u8Value)
{
    switch (u8Port_ID)
    {
        case PORTA_ID:
            PORTA = u8Value;
            break;
        case PORTB_ID:
            PORTB = u8Value;
            break;
        case PORTC_ID:
            PORTC = u8Value;
            break;
        case PORTD_ID:
            PORTD = u8Value;
            break;
    }
}


u8 DIO_u8GetPinValue (u8 u8Port_ID, u8 u8Pin_ID)
{
    u8 pin;
    switch (u8Port_ID)
    {
        case PORTA_ID:
            pin = GetBit(PINA, u8Pin_ID);
            break;
        case PORTB_ID:
            pin = GetBit(PINB, u8Pin_ID);
            break;
        case PORTC_ID:
            pin = GetBit(PINC, u8Pin_ID);
            break;
        case PORTD_ID:
            pin = GetBit(PIND, u8Pin_ID);
            break;
    }
    return pin;

}

u8 DIO_u8GetPortValue (u8 u8Port_ID)
{
    u8 pin;
    switch (u8Port_ID)
    {
        case PORTA_ID:
            pin = PINA;
            break;
        case PORTB_ID:
            pin = PINB;
            break;
        case PORTC_ID:
            pin = PINC;
            break;
        case PORTD_ID:
            pin = PIND;
            break;
    }
    return pin;
}
