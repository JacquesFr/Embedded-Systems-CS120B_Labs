/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 4 part 4 challenge 1
 */ 

#include <avr/io.h>

enum state {Init, wait, pound_pressed, pound_lift_up, open, lock_pressed, lock_lift_up, unlock, lock} state;
unsigned char x = 0x00;
unsigned char y = 0x00;
unsigned char hash0 = 0x00;
unsigned char locking = 0x00;
unsigned char unlocking = 0x00;
unsigned char lockcheck = 0x00;
unsigned char count = 0x00;


void tick(){
	
	switch(state)	{		//State Transitions
		
		case(Init):
			state = wait;
		break;
		
		case(wait):
		
			if((x == 0) && (y == 0) && (hash0 & 0x04)){
				state = pound_pressed;
			}
			
			else if ((locking & 0x80) && (unlocking & 0x01)) {
				state = lock_pressed;
			}
			
			else{
				state = wait;
			}
			
		break;
		
		case(pound_pressed):
		
			if((x == 0) && (y == 0) && (hash0 & 0x04)){
				state = pound_pressed;
			}
			else if((x == 0) && (y == 0) && (hash0 == 0)){
				state = pound_lift_up;
			}
			
			else{
				state = wait;
			}
			
		break;
		
		case(pound_lift_up):
			if(count == 0){
				if((x & 0x01) && (y == 0) && (hash0 == 0)){
					state = open;
				}
			}
			
			else if(count & 0x01){
				if((x == 0) && (y & 0x02) && (hash0 == 0)){
					state = open;
				}
			}
			
			else if(count & 0x02){
				if((x & 0x01) && (y == 0) && (hash0 == 0)){
					state = open;
				}
			}
			
			else{
				state = wait;				
			}
			
		break;
		
		case(open):
		
			if(count < 3){
				state = pound_lift_up;
			}
		
			else{
				if(lockcheck == 0){
					state = unlock;
				}
				
				else{
					state = lock;
				}
			}
			
		break;
		
		case(lock):	
			lockcheck = 0x00;
			unlocking = 0x00;
			PORTB = unlocking;
			state = wait;
		break;
		
		case(unlock):
			lockcheck = 0x01;
			unlocking = 0x01;
			PORTB = unlocking;
			state = wait;
		break;
		
		case(lock_pressed):
			if(locking & 0x80){
				state = lock_pressed;
			}
			else{
				state = lock_lift_up;
			}
		break;
		
		case(lock_lift_up):
			state = wait;
		break;
		
		default:
			state = Init;
		break;
	}
	
	switch(state){		//State Actions
		case(Init):
			x = PINA & 0x01;
			y = PINA & 0x02;
			hash0 = PINA & 0x04;
			locking = PINA & 0x80;
			
			unlocking = 0x00;
			PORTB = unlocking;
			PORTC = state;
		break;
		
		case(wait):
			x = PINA & 0x01;
			y = PINA & 0x02;
			hash0 = PINA & 0x04;
			locking = PINA & 0x80;
			count = 0x00;
			PORTC = state;
		break;
		
		case(pound_pressed):
			x = PINA & 0x01;
			y = PINA & 0x02;
			hash0 = PINA & 0x04;
			locking = PINA & 0x80;
			
			PORTC = state;
		break;
		
		case(pound_lift_up):
			x = PINA & 0x01;
			y = PINA & 0x02;
			hash0 = PINA & 0x04;
			locking = PINA & 0x80;
			
			PORTC = state;
		break;
		
		case(open):
		
			x = PINA & 0x01;
			y = PINA & 0x02;
			hash0 = PINA & 0x04;
			locking = PINA & 0x80;
			count++;
			PORTC = state;
			
		break;
		
		case(lock):
			
			x = PINA & 0x01;
			y = PINA & 0x02;
			hash0 = PINA & 0x04;
			locking = PINA & 0x80;
			
			PORTC = state;
			
		break;
		
		case(unlock):
			x = PINA & 0x01;
			y = PINA & 0x02;
			hash0 = PINA & 0x04;
			locking = PINA & 0x80;
			
			PORTC = state;
			
		break;
		
		case(lock_pressed):
			unlocking = 0x00;
			PORTB = unlocking;
			
			x = PINA & 0x01;
			y = PINA & 0x02;
			hash0 = PINA & 0x04;
			locking = PINA & 0x80;
			
			PORTC = state;
		break;
		
		case(lock_lift_up):
			x = PINA & 0x01;
			y = PINA & 0x02;
			hash0 = PINA & 0x04;
			locking = PINA & 0x80;
			
			PORTC = state;
		break;
		
		default:
			state = Init;
		break;
	}
}


int main(void)
{
	DDRA = 0x00; PINA = 0xFF;
	DDRB = 0xFF; PINB = 0x00;
	DDRC = 0xFF; PINC = 0x00;

	state = Init;
	
	while (1)
	{
		tick();
	}
}