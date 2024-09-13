#ifndef _INTRUPUTS_COMMON_
#define _INTRUPUTS_COMMON_


#define _VECTOR(N)	__vector_ ## N

#define  ISR(VECT_NO)		\
			void VECT_NO(void) __attribute__((signal));\
			void VECT_NO(void)


#define sei()	__asm__ __volatile__ ("sei")		// Set Global Interrupt Enable
#define cli()	__asm__ __volatile__ ("cli")		// Close Global Interrupt


#endif
