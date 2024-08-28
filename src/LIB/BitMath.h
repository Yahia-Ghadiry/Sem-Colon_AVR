/*
 * BitMath.h
 *
 * Created: 13/8/2024 2:42:31 AM
 *  Author: Bassel Mahmoud
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(reg,pin) reg |=(1<<pin)
#define ClrBit(reg,pin) reg &=(~(1<<pin))
#define GetBit(reg,pin) (reg>>pin)&1
#define TogBit(reg,pin) reg ^=(1<<pin)






#endif /* BITMATH_H_ */
