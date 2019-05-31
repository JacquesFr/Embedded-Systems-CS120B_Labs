/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 10 part 2
 */ 

#include <avr/io.h>
#include "io.c"
#include <time.h>
#include <stdio.h>

volatile unsigned char TimerFlag = 0; // TimerISR() sets this to 1. C programmer should clear to 0.

unsigned long _avr_timer_M = 1; 
unsigned long _avr_timer_cntcurr = 0; 
unsigned int time_count = 10;
unsigned char cnt = 0x00;
unsigned char cnt0 = 0x00;



void TimerOn() {

	TCCR1B = 0x0B;
	OCR1A = 125;    // Timer interrupt will be generated when TCNT1==OCR1A
	TIMSK1 = 0x02; // bit1: OCIE1A -- enables compare match interrupt
	TCNT1=0;

	_avr_timer_cntcurr = _avr_timer_M;

	SREG |= 0x80; // 0x80: 1000000
}



void TimerOff() {
	TCCR1B = 0x00; 
}


void TimerISR() {
	TimerFlag = 1;
}


ISR(TIMER1_COMPA_vect) {
	_avr_timer_cntcurr--; // Count down to 0 rather than up to TOP
	if (_avr_timer_cntcurr == 0) { // results in a more efficient compare
		TimerISR(); // Call the ISR that the user uses
		_avr_timer_cntcurr = _avr_timer_M;
	}
}



// Set TimerISR() to tick every M ms

void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}

unsigned char threeLED = 0x00;
unsigned char blinkingLED = 0x00;
unsigned char combineLED = 0x00;

enum threeLED_states {Init0, LED1, LED2, LED3} threeLED_state;
enum blinkLED_states {Init1, LED_on, LED_off} blinkLED_state;
enum combineLED_states {Init2, out} combineLED_state;

void SM_threeLED(){
	
	switch(threeLED_state)	{		//State Transitions
		case(Init0):
			threeLED_state = LED1;
			break;
		
		case(LED1):
			if(cnt < 30){
				threeLED_state = LED1;
			}
			else{
				cnt = 0x00;
				threeLED_state = LED2;
			}
			break;
		
		case(LED2):
			if(cnt < 30){
				threeLED_state = LED2;
			}
			else{
				cnt = 0x00;
				threeLED_state = LED3;
			}
			break;
			
		case(LED3):
			if(cnt < 30){
				threeLED_state = LED3;
			}
			else{
				cnt = 0x00;
				threeLED_state = LED1;
			}
			break;
		
		default:
			threeLED_state = Init0;
			break;
	}
	
	switch(threeLED_state){		//State Actions
		case(Init0):
			break;
		
		case(LED1):
			threeLED = 0x01;
			cnt++;
			break;
		
		case(LED2):
			threeLED = 0x02;
			cnt++;
			break;
		
		case(LED3):
			threeLED=0x04;
			cnt++;
			break;
		
		default: 
			break;
	}
}

void SM_blinkingLED(){
	
	switch(blinkLED_state)	{		//State Transitions
		case(Init1):
			blinkLED_state = LED_on;
			break;
		
		case(LED_on):
			if(cnt0 < 100){
				blinkLED_state = LED_on;
			}
			else{
				cnt0 = 0x00;
				blinkLED_state = LED_off;
			}
			break;
		
		case(LED_off):
			if(cnt0 < 100){
				blinkLED_state = LED_off;
			}
			else{
				cnt0 = 0x00;
				blinkLED_state = LED_on;
			}
			break;
		
		default:
			blinkLED_state = Init1;
			break;
	}
	
	switch(blinkLED_state){		//State Actions
		case(Init1):
			cnt0 = 0x00;
			blinkingLED = 0x00;
			break;
		
		case(LED_on):
			blinkingLED = 0x08;
			cnt0++;
			break;
		
		case(LED_off):
			blinkingLED = 0x00;
			cnt0++;
			break;
		
		default:
			break;
	}
}

void SM_combineLED(){
	switch(combineLED_state)	{		//State Transitions
		case(Init2):
			combineLED_state = out;
			break;
		
		case(out):
			combineLED_state = out;
			break;
		
		default:
			combineLED_state = Init2;
			break;
	}
	
	switch(combineLED_state){		//State Actions
		case(Init2):
			combineLED = 0x00;
			break;
		
		case(out):
			combineLED = threeLED | blinkingLED;
			PORTB = combineLED;
			break;
		
		default:
			combineLED = 0x00;
			break;
	}
}




int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	TimerSet(time_count);
	TimerOn();

	threeLED_state = Init0;
	blinkLED_state = Init1;
	combineLED_state = Init2;
	
	while (1)
	{
		SM_threeLED();
		SM_blinkingLED();
		SM_combineLED();
		
		while(!TimerFlag){}
		TimerFlag = 0;
	}
}
