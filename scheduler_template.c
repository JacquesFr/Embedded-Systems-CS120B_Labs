/*
 * Jfrac001_lab11_part1.c
 *
 * Created: 5/13/2019 2:51:39 PM
 * Author : jacqu
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <bit.h>
#include <timer.h>
#include <stdio.h>
#include "io.c"

//--------Find GCD function --------------------------------------------------
unsigned long int findGCD(unsigned long int a, unsigned long int b)
{
    unsigned long int c;
    while(1){
        c = a%b;
        if(c==0){return b;}
        a = b;
		b = c;
    }
    return 0;
}
//--------End find GCD function ----------------------------------------------

//--------Task scheduler data structure---------------------------------------
// Struct for Tasks represent a running process in our simple real-time operating system.
typedef struct _task {
    /*Tasks should have members that include: state, period,
        a measurement of elapsed time, and a function pointer.*/
    signed char state; //Task's current state
    unsigned long int period; //Task period
    unsigned long int elapsedTime; //Time elapsed since last task tick
    int (*TickFct)(int); //Task tick function
} task;

//--------End Task scheduler data structure-----------------------------------
unsigned char GetKeypadKey() {

	PORTC = 0xEF; // Enable col 4 with 0, disable others with 1�s
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	if (GetBit(PINC,0)==0) { return('1'); }
	if (GetBit(PINC,1)==0) { return('4'); }
	if (GetBit(PINC,2)==0) { return('7'); }
	if (GetBit(PINC,3)==0) { return('*'); }

	// Check keys in col 2
	PORTC = 0xDF; // Enable col 5 with 0, disable others with 1�s
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	if (GetBit(PINC,0)==0) { return('2'); }
	if (GetBit(PINC,1)==0) { return('5'); }
	if (GetBit(PINC,2)==0) { return('8'); }
	if (GetBit(PINC,3)==0) { return('0'); }
	// ... *****FINISH*****

	// Check keys in col 3
	PORTC = 0xBF; // Enable col 6 with 0, disable others with 1�s
	asm("nop"); // add a delay to allow PORTC to stabilize before checking
	// ... *****FINISH*****
	if (GetBit(PINC,0)==0) { return('3'); }
	if (GetBit(PINC,1)==0) { return('6'); }
	if (GetBit(PINC,2)==0) { return('9'); }
	if (GetBit(PINC,3)==0) { return('#'); }

	// Check keys in col 4
	// ... *****FINISH*****
	PORTC = 0x7F; // Enable col 6 with 0, disable others with 1�s
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

void KeypadTick(){
	unsigned char x;
	x = GetKeypadKey();
	switch (x) {
		case '\0': PORTB = 0x1F; break; // All 5 LEDs on
		case '1': PORTB = 0x01; break; // hex equivalent
		case '2': PORTB = 0x02; break;
		case '3': PORTB = 0x03; break;
		case '4': PORTB = 0x04; break;
		case '5': PORTB = 0x05; break;
		case '6': PORTB = 0x06; break;
		case '7': PORTB = 0x07; break;
		case '8': PORTB = 0x08; break;
		case '9': PORTB = 0x09; break;
		case 'A': PORTB = 0x0A; break;
		case 'B': PORTB = 0x0B; break;
		case 'C': PORTB = 0x0C; break;
		case 'D': PORTB = 0x0D; break;
		case '*': PORTB = 0x0E; break;
		case '0': PORTB = 0x00; break;
		case '#': PORTB = 0x0F; break;
		default: PORTB = 0x1B; break; // Should never occur. Middle LED off.
	}
}


//--------Shared Variables----------------------------------------------------
unsigned char SM2_output = 0x00;
unsigned char SM3_output = 0x00;
unsigned char pause = 0;

//--------End Shared Variables------------------------------------------------

//--------User defined FSMs---------------------------------------------------
//Enumeration of states.
enum SM1_States { SM1_wait, SM1_press, SM1_release };

// Monitors button connected to PA0. 
// When button is pressed, shared variable "pause" is toggled.
int SMTick1(int state) {

    // Local Variables
    unsigned char press = ~PINA & 0x01;

    //State machine transitions
    switch (state) {
    
	case SM1_wait:     
		if (press == 0x01){    // Wait for button press
			state = SM1_press;
		}
		break;

    case SM1_press:    
		state = SM1_release;
		break;

    case SM1_release:    
		if (press == 0x00){    // Wait for button release
			state = SM1_wait;
		}
		break;

    default:        
		state = SM1_wait; // default: Initial state
        break;
    }

    //State machine actions
    switch(state) {
		case SM1_wait:    
			break;

		case SM1_press:    
			pause = (pause == 0) ? 1 : 0; // toggle pause
			break;

		case SM1_release:    
			break;

		default:        
			break;
		}

    return state;
}

//Enumeration of states.
enum SM2_States { SM2_wait, SM2_blink };

// If paused: Do NOT toggle LED connected to PB0
// If unpaused: toggle LED connected to PB0
int SMTick2(int state) {

    //State machine transitions
    switch (state) {
    case SM2_wait:    
		if (pause == 0) {    // If unpaused, go to blink state
			state = SM2_blink;
		}
		break;

    case SM2_blink:    
		if (pause == 1) {    // If paused, go to wait state
			state = SM2_wait;
		}
		break;

    default:        
		state = SM2_wait;
		break;
    }

    //State machine actions
    switch(state) {
		case SM2_wait:    
			break;

		case SM2_blink:    
			SM2_output = (SM2_output == 0x00) ? 0x01 : 0x00; //toggle LED
			break;

		default:        
			break;
    }

    return state;
}

//Enumeration of states.
enum SM3_States { SM3_wait, SM3_blink };

// If paused: Do NOT toggle LED connected to PB1
// If unpaused: toggle LED connected to PB1
int SMTick3(int state) {
    //State machine transitions
    switch (state) {
    case SM3_wait:    
		if (pause == 0) {    // If unpaused, go to blink state
			state = SM3_blink;
		}
		break;

    case SM3_blink:    
		if (pause == 1) {    // If paused, go to wait state
			state = SM3_wait;
		}
		break;

    default:        
		state = SM3_wait;
        break;
    }

    //State machine actions
    switch(state) {
    case SM3_wait:    
		break;

    case SM3_blink:    
		SM3_output = (SM3_output == 0x00) ? 0x02 : 0x00; //toggle LED
        break;

    default:        
		break;
    }

    return state;
}


//Enumeration of states.
enum SM4_States { SM4_display };

// Combine blinking LED outputs from SM2 and SM3, and output on PORTB
int SMTick4(int state) {
    // Local Variables

    unsigned char output;

    //State machine transitions
    switch (state) {
    case SM4_display:    
		break;

    default:        
		state = SM4_display;
        break;
    }

    //State machine actions
    switch(state) {
    case SM4_display:    
		output = SM2_output | SM3_output; // write shared outputs
        break;

    default:        
		break;
    }

    PORTB = output;    // Write combined, shared output variables to PORTB

    return state;
}

// --------END User defined FSMs-----------------------------------------------

// Implement scheduler code from PES.
int main()
{
// Set Data Direction Registers
// Buttons PORTA[0-7], set AVR PORTA to pull down logic
DDRA = 0x00; PORTA = 0xFF;
DDRB = 0xFF; PORTB = 0x00;
// . . . etc

// Period for the tasks
unsigned long int SMTick1_calc = 50;
unsigned long int SMTick2_calc = 500;
unsigned long int SMTick3_calc = 1000;
unsigned long int SMTick4_calc = 10;

//Calculating GCD
unsigned long int tmpGCD = 1;
tmpGCD = findGCD(SMTick1_calc, SMTick2_calc);
tmpGCD = findGCD(tmpGCD, SMTick3_calc);
tmpGCD = findGCD(tmpGCD, SMTick4_calc);

//Greatest common divisor for all tasks or smallest time unit for tasks.
unsigned long int GCD = tmpGCD;

//Recalculate GCD periods for scheduler
unsigned long int SMTick1_period = SMTick1_calc/GCD;
unsigned long int SMTick2_period = SMTick2_calc/GCD;
unsigned long int SMTick3_period = SMTick3_calc/GCD;
unsigned long int SMTick4_period = SMTick4_calc/GCD;

//Declare an array of tasks 
static task task1, task2, task3, task4;
task *tasks[] = { &task1, &task2, &task3, &task4 };
const unsigned short numTasks = sizeof(tasks)/sizeof(task*);

// Task 1
task1.state = -1;//Task initial state.
task1.period = SMTick1_period;//Task Period.
task1.elapsedTime = SMTick1_period;//Task current elapsed time.
task1.TickFct = &SMTick1;//Function pointer for the tick.

// Task 2
task2.state = -1;//Task initial state.
task2.period = SMTick2_period;//Task Period.
task2.elapsedTime = SMTick2_period;//Task current elapsed time.
task2.TickFct = &SMTick2;//Function pointer for the tick.

// Task 3
task3.state = -1;//Task initial state.
task3.period = SMTick3_period;//Task Period.
task3.elapsedTime = SMTick3_period; // Task current elasped time.
task3.TickFct = &SMTick3; // Function pointer for the tick.

// Task 4
task4.state = -1;//Task initial state.
task4.period = SMTick4_period;//Task Period.
task4.elapsedTime = SMTick4_period; // Task current elasped time.
task4.TickFct = &SMTick4; // Function pointer for the tick.

// Set the timer and turn it on
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


