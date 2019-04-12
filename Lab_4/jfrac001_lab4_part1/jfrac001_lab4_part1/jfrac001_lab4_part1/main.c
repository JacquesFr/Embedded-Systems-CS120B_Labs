/*
 * jfrac001_lab4_part1.c
 *
 * Created: 4/10/2019 9:34:47 AM
 * Author : jacqu
 */ 

#include <avr/io.h>

enum LED_states { light_1, light_2, tran0, tran1 } LED_states;
    unsigned char button = 0x00;	

void tick_latch(){
	
	switch(LED_states)	{		//state transitions
		
		case(light_1):
			if(button & 0x01){
				LED_states = tran0;
			}
			else{
				LED_states = light_1;
			}
		break;
		
		case(tran0):
			if(button == 0){
				LED_states = light_2;
			}
			else{
				LED_states = tran0;
			}
		break;
		
		case(light_2):
			if(button & 0x01){
				LED_states = tran1;
			}
			else{
				LED_states = light_2;
			}
		break;
		
		case(tran1):
			if(button == 0){
				LED_states = light_1;
			}
			else{
				LED_states = tran1;
			}
		break;
		
		default:
			LED_states = light_1;
		break;
		
		
	}
	
	switch(LED_states){		//state actions
		case(light_1):
			PORTB = 0x01;
			button = PINA & 0x01;
		break;
		
		case(tran0):
			button = PINA & 0x01;
			PORTB = 0X02;
		break;
		
		case(light_2):
			PORTB = 0x02; 
			button = PINA & 0x01;
		break;
		
		case(tran1):
			button = PINA & 0x01;
			PORTB = 0x01;
		break;
		
		default:
			PORTB = 0x01;
		break;
	}
}


int main(void)
{
	DDRA = 0x00; PINA = 0xFF;
	DDRB = 0xFF; PINB = 0x00;

	LED_states = light_1;
	
    while (1) 
    {
		tick_latch();
		
    }
}

