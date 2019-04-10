/*
 * Jacques Fracchia
 * jfrac001@ucr.edu 
 * Lab 3 part 1
 */ 

#include <avr/io.h>
#include <math.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
	// initialize to 0s
	unsigned char temp = 0x00;
	unsigned char count = 0x00;
	while(1)
	{
		count = 0x00;
		
		for(double i = 0; i <= 7; i++){
			
			temp = ceil(pow(2,i));
			
			if(PINA & temp){
				count++;
			}
			
			if(PINB & temp){
				count ++;
			}   
		}
		
		PORTC = count;
	}
}


