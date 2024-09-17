#include "ADC.h"
#include "LIB/BitMath.h"

void ADC_vInit(u8 u8Prescaler)
{

    MaskReg(ADMUX, ADC_REFS_MASK);
    PostMaskSet(ADMUX, ADC_REF, ADMUX_REFS0);

    MaskReg(ADCSRA, ADC_PRESCALER_MASK);
    PostMaskSet(ADCSRA, u8Prescaler, ADCSRA_ADPS0);

    SetBit(ADCSRA, ADCSRA_ADEN);

}

u16 ADC_u16ReadChannel(u8 u8Channel)
{
    MaskReg(ADMUX, ADC_ADMUX_MUX_MASK);
    PostMaskSet(ADMUX, u8Channel, ADMUX_MUX0);

    SetBit(ADCSRA, ADCSRA_ADSC);

}

void ADC_vDisable()
{
    ClrBit(ADCSRA, ADCSRA_ADEN);
}

void ADC_vEnable()
{
    SetBit(ADCSRA, ADCSRA_ADEN);
}
