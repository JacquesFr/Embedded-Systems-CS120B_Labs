/*
 * jfrac001_lab2_part2.c
 *
 * Created: 4/3/2019 2:22:10 PM
 * Author : jacqu
 */ 

#include <avr/io.h>
#include <math.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0x0F; 
	DDRC = 0xFF; PORTC = 0x00; 
	unsigned char cntavail = 0x00; 
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
		
		PORTC = cntavail;
		
		
	}
	return 0;
}

