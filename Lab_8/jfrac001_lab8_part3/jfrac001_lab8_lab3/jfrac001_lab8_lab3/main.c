/*
 * Jacques Fracchia
 * Lab 8 Part 3
 * jfrac001@ucr.edu
 * April 29, 2019
 */ 

#include <avr/io.h>

unsigned short ANALOG_IN = 0x0000;
unsigned short MAX = 512;
unsigned char LED = 0x00;

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}


enum state {Init, wait} state;

void tick(){
	
	switch(state)	{		//State Transitions
		
		case(Init):
			state = wait;
			break;
		
		case(wait):
			state = wait;
			break;
		
		default:
			state = Init;
			break;
	}
	
	switch(state){		//State Actions
		case(Init):
			LED = 0x00;
			MAX = 0x90;
			break;
		
		case(wait):
			ANALOG_IN = ADC;
			if(ANALOG_IN >= MAX){
				LED = 0x01;
			}
			else{
				LED = 0x00;
			}
			PORTB = LED & 0x01;
			break;
		
		default:
			//Actions
			break;
	}
	
	
}



int main(void)
{
	DDRB = 0x01; PORTB = 0x00;
	
	state = Init;
	
	ADC_init();
    
    while (1) 
    {
		tick();
    }
}

