/*
	Template for state machine switch cases
*/
#include <avr/io.h>

enum state {Init} state;

void tick();


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

tick(){
	
	switch(state)	{		//State Transitions
		
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
			state = Init;
		break;
	}
	
	switch(state){		//State Actions
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
