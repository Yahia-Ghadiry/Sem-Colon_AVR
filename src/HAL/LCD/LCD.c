#include "LCD.h"

void LCD_vInitialize(u8 u8FunctionSet, u8 u8DisplayControl, u8 u8EntryMode)
{
    DIO_vSetPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT); 
    DIO_vSetPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
    DIO_vSetPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_OUTPUT);

    _delay_ms(30);
    LCD_vSendCommand(u8FunctionSet);
    _delay_us(40);
    LCD_vSendCommand(u8DisplayControl);
    LCD_vClearScreen();
    _delay_us(2);
    LCD_vSendCommand(u8EntryMode);
    _delay_us(40);
}

void LCD_vSendCommand(u8 u8Command)
{
    DIO_vSetPortValue(LCD_DATA_PORT_ID, u8Command);
    DIO_vSetPinValue(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_LOW);

    DIO_vSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_HIGH);
    _delay_ms(2);
    DIO_vSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_LOW);
}

void LCD_vClearScreen()
{
    LCD_vSendCommand(LCD_CLEAR_SCREEN);
    _delay_us(2);
}

void LCD_vSendData(u8 u8Data)
{
    DIO_vSetPortValue(LCD_DATA_PORT_ID, u8Data);
    DIO_vSetPinValue(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_HIGH);

    DIO_vSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_HIGH);
    _delay_ms(2);
    DIO_vSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_LOW);
    
    _delay_us(44);
}
