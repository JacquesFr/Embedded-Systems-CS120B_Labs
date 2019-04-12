/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 3 part 4 (challenge 1)
 */ 

#include <avr/io.h>


int main(void)
{
    while (1) 
    {
		DDRA = 0x00; PORTA = 0xFF;
		DDRB = 0x0F; PORTB = 0x00;
		DDRC = 0xF0; PORTC = 0x00;
		
		unsigned char temp_a_upper = 0x00;
		unsigned char temp_a_lower = 0x00;
		
		temp_a_upper = PINA & 0xF0;
		temp_a_lower = PINA & 0x0F;
		
		temp_a_lower = temp_a_lower << 4;
		temp_a_upper = temp_a_upper >> 4;
		
		PORTB = temp_a_upper;
		PORTC = temp_a_lower;
    }
}

