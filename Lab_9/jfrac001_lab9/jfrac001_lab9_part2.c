/*
 * Jacques Fracchia
 * jfrac001@ucr.edu
 * lab9 part 2
 */ 

#include <avr/io.h>


#define  c4  261.63
#define  d4  293.66
#define  e4  329.63
#define  f4  349.23
#define  g4  392.00
#define  a4  440.00
#define  b4  493.88
#define  c5  523.25

double scale[8] = {c4, d4, e4, f4, g4, a4, b4, c5};
unsigned char button = 0x00;
unsigned cnt = 0x00;

enum states {Init, wait, higher_press, lower_press, higher, lower}state;
	
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
				state = higher_press;
			}
			
			else if(button == 0x02){
				state = lower_press;
			}
			else{
				state = wait;
			}
			
			break;
			
		case higher_press:
			if(button == 0x01){
				state = higher_press;
			}
			else{
				state = higher;
			}
			break;
			
		case higher:
			state = wait;
			break;
			
		case lower_press:
			if(button == 0x02){
				state = lower_press;
			}
			else{
				state = lower;
			}
			break;
			
		case lower:
			state = wait;
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
				set_PWM(scale[cnt]);
				break;
			
			case higher_press:
				set_PWM(scale[cnt]);
				break;
			
			case higher:
				if(cnt < 7){
					cnt++;
				}
				set_PWM(scale[cnt]);
				break;
			
			case lower_press:
				set_PWM(scale[cnt]);
				break;
				
			case lower:
				if(cnt > 0){
					cnt--;
				}
				set_PWM(scale[cnt]);
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
	set_PWM(scale[cnt]);
	
    /* Replace with your application code */
    while (1) 
    {
		button = PINA & 0x07;
		tick();
		
    }
}