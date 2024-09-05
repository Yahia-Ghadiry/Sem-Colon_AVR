#include "LCD.h"


void LCD_vInit(u8 u8FunctionSet, u8 u8DisplayControl, u8 u8EntryMode)
{
    DIO_vSetPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT); 
    DIO_vSetPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
    DIO_vSetPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_OUTPUT);

    LCD_vSendCommand(u8FunctionSet);
    LCD_vSendCommand(u8DisplayControl);
    LCD_vClearScreen();
    LCD_vSendCommand(u8EntryMode);
}

void LCD_vSendCommand(u8 u8Command)
{
    DIO_vSetPortValue(LCD_DATA_PORT_ID, u8Command);
    DIO_vSetPinValue(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_LOW);

    DIO_vSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_HIGH);
    _delay_us(1);
    DIO_vSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_LOW);

    _delay_us(39);
}

void LCD_vClearScreen()
{
    LCD_vSendCommand(LCD_CLEAR_SCREEN);
    _delay_ms(2);
}

void LCD_vSendData(u8 u8Data)
{
    DIO_vSetPortValue(LCD_DATA_PORT_ID, u8Data);
    DIO_vSetPinValue(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_HIGH);

    DIO_vSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_HIGH);
    _delay_us(1);
    DIO_vSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_LOW);
    
    _delay_us(43);
}

void LCD_vSendString(const u8 *sString)
{
    int i = 0;
    
    while (sString[i] != '\0')
    {
        LCD_vSendData(sString[i]);
        PORTD = sString[i];
        i++;
    }
}

void LCD_vSendInt(u8 u8Int)
{
    u8 length = 0;
    u8 copy = u8Int;
    while(copy != 0)
    {
        copy /= 10;
        length++;
    }
    
    if (length == 0)
    {
        LCD_vSendData('0');
        return;
    }

    u8 IntString[length + 1];
    for (u8 i = 1; i <= length; i++)
    {
        IntString[length - i] = '0' + (u8Int %10);
        u8Int /= 10;
    }
    IntString[length] = '\0';
    LCD_vSendString(IntString);

}

void LCD_vMoveCursor(u8 u8Postion)
{
    LCD_vSendCommand(LCD_SET_DDRAM_ADDRESS_BAISE | u8Postion);
}

void LCD_vMakeCustomChar(const u8 CustomChar[], u8 u8CGPositon)
{
    LCD_vSendCommand(LCD_SET_CGRAM_ADDRESS_BAISE | u8CGPositon);
   
    for (u8 i = 0; i < 8; i++)
    {
        LCD_vSendData(CustomChar[i]);    
    }

    LCD_vMoveCursor(LCD_LINE1_POSITION | LCD_CHAR1_POSITION);
}
