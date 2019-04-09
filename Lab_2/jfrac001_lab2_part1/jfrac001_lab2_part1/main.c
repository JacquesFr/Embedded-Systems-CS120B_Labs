/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 2 part 1
 * Created: 4/3/2019 10:19:33 AM
 * 
 */ 

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA1 = 0x00; // Temporary variable to hold the value of A1
	unsigned char tmpA0 = 0x00; // Temporary variable to hold the value of A0
	while(1)
	{
		// 1) Read input
		tmpA1 = PINA & 0x02;
		tmpA0 = PINA & 0x01;
		// 2) Perform computation
		// if PA0 is 0 and PA1 is 0, set PB0 to 0;
		if (tmpA1 == 0x00 && tmpA0 == 0x01) { // True if PA0 is 1
			tmpB = (tmpB & 0xFC) | 0x01; // Sets tmpB to bbbbbb01
			// (clear rightmost 2 bits, then set to 01)
		}
		
		else {
			tmpB = (tmpB & 0xFC) | 0x00; // Sets tmpB to bbbbbb10
			// (clear rightmost 2 bits, then set to 10)
		}
		// 3) Write output
		PORTB = tmpB;
	}
	return 0;
}


