/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 4 part 2
 */ 
#include <avr/io.h>

enum state {Init, wait, add_pressed, sub_pressed, add, subtract,  reset} state;
unsigned char add_button = 0x00;
unsigned char sub_button = 0x00;
unsigned char count = 0x00;

//Functions
void tick(){
	//Local Variables
	
	
	
	switch(state)	{		//State Transitions
		
		case(Init):
			state = wait;
			count = 0x07;
			PORTC = count;
		break;
		
		case(wait):
		
			if((add_button == 0) && (sub_button == 0)){
				state = wait;
			}
		
			else if((add_button & 0x01) && (sub_button == 0)){
				state = add_pressed;
			}
		
			else if((add_button == 0) && (sub_button & 0x02)){
				state = sub_pressed;
			}
		
			else{
				state = reset;
			}
		
		break;
		
		case(add_pressed):
			state = add;
		break;
		
		case(add):
			if((add_button == 0) && (sub_button == 0)){
				state = wait;
			}
		
			else if((add_button & 0x01) && (sub_button == 0)){
				state = add;
			}
		
			else if((add_button == 0) && (sub_button & 0x02)){
				state = sub_pressed;
			}
		
			else{
				state = reset;
			}
		break;
		
		case(sub_pressed):
			state = subtract;
		break;
		
		case(subtract):
			if((add_button == 0) && (sub_button == 0)){
				state = wait;
			}
		
			else if((add_button == 0) && (sub_button & 0x02)){
				state = subtract;
			}
		
			else if((add_button & 0x01) && (sub_button == 0)){
				state = add_pressed;
			}
		
			else{
				state = reset;
			}
		break;
		
		case(reset):
			state = wait;
		break;
		
		default:
			state = Init;
		break;
	}
	
	switch(state){		//State Actions
		case(Init):
			add_button = PINA & 0x01;
			sub_button = PINA & 0x02;

		break;
		
		case(wait):
			add_button = PINA & 0x01;
			sub_button = PINA & 0x02;
		break;
		
		case(add_pressed):
		
			if(count < 9){
				count = count + 1;
				PORTC = count;
			}
			
			else{
				PORTC = count;
			}
			
			add_button = PINA & 0x01;
			sub_button = PINA & 0x02;
		break;
		
		case(add):
			add_button = PINA & 0x01;
			sub_button = PINA & 0x02;
		break;
		
		case(sub_pressed):
		
			if(count > 0){
				count = count - 1;
				PORTC = count;
			}
		
			else{
				PORTC = count;
			}
		
			add_button = PINA & 0x01;
			sub_button = PINA & 0x02;
		break;
		
		case(subtract):
			add_button = PINA & 0x01;
			sub_button = PINA & 0x02;
		break;
		
		case(reset):
			count = 0;
			PORTC = count;
		
			add_button = PINA & 0x01;
			sub_button = PINA & 0x02;
		break;
		
		default:
			state = Init;
		break;
	}
}



//Global Variables

int main(void)
{
	DDRA = 0x00; PINA = 0xFF;
	DDRC = 0xFF; PINC = 0x00;

	state = Init;	
	
	while (1)
	{
		tick();
	}
}

