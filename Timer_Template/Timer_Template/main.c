/*
 * Timer_Template.c
 *
 * Created: 4/26/2019 12:57:37 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>
#include "io.c"
#include <time.h>
#include <stdio.h>

volatile unsigned char TimerFlag = 0; // TimerISR() sets this to 1. C programmer should clear to 0.



// Internal variables for mapping AVR's ISR to our cleaner TimerISR model.

unsigned long _avr_timer_M = 1; // Start count from here, down to 0. Default 1 ms.

unsigned long _avr_timer_cntcurr = 0; // Current internal count of 1ms ticks



unsigned char lights = 0x00;

unsigned int time_count = 1000;



void TimerOn() {

	// AVR timer/counter controller register TCCR1

	TCCR1B = 0x0B;// bit3 = 0: CTC mode (clear timer on compare)

	// bit2bit1bit0=011: pre-scaler /64

	// 00001011: 0x0B

	// SO, 8 MHz clock or 8,000,000 /64 = 125,000 ticks/s

	// Thus, TCNT1 register will count at 125,000 ticks/s



	// AVR output compare register OCR1A.

	OCR1A = 125;    // Timer interrupt will be generated when TCNT1==OCR1A

	// We want a 1 ms tick. 0.001 s * 125,000 ticks/s = 125

	// So when TCNT1 register equals 125,

	// 1 ms has passed. Thus, we compare to 125.

	// AVR timer interrupt mask register

	TIMSK1 = 0x02; // bit1: OCIE1A -- enables compare match interrupt



	//Initialize avr counter

	TCNT1=0;



	_avr_timer_cntcurr = _avr_timer_M;

	// TimerISR will be called every _avr_timer_cntcurr milliseconds



	//Enable global interrupts

	SREG |= 0x80; // 0x80: 1000000

}



void TimerOff() {

	TCCR1B = 0x00; // bit3bit1bit0=000: timer off

}



void TimerISR() {

	TimerFlag = 1;

}



// In our approach, the C programmer does not touch this ISR, but rather TimerISR()

ISR(TIMER1_COMPA_vect) {

	// CPU automatically calls when TCNT1 == OCR1 (every 1 ms per TimerOn settings)

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

enum state {Init} state;

void tick(){
	
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


int main(void)
{
	DDRA = 0x00; PINA = 0xFF;
	DDRB = 0xFF; PINB = 0x00;
	TimerSet(time_count);
	TimerOn();

	state = Init;
	
	while (1)
	{
		tick();
		while(!TimerFlag){}
		TimerFlag = 0;
	}
}


