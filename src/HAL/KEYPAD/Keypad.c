#include "Keypad.h"
#include <util/delay.h>


void KEYPAD_vInit(u8 u8PullMode)
{
    DIO_vSetPortDirection(KEYPAD_PORT_ID, KEYPAD_PORT_DIRECTION);
    DIO_vSetPortValue(KEYPAD_PORT_ID, u8PullMode);
}

u8 KEYPAD_u8KeyPressed(u8 u8PullMode)
{
    u8 u8ColumnPressed = KEYPAD_NO_PRESSED_COL;
    u8 u8KeyPressed = KEYPAD_NO_PRESSED_ALL;
    u8 u8RowCount = 0;
    
    for (u8 u8Test = KEYPAD_TEST_BEGIN; u8Test != KEYPAD_TEST_END; u8Test <<= KEYPAD_TEST_OFFSET)
    {
        DIO_vSetPortValue(KEYPAD_PORT_ID, u8Test ^ u8PullMode);
        u8ColumnPressed = (DIO_u8GetPortValue(KEYPAD_PORT_ID) ^ u8PullMode) << KEYPAD_ROW_LENGTH;

        if(u8ColumnPressed != KEYPAD_NO_PRESSED_COL)    
        {
            switch (u8ColumnPressed)
            {
                case KEYPAD_PRESSED_COL_1:
                    u8ColumnPressed = KEYPAD_COLUMN_1;
                    break;
                case KEYPAD_PRESSED_COL_2:
                    u8ColumnPressed = KEYPAD_COLUMN_2;
                    break;
                case KEYPAD_PRESSED_COL_3:
                    u8ColumnPressed = KEYPAD_COLUMN_3;
                    break;
                case KEYPAD_PRESSED_COL_4:
                    u8ColumnPressed = KEYPAD_COLUMN_4;
                    break;

            }

            u8KeyPressed = u8ColumnPressed + (KEYPAD_COLUMN_WIDTH * u8RowCount);
            break;
        }

        u8RowCount++;
    }


    return u8KeyPressed;
}

