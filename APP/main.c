#include "MCAL/DIO/DIO.h"
#include "LIB/BitMath.h"
#include "LIB/STD_types.h"
//#include <util/delay.h>

#define F_CPU 8000000UL

int main(void)
{
    DIO_vSetPinDirection(PORTA_ID, PIN1_ID, PIN_OUTPUT);
    DIO_vSetPinValue(PORTA_ID, PIN1_ID, PIN_HIGH);
    
    while (1)
    {

    }
}
