/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 3 part 5 challenge 2
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		
		DDRD = 0x00; PORTD = 0xFF;
		DDRB = 0xFE; PORTB = 0x01;
		
		unsigned char air_bag = 0x00;
		unsigned short weight = 0x00;
		unsigned char valB0 = 0x00;
		
		weight = PIND & 0xFF;
		valB0 = PINB & 0x01;
		
		
		weight = weight << 1;
		weight = weight | valB0;
		
		if(weight >= 70){
			air_bag = 0x02;
		}
		
		else if(weight > 5 && weight < 70){
			air_bag = 0x04;	
		}
		
		else{
			air_bag = 0x00;
		}
		
		PORTB = air_bag;
    }
}

