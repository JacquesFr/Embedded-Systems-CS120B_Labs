/*
 * jfrac001_lab11_part3.c
 *
 * Created: 5/19/2019 5:59:28 PM
 * Author : jacqu
 */ 

#include <avr/interrupt.h>
#include <stdio.h>
#include <io.c>
#include <io.h>
#include <timer.h>
#include <bit.h>
#include <scheduler.h>

unsigned char val1 = 0x1F;
unsigned char temp = 0;
unsigned char press;



enum States{init, pressed, display} state;
	
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

	return('\0'); // default value

}

int tick(int state){
	press = GetKeypadKey();
	

	switch(state){
		default:
			state = init;
			break;

		case init:
			if (press == 0x00){
				state = init;
			}
			else{
				state = pressed;
			}
			break;

		case pressed:
			if (press){
				state = pressed;
			}
			else{
				state = display;
			}
			break;
		
		case display:
			state = init;
			break;
	}

	switch(state){
		
		case init:
			break;

		case pressed:
			break;
		
		case display:
			switch(press){}
				
				LCD_ClearScreen();

				// All 5 LEDs on
				case '\0': PORTB = 0x1F; break;
				// hex equivalent
				case '1': PORTB = 0x01; val1 = 1; LCD_Cursor(1); LCD_WriteData(press + '0'); break;
				case '2': PORTB = 0x02; val1 = 2; LCD_Cursor(1); LCD_WriteData(press + '0'); break;
				case '3': PORTB = 0x03; val1 = 3; LCD_Cursor(1); LCD_WriteData(press + '0'); break;
				case '4': PORTB = 0x04; val1 = 4; LCD_Cursor(1); LCD_WriteData(press + '0'); break;
				case '5': PORTB = 0x05; val1 = 5; LCD_Cursor(1); LCD_WriteData(press + '0'); break;
				case '6': PORTB = 0x06; val1 = 6; LCD_Cursor(1); LCD_WriteData(press + '0'); break;
				case '7': PORTB = 0x07; val1 = 7; LCD_Cursor(1); LCD_WriteData(press + '0'); break;
				case '8': PORTB = 0x08; val1 = 8; LCD_Cursor(1); LCD_WriteData(press + '0'); break;
				case '9': PORTB = 0x09; val1 = 9; LCD_Cursor(1); LCD_WriteData(press + '0'); break;
				case '0': PORTB = 0x00; val1 = 0; LCD_Cursor(1); LCD_WriteData(press + '0'); break;


				// . . . ***** FINISH *****
				case 'A': PORTB = 0x0A; val1 = 65; LCD_Cursor(1); LCD_WriteData(val1); break;
				case 'B': PORTB = 0x0B; val1 = 66; LCD_Cursor(1); LCD_WriteData(val1); break;
				case 'C': PORTB = 0x0C; val1 = 67; LCD_Cursor(1); LCD_WriteData(val1); break;
				case 'D': PORTB = 0x0D; val1 = 68; LCD_Cursor(1); LCD_WriteData(val1); break;
				case '*': PORTB = 0x0E; val1 = 42; LCD_Cursor(1); LCD_WriteData(val1); break;
				case '#': PORTB = 0x0F; val1 = 35; LCD_Cursor(1); LCD_WriteData(val1); break;
				// Should never occur. Middle LED off.
				default: PORTB = 0x1B; break;
			}
			

		default:
			//val = 0x1F;
			break;


	}
}




	return state;
}



int main(void)
{
	// PORTB set to output, outputs init 0s
	DDRB = 0xFF;
	PORTB = 0x00;
	// PC7..4 outputs init 0s, PC3..0 inputs init 1s
	DDRC = 0x00;
	PORTC = 0xFF;

	DDRD = 0xFF;
	PORTD = 0x00;

	DDRA = 0xFF;
	PORTA = 0x00;

	static task task1;

	task *tasks[] = {&task1};

	unsigned long int task_period = 300;
	unsigned long int task_tick = 300;
	const unsigned short numTasks = sizeof(task)/sizeof(task*);



	task1.state = -1;
	task1.period = task_period;
	task1.elapsedTime = task_tick;
	task1.TickFct = &tick;

	TimerSet(task_tick);
	TimerOn();
	LCD_init();

	while (1)
	{


		// Scheduler code
		for (unsigned short i = 0; i < numTasks; i++ ) {
			// Task is ready to tick
			if ( tasks[i]->elapsedTime == tasks[i]->period ) {
				// Setting next state for task
				tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
				// Reset elapsed time for next tick.
				tasks[i]->elapsedTime = 0;
			}
			tasks[i]->elapsedTime += 1;
		}
		//val = GetKeypadKey();

		while(!TimerFlag){};
		TimerFlag = 0;


	}
}

