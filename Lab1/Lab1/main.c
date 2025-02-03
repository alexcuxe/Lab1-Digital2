/*
 * Lab1.c
 *
 * Created: 28/01/2025 14:33:21
 * Author : Alex Cuxe
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>
#include "disp/display.h"

uint8_t start = 0;
uint8_t counter1 = 0;
uint8_t counter2 = 0;
uint8_t shift1 = 0;
uint8_t shift2 = 0;
uint8_t block = 0;

void initPCINT0(void);
void initPCINT1(void);

int main(void)
{
	cli();
	initDislayPorts();
	
	PORTB |= (1 << PINB4);		//pins of PORTB as input w pull up
	DDRB = 0x0F;		//inputs and ouputs
	
	PORTC |= (1 << PINC4) | (1 << PINC5);
	DDRC = 0x0F;			//inputs and outputs
	
	initPCINT0();
	initPCINT1();
	sei();
	
    while (1) 
    {
		if(start == 1){ //reverse counter
			display(5);
			_delay_ms(1000);
			display(4);
			_delay_ms(1000);
			display(3);
			_delay_ms(1000);
			display(2);
			_delay_ms(1000);
			display(1);
			_delay_ms(1000);
			display(0);
			start = 2;
		}
    }
}


//************************************************************
//                 Interruptions
//************************************************************

void initPCINT0(void){
	PCICR |= (1 << PCIE0);						//pin change
	PCMSK0 |= (1 << PCINT4);	//mask
}

void initPCINT1(void){
	PCICR |= (1 << PCIE1);	
	PCMSK1 |= (1 << PCINT12) | (1 << PCINT13);
}

ISR (PCINT0_vect){
	if (!(PINB & (1 << PINB4))) {
		if(block == 0){				// blocks if anyone has won
			if(start == 2){			// if nobody has won, it counts and shifts
				PORTC &= 0xF0;
				counter1++;
				if(counter1 >= 4){
					shift1 = 4;		// left shift limit
				}
				shift1 = counter1 - 1;
				PORTC |= (1 << shift1);
				if (PORTC & (1 << PINC3)){		// if the player wins,
					block = 1;					//blocks and shows its number on display
					display(1);
					PORTC |= 0x0F;				//turn on all of its leds
					PORTB &= 0xF0;				// turn off all of the other leds
				}
			}
		}
	}
}

ISR(PCINT1_vect){
	if (!(PINC & (1 << PINC4))){
		if(start == 0){			//just for starting
			start = 1;
		}else{
			start = start;		//it won't let u choose another option
		}
	}
	
	if (!(PINC & (1 << PINC5))){
		if (block == 0){
			if(start == 2){
				PORTB &= 0xF0;
				counter2++;
				if(counter2 >= 4){
					shift2 = 4;
				}
				shift2 = counter2 - 1;
				PORTB |= (1 << shift2);
				if (PORTB & (1 << PINB3)){
					block = 1;
					display(2);
					PORTB |= 0x0F;
					PORTC &= 0xF0;
				}
			}
		}
	}
}