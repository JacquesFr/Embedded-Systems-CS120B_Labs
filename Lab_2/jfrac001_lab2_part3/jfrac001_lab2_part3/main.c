/*
 * jfrac001_lab2_part3.c
 *
 * Created: 4/3/2019 6:17:14 PM
 * Author : jacqu
 */ 

#include <avr/io.h>
#include <math.h>



int main(void)
{
	DDRA = 0x00; PORTA = 0x0F; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char cntavail; // Temporary variable to hold the value of B
	int temp = 0x00;
	
	while(1)
	{
		cntavail = 4;
		
		for(double i = 0; i <= 3; i++){
			
			temp = ceil(pow(2,i));
			
			if(PINA & temp){
				cntavail--;
			}
		}
		
		if(cntavail == 0){
			cntavail = 0x80;
			PORTC = cntavail;
		}
		
		else{
			PORTC = cntavail;
		}
		
		
	}
	return 0;
}


