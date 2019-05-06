/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * April 29, 2019
 */ 

#include <avr/io.h>

unsigned short analog_in;
unsigned char tempB = 0; 
unsigned char tempD = 0;

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	//        in Free Running Mode, a new conversion will trigger whenever
	//        the previous conversion completes.
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
			tempB = 0;
			tempD = 0;
			break;
		
		case(wait):
			analog_in = ADC;
			tempB = (char) analog_in;
			tempD = (char) (analog_in >> 8);
			
			PORTB = tempB & 0xFF;
			PORTD = tempD & 0x03;
			
			break;
		
		default:
			//Actions
			break;
	}
	
	
}



int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	state = Init;
	
	ADC_init();
	
    
    while (1) 
    {
		tick();
		
    }
}


