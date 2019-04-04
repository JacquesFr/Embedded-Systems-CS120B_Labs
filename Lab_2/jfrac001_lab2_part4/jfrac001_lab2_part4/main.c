/*
 * jfrac001_lab2_part4.c
 *
 * Created: 4/4/2019 4:17:43 PM
 * Author : Jacques Fracchia
 */ 

#include <avr/io.h>
#include <stdio.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0x03; PORTD = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		unsigned char weight = 0;
		signed char unbalanced_left = 0;
		signed char unbalanced_right = 0;
		
		weight = PINA + PINB + PINC;
		unbalanced_left = PINA - PINC;
		unbalanced_right = PINC - PINA;
		PORTD = 0x00;
		
		if(weight > 140){
			PORTD = 0x01;
		}
		
		if(unbalanced_left >= 80 || unbalanced_left <= -80){
			PORTD = 0x02;
		}
		
		if(unbalanced_right >= 80 || unbalanced_right <= -80){
			PORTD = 0x02;
		}

		
		
		
    }
	return 0;
}

