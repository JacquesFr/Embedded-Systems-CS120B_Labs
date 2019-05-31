/*
 * Jfrac001_lab11_part1.c
 *
 * Created: 5/13/2019 2:51:39 PM
 * Author : jacqu
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "scheduler.h"
#include "bit.h"
#include "timer.h"
#include <stdio.h>
#include "io.c"
//#include "keypad.h"



unsigned char LED;

unsigned char GetKeypadKey() {

	PORTC = 0xEF; // Enable col 4 with 0, disable others with 1’s
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	if (GetBit(PINC,0)==0) { return('1'); }
	if (GetBit(PINC,1)==0) { return('4'); }
	if (GetBit(PINC,2)==0) { return('7'); }
	if (GetBit(PINC,3)==0) { return('*'); }

	// Check keys in col 2
	PORTC = 0xDF; // Enable col 5 with 0, disable others with 1’s
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	if (GetBit(PINC,0)==0) { return('2'); }
	if (GetBit(PINC,1)==0) { return('5'); }
	if (GetBit(PINC,2)==0) { return('8'); }
	if (GetBit(PINC,3)==0) { return('0'); }
	// ... *****FINISH*****

	// Check keys in col 3
	PORTC = 0xBF; // Enable col 6 with 0, disable others with 1’s
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	// ... *****FINISH*****
	if (GetBit(PINC,0)==0) { return('3'); }
	if (GetBit(PINC,1)==0) { return('6'); }
	if (GetBit(PINC,2)==0) { return('9'); }
	if (GetBit(PINC,3)==0) { return('#'); }

	// Check keys in col 4
	// ... *****FINISH*****
	PORTC = 0x7F; // Enable col 6 with 0, disable others with 1’s
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	// ... *****FINISH*****
	if (GetBit(PINC,0)==0) { return('A'); }
	if (GetBit(PINC,1)==0) { return('B'); }
	if (GetBit(PINC,2)==0) { return('C'); }
	if (GetBit(PINC,3)==0) { return('D'); }

	// Check keys in col 4
	// ... *****FINISH*****

	return('\0'); // default value
}

unsigned char KeypadTick(){
	unsigned char x;
	x = GetKeypadKey();
	switch (x) {
		case '\0': LED = 0x1F; break; // All 5 LEDs on
		case '1': LED = 0x01; break; // hex equivalent
		case '2': LED = 0x02; break;
		case '3': LED = 0x03; break;
		case '4': LED = 0x04; break;
		case '5': LED = 0x05; break;
		case '6': LED = 0x06; break;
		case '7': LED = 0x07; break;
		case '8': LED = 0x08; break;
		case '9': LED = 0x09; break;
		case 'A': LED = 0x0A; break;
		case 'B': LED = 0x0B; break;
		case 'C': LED = 0x0C; break;
		case 'D': LED = 0x0D; break;
		case '*': LED = 0x0E; break;
		case '0': LED = 0x00; break;
		case '#': LED = 0x0F; break;
		default: LED = 0x1B; break; // Should never occur. Middle LED off.
	}
	return LED;
}

enum States{Init, Keypad_LED} state;
unsigned char key = 0x00;
	
int TickFct_KeyLED(int state){
	
	switch(state){ //Transitions
		case Init:
			state = Keypad_LED;
			break;
		
		case Keypad_LED:
			state = Keypad_LED;
			break;
		
		default:
			PORTB = key;
			break;
	}
	
	switch(state){ //Actions
		case Init:
			key = 0x00;
			break;	
		
		case Keypad_LED:
			key = KeypadTick();
			PORTB = key & 0xFF;
			break;
			
		default:
			PORTB = key;
			break;
	}	
	return state;
}; 
	
int main(){

	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0xFF;
// Set the timer and turn it on
	unsigned long int TickFct_KeyLED_period = 100;
	unsigned long int tmpGCD = 1;
	tmpGCD = findGCD(TickFct_KeyLED_period, TickFct_KeyLED_period);
	
	unsigned long int GCD = tmpGCD;
	
	unsigned long int KeyLED_period = TickFct_KeyLED_period/GCD;
	
	static task task1;
	task *tasks[] = { &task1};
	const unsigned short numTasks = sizeof(tasks)/sizeof(task*);
	
	task1.state = 0;
	task1.period = KeyLED_period;
	task1.elapsedTime = KeyLED_period;
	task1.TickFct = &TickFct_KeyLED;
	
	//state = TickFct_KeyLED(state);

	TimerSet(GCD);
	TimerOn();

	unsigned short i; // Scheduler for-loop iterator
	while(1) {
		// Scheduler code
	
		for ( i = 0; i < numTasks; i++ ) {
			// Task is ready to tick
			if ( tasks[i]->elapsedTime == tasks[i]->period ) {
				// Setting next state for task
				tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
				// Reset the elapsed time for next tick.
				tasks[i]->elapsedTime = 0;
			}
			tasks[i]->elapsedTime += 1;
		}
		while(!TimerFlag);
		TimerFlag = 0;
	}

	// Error: Program should not exit!
	return 0;
}


