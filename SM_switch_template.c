/*
	Template for state machine switch cases
*/
#include <avr/io.h>

enum states {Init} states;

void tick(){
	
	switch(states)	{		//State Transitions
		
		case(Init):
			if(){
				//Transition
			}
			else{
				//Transition
			}
		break;
		
		case():
			if(){
				//Transition
			}
			else{
				//Transition
			}
		break;
		
		default:
			states = Init;
		break;
	}
	
	switch(states){		//State Actions
		case(Init):		
			//Actions	
		break;
		
		case():
			//Actions
		break;
		
		default:
			//Actions
		break;
	}
}


int main(void)
{
	DDRA = 0x00; PINA = 0xFF;
	DDRB = 0xFF; PINB = 0x00;

	states = Init;
	
	while (1)
	{
		tick();
	}
}
