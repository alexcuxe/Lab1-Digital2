/*
 * display.h
 *
 * Created: 3/02/2025 09:53:21
 *  Author: Eber Alexander
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <avr/io.h>
#include <stdint.h>

void initDislayPorts(void);

// Mostrar número
void display(uint8_t dig);



#endif /* DISPLAY_H_ */