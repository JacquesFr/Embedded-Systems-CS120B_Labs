/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 5 part 2
 */ 
#include <avr/io.h>
#include <time.h>
#include <stdio.h>

enum state {Init, wait, add_pressed, sub_pressed, add, subtract, reset_down, reset} state;
unsigned char pinCheck = 0x00;
unsigned char count = 0x00;


//Functions
void tick(){
	//Local Variables
	
	
	
	switch(state)	{		//State Transitions
		
		case(Init):
			state = wait;
			count = 0x00;
			PORTB = count;
		break;
		
		case(wait):
		
			if(pinCheck == 0x03){
				state = reset;
			}
		
			else if(pinCheck == 0x01){
				state = add_pressed;
			}
		
			else if(pinCheck == 0x02){
				state = sub_pressed;
			}
		
			else{
				state = wait;
			}
		
		break;
		
		case(add_pressed):
			
			if(pinCheck == 0x01){
				state = add_pressed;
			}
			
			else{
				if(count < 9){
					count = count + 1;
					PORTB = count;
				}
				
				else{
					PORTB = count;
				}
				
				state = add;
			}
			
		break;
		
		case(add):
	

				state = wait;
		
		break;
		
		case(sub_pressed):
		
			if(pinCheck == 0x02){
				state = sub_pressed;
			}
			else{
								if(count > 0){
									count = count - 1;
									PORTB = count;
								}
								
								else{
									PORTB = count;
								}
								
				state = subtract;
			}
			
		break;
		
		case(subtract):


				state = wait;
			
		break;
		
		case(reset_down):
			if(pinCheck == 0x03){
				state = reset_down;
			}
			else{
				state = reset;
			}
			
		break;
		
		case(reset):
			count = 0x00;
			PORTB = count;
			state = wait;
		break;
		
		default:
			state = Init;
		break;
	}
		
}



//Global Variables

int main(void)
{
	DDRA = 0x00; PORTA = 0x03;
	DDRB = 0x0F; PORTB = 0x00;

	state = Init;	
	
	while (1)
	{
		pinCheck = PINA & 0x03;
		tick();
	}
	
	return 0;
}

