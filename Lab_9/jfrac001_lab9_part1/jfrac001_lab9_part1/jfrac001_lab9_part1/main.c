/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * Lab 9 part 1
 */ 

#include <avr/io.h>

unsigned char button = 0x00;
unsigned short c_freq = 261.63;
unsigned short d_freq = 293.66;
unsigned short e_freq = 329.63;

enum states {Init, wait, C, D, E}state;
// 0.954 hz is lowest frequency possible with this function,
// based on settings in PWM_on()
// Passing in 0 as the frequency will stop the speaker from generating sound
void set_PWM(double frequency) {
	static double current_frequency; // Keeps track of the currently set frequency
	// Will only update the registers when the frequency changes, otherwise allows
	// music to play uninterrupted.
	if (frequency != current_frequency) {
		if (!frequency) { TCCR3B &= 0x08; } //stops timer/counter
		else { TCCR3B |= 0x03; } // resumes/continues timer/counter
		
		// prevents OCR3A from overflowing, using prescaler 64
		// 0.954 is smallest frequency that will not result in overflow
		if (frequency < 0.954) { OCR3A = (int)0xFFFF; }
		
		// prevents OCR0A from underflowing, using prescaler 64					// 31250 is largest frequency that will not result in underflow
		else if (frequency > 31250) { OCR3A = 0x0000; }
		
		// set OCR3A based on desired frequency
		else { OCR3A = (short)(8000000 / (128 * frequency)) - 1; }

		TCNT0 = 0; // resets counter
		current_frequency = frequency; // Updates the current frequency
	}
}

void PWM_on() {
	TCCR3A = (1 << COM0A0);
	// COM3A0: Toggle PB3 on compare match between counter and OCR0A
	TCCR3B = (1 << WGM02) | (1 << CS01) | (1 << CS00);
	// WGM02: When counter (TCNT0) matches OCR0A, reset counter
	// CS01 & CS30: Set a prescaler of 64
	set_PWM(0);
}

void PWM_off() {
	TCCR3A = 0x00;
	TCCR3B = 0x00;
}

void tick(){
	switch(state){
		case Init:		//transitions
			state = wait;
			break;
		
		case wait:
			if(button == 0x01){
				state = C;
			}
			
			else if(button == 0x02){
				state = D;
			}
			
			else if(button == 0x04){
				state = E; 
			}
			
			else{
				state = wait;
			}
			
			break;
			
		case C:
			if(button == 0x01){
				state = C;
			}
			else{
				state = wait;
			}
			break;
		case D:
			if(button == 0x02){
				state = D;
			}
			else{
				state = wait;
			}
			break;
		case E:
			if(button == 0x04){
				state = E;
			}
			else{
				state = wait;
			}
			break;
			
		default:
			state = Init;
			break;
		}
		
		switch(state){
			case Init:
				set_PWM(0);
				break;
			
			case wait:
				set_PWM(0);
				break;
			
			case C:
				set_PWM(c_freq);
				break;
			
			case D:
				set_PWM(d_freq);
				break;
			
			case E:
				set_PWM(e_freq);
				break;
			
			default:
				set_PWM(0);
				break;	
		}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	state = Init;
	PWM_on();
	set_PWM(0);
	
    /* Replace with your application code */
    while (1) 
    {
		button = PINA & 0x07;
		tick();
		
    }
}

