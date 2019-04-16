/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 5 part 1
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0x0F; // Configure port A's 8 pins as inputs
	DDRB = 0x7F; PORTB = 0x00; // Configure port B's 8 pins as outputs
	// initialize to 0s
	unsigned char fuel = 0x00; // intermediate variable used for port updates
	unsigned char lights = 0x00;
	
	while(1)
	{
		
		
		lights = 0x00;
		
		fuel = PINA & 0x0F; // Mask PINA to only get the bit you are interested in
		
		if (fuel == 1 || fuel == 2 ){
			lights = 0x60;
		}
		
		else if(fuel == 3 || fuel == 4){
			lights = 0x70;
		}
		
		else if(fuel == 5 || fuel == 6){
			lights = 0x38;
		}
		
		else if(fuel >= 7 && fuel <= 9){
			lights = 0x3C;
		}
		
		else if(fuel >= 10 && fuel <= 12){
			lights = 0x3E;
		}
		
		else if(fuel >= 13 && fuel <= 15){
			lights = 0x3F;
		}
		
		else{
			lights = 0x00;
		}
		
		PORTB = lights;
	}
}


