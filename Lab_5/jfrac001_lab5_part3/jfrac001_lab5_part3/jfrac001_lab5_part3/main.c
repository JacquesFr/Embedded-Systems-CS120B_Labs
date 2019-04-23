/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 5 part 3 challenge 1
 */ 

#include <avr/io.h>

unsigned char direction = 0x00;
unsigned char light;
unsigned char counter = 0x00;
unsigned char reset = 0x00;
unsigned char button;

enum state {Init, wait, button_pressed, button_released} state;
	
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}


void tick(){
	
	switch(state)	{		//State Transitions
		
		case(Init):
			counter = 0x00;
			direction = 0x00;
			state = wait;
		break;
		
		case(wait):
			if(button == 0x00){
				state = wait;
			}
			else{
				state = button_pressed;
			}
		break;
		
		case(button_pressed):
			if(button == 0x01){
				state = button_pressed;
			}
			else{
				state = button_released;
			}
		break;
		
		case(button_released):
		
			if(!direction){
				if(counter < 6){
					light = SetBit(light, counter, 1);
					counter++;
					PORTB = light;
				}
				else{
					direction = 0x01;
					light = reset;
					PORTB = light;
				}
			}
			else{
				if(counter == 0){
					direction = 0x00;
					light = reset;
					PORTB = light;
				}
				else{
					light = SetBit(light, counter, 1);
					counter --;
					PORTB = light & 0x3F;
				}
			}
			
			state = wait;
			
		break;
		
		default:
			state = Init;
		break;
	}

}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		button = PINA & 0x01;
		tick();
    }
	
	return 0;
}

