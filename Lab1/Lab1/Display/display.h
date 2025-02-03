/*
 * display.h
 *
 * Created: 3/02/2025 08:44:01
 *  Author: Eber Alexander
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>
#include <util/delay.h>


//Puertos para display
void initDislayPorts(void); 

// Mostrar número
void display(uint8_t dig);




#endif /* DISPLAY_H_ */