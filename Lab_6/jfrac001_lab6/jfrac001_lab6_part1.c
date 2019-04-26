/*
 * Jacques Fracchia
 * Partner: Silvino
 * jfrac001@ucr.edu
 * Created: 4/22/2019 10:49:07 PM
 * Author : jacques
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

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

enum state {Init, LED_1, LED_2, LED_3} state;
	
void tick(){
	
	switch(state)	{		//State Transitions
		
		case(Init):
			state = LED_1;
		break;
		
		case(LED_1):
			if(!TimerFlag){
				state = LED_1;
			}
			else{
				TimerFlag = 0;
				state = LED_2;
			}
		break;
		
		case(LED_2):
			if(!TimerFlag){
				state = LED_2;
			}
			else{
				TimerFlag = 0;
				state = LED_3;
			}
		break;
		
		case(LED_3):
			if(!TimerFlag){
				state = LED_3;
			}
			else{
				TimerFlag = 0;
				state = LED_1;
			}
		break;
		
		default:
			state = Init;
		break;
	}
	
	switch(state){		//State Actions
		case(Init):
			lights = 0x00;
			TimerFlag = 0;
		break;
		
		case(LED_1):
			lights = 0x01;
			PORTB = lights;
		break;

		case(LED_2):
			lights = 0x02;
			PORTB = lights;
		break;
		
		case(LED_3):
			lights = 0x04;
			PORTB = lights;
		break;
		
		
		default:
			lights = 0x07;
			PORTB = lights;
		break;
	}
}

int main()
{
	DDRB = 0x07; // Set port B to output
	PORTB = 0x00; // Init port B to 0s
	TimerSet(time_count);
	TimerOn();

	while(1) {
		
		tick();
		
	}
	
	return 0;
}
