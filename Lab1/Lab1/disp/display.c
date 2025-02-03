/*
 * display.c
 *
 * Created: 3/02/2025 08:44:13
 *  Author: Eber Alexander
 */ 


#include "display.h"


//Puertos para display
void initDislayPorts(void){
	//Set pins
	DDRD = 0xFF;	//entire PORTD as output
	PORTD = 0;		//turn off the entire port
	UCSR0B = 0;		//rx and tx as normal pins
	PORTD = 0;
}

// Mostrar número
void display(uint8_t dig){
	uint8_t displayN[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
	
	switch (dig)
	{
	case 0:
	PORTD = displayN[0];
	break;
		
	case 1:
	PORTD = displayN[1];
	break;
		
	case 2:
	PORTD = displayN[2];
	break;
	
	case 3:
	PORTD = displayN[3];
	break;
	
	case 4:
	PORTD = displayN[4];
	break;
	
	case 5:
	PORTD = displayN[5];
	break;
	
	case 6:
	PORTD = displayN[6];
	break;
	
	case 7:
	PORTD = displayN[7];
	break;
	
	case 8:
	PORTD = displayN[8];
	break;
	
	case 9:
	PORTD = displayN[9];
	break;
	
	case 10:
	PORTD = displayN[10];
	break;
	
	case 11:
	PORTD = displayN[11];
	break;
	
	case 12:
	PORTD = displayN[12];
	break;
	
	case 13:
	PORTD = displayN[13];
	break;
	
	case 14:
	PORTD = displayN[14];
	break;
	
	case 15:
	PORTD = displayN[15];
	break;
	}
}