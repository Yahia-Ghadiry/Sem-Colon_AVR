#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(reg,pin) reg |=(1<<pin)
#define ClrBit(reg,pin) reg &=(~(1<<pin))
#define GetBit(reg,pin) (reg>>pin)&1
#define TogBit(reg,pin) reg ^=(1<<pin)
#define MaskReg(reg,mask) reg &=mask
#define PostMaskSet(reg,bits,shift) reg |=(bits<<shift)

#endif
