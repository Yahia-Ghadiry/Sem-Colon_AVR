CC = avr-gcc
CFLAGS = -mmcu=atmega32


MAIN: 
	$(CC) $(CFLAGS) -c main.c -o main.o

DIO:
	$(CC) $(CFLAGS) -c MCAL/DIO/DIO.c -o dio.o

LINK: main.o dio.o
	$(CC) $(CFLAGS) dio.o main.o -o prog.elf

HEX: LINK
	avr-objcopy -j .text -O ihex prog.elf prog.hex

all: MAIN DIO LINK HEX
	@echo "Created everything"
