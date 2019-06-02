#ifndef LEVELTWO_H
#define LEVELTWO_H

#define F_CPU 11059200UL //defining crystal frequency
#include <util/delay.h>  //delay header
#include <string.h>
#include <stdlib.h>
#include <time.h>

unsigned char two_alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0' };

unsigned char LvlOneComplete;
unsigned char a = 0x00;
unsigned char b = 0x00;
unsigned char joystick2 = 0x00;
unsigned char key2[];
unsigned char key_LED2[];
unsigned char leveltwo[20] = "";
unsigned char next2 = 0x00;
unsigned char accept2 = 0x00;
unsigned char key_length2 = 0x00;
unsigned char temp2;
int HORIZONTAL2=141; //neutral value on x-axis
int HORIZONTALMOV2 =0;
int specialKey2;

unsigned char success2 = 0x00;
const unsigned char* failed2 = "Game Over!";
const unsigned char* successful2 = "Congratulations!";
const unsigned char levelSpeed2 = 20;
unsigned char successTimer2 = 0x00;
unsigned char failTimer2 = 0x00;


unsigned char word1_two[] = {'O', 'C', 'C', 'L', 'U', 'D', 'E', '\0'};
unsigned char word2_two[] = {'Q', 'U', 'I', 'B', 'B', 'L', 'E', '\0'};
unsigned char word3_two[] = {'A', 'R', 'R', 'A', 'N', 'T', '\0'};
unsigned char word4_two[] = {'F', 'O', 'M', 'E', 'N', 'T', '\0'};
unsigned char word5_two[] = {'R', 'E', 'C', 'R', 'E', 'A', 'N', 'C', 'Y', '\0'};

unsigned long word1_LED_two[] = { 0,0,0,0,0,0,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b01111110,0b10111101,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0,0,0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110,0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110,0,0,0,0,0,0,0,0,0,0 };
unsigned long word2_LED_two[] = { 0,0,0,0,0,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111,0,0,0b00111100,0b01111110,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b00111100,0b01111110,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011,0,0,0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110,0,0,0b01111110,0b11111111,0b11001111,0b11011111,0b11011011,0b11000011,0b11111111,0b01111110,0,0,0,0,0,0,0,0,0,0 };
unsigned long word3_LED_two[] = { 0,0,0,0,0,0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0,0,0,0,0,0,0,0 };
unsigned long word4_LED_two[] = { 0,0,0,0,0,0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11111111,0b11111111,0b01100000,0b01110000,0b01110000,0b01100000,0b11111111,0b11111111,0,0,0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110,0,0,0b11011000,0b11011000,0b11011000,0b11011000,0b11011000,0b11111111,0b11111111,0,0,0,0,0,0,0,0,0,0 };
unsigned long word5_LED_two[] = { 0,0,0,0,0,0,0,0b01000000,0b11100000,0b01110000,0b00111111,0b00111111,0b01110000,0b11100000,0b01000000,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0,0,0,0,0,0,0,0};
	

/*

int getRandomKey(){
	int num;
	num = rand() % 5;
	return num;
	
}

void append(unsigned char* s, unsigned char c) {
	int len = strlen(s);
	s[len] = c;
	s[len+1] = '\0';
}

unsigned char compare(unsigned char* user, unsigned char* game){
	unsigned char pass = 0x01;
	key_length2 = strlen(game);
	for(int x=0; x<key_length2; x++){
		if(user[x] != game[x]){
			pass = 0x00;
		}
	}
	return pass;
}

	
void levelTwoLEDisplay(){
	//unsigned char* Letters = buildWords(occlude);
	char PORT[8] = {1,2,4,8,16,32,64,128}; //pin values of a port 2^0,2^1,2^2……2^7
	specialKey2 = getRandomKey();
		
	if(specialKey2 == 0){
		for(int x=word_1LED_length_two; x >= 0; x--){
			for(int a=0; a < levelSpeed2; a++){
				for (int i=0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word1_LED_two[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
	}
	
	if(specialKey2 == 1){
		for(int x = word_2LED_length_two; x >= 0; x--){
			for(int a=0; a < levelSpeed2; a++){
				for (int i=0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word2_LED_two[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
	}
	
	if(specialKey2 == 2){
		for(int x = word_3LED_length_two; x >= 0; x--){
			for(int a=0; a < levelSpeed2; a++){
				for (int i=0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word3_LED_two[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
	}
	
	if(specialKey2 == 3){
		for(int x = word_4LED_length_two; x >= 0; x--){
			for(int a = 0; a < levelSpeed2; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word4_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
	}
	
	if(specialKey2 == 4) {
		for(int x = word_5LED_length_two; x >= 0; x--){
			for(int a=0; a < levelSpeed2; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word5_LED_two[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
	}
}

void ADC_init() {
	ADCSRA |=(1<<ADEN) |(1<ADPS2)|(1<ADPS1) |(1<<ADPS0);
	ADMUX |=(1<<REFS0);
}

int getJoystick(){
	ADMUX = 0x40;
	ADCSRA |=(1<<ADSC);//start ADC conversion
	while ( !(ADCSRA & (1<<ADIF)));//wait till ADC conversion	
	HORIZONTALMOV2 = ADC;//moving value
	ADC=0;//reset ADC register	
	
	return HORIZONTALMOV2;	
}
*/

enum levelTwo_states { two_wait, two_getKey, two_displayLED, two_displayLCD, two_check_string, two_debounce, two_enter, two_failed, two_success, two_scroll_up, two_scroll_down, two_complete};

int levelTwo(int state) {
	next2 = PINA & 0x10;
	accept2 = PINA & 0x20;
	//State machine transitions
	switch (state) {
		
		case two_wait:
			
			if (LvlOneComplete){    // Wait for button press
				LCD_Cursor(0);
				state = two_getKey;
				
			}
			else{
				state = two_wait;
			}
			break;
		
		case two_getKey:
			state = two_displayLED;
			break;
			

		case two_displayLED:
			state = two_displayLCD;
			break;
			
		case two_displayLCD:
			joystick = getJoystick();
			
			if(next2){
				state = two_debounce;
			}
			
			else if(joystick>(HORIZONTAL2+50)){
				if(a>=0 && a<26){
					state = two_scroll_up;
					
				}
				else{
					state = two_displayLCD;
				}
			}
			
			else if(joystick<(HORIZONTAL2-100)){
				if(a>=0 && a<26){
					state = two_scroll_down;
				}
				else{
					state = two_displayLCD;
				}
			}
			
			else if(accept2){
				temp2 = two_alphabet[a];
				append(leveltwo, temp2);
				state = two_check_string;
			}
			
			else{	
				state = two_displayLCD;
			}	
			break;
		
		case two_debounce:
			if(next2){
				state = two_debounce;
			}
			else{
				state = two_enter;
			}
			break;
		
		case two_enter:
			state = two_displayLCD;
			break;
			
		case two_check_string:
			if(specialKey2 == 0){
				success2 = compare(leveltwo, word1_two);
			}
			else if(specialKey2 == 1){
				success2 = compare(leveltwo, word2_two);
			}
			else if(specialKey2 == 2){
				success2 = compare(leveltwo, word3_two);
			}
			else if(specialKey2 == 3){
				success2 = compare(leveltwo, word4_two);
			}
			else {
				success2 = compare(leveltwo, word5_two);
			}
			
			if(success2){
				state = two_success;
			}
			else{
				state = two_failed;
			}
			break;
		
		case two_scroll_down:
			state = two_displayLCD;
			break;
		
		case two_scroll_up:
			state = two_displayLCD;
			break;
		
		case two_failed:
			if(failTimer2 < 100){
				state = two_failed;
			}
			else{
				state = two_complete;
			}
			break;

		case two_success:
			if(successTimer2 < 100){
				state = two_success;
			}
			else{
				state = two_complete;	
			}
			break;
		
		case two_complete:
			if(LvlOneComplete){
				state = two_complete;				
			}
			else{
				state = two_wait;
			}


		default:
			state = two_wait; // default: Initial state
			break;
	}

	//State machine actions
	switch (state) {
		case two_wait:	
			break;
		
		case two_getKey:
			specialKey2 = getRandomKey();
			break;

		case two_displayLED:
			LCD_ClearScreen();
			levelOneLEDisplay();
			break;

		case two_displayLCD:
			LCD_DisplayString(1, two_alphabet[a]);
			break;
			
		case two_debounce:
			break;
			
		case two_enter:
			temp2 = two_alphabet[a];
			append(leveltwo, temp2);
			b++;
			break;
		
		case two_scroll_down:
			if(a>0){
				a--;
			}
			break;
		
		case two_scroll_up:
			if(a<25){
				a++;
			}
			break;
			
		case two_check_string:
			LCD_ClearScreen();
			break;
			
		case two_failed:
			LCD_DisplayString(1, failed2);
			failTimer2++;
			break;
	
		case two_success:
			LCD_DisplayString(1, successful2);
			successTimer2++;
			break;
	
		case two_complete:
			break;
		
		default:
			state = two_wait; // default: Initial state
			break;
	}

	return state;
}



/*
unsigned char* buildWords(unsigned char* string){
	unsigned char* answer = (unsigned char*) malloc(sizeof(char)*256);
	
	const char A[] = {0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111}; //A
	const char B[] = {0,0,0b00111100,0b01111110,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111}; //B
	const char C[] = {0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100}; //C
	const char D[] = {0,0,0b01111110,0b10111101,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111}; //D
	const char E[] = {0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111}; //E
	const char F[] = {0,0,0b11011000,0b11011000,0b11011000,0b11011000,0b11011000,0b11111111,0b11111111}; //F
	const char G[] = {0,0,0b00011111,0b11011111,0b11011000,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111}; //G
	const char H[] = {0,0,0b11111111,0b11111111,0b00011000,0b00011000,0b00011000,0b11111111,0b11111111}; //H
	const char I[] = {0,0,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011}; //I
	const char J[] = {0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000011,0b11001111,0b11001111}; //J
	const char K[] = {0,0,0b11000011,0b11100111,0b01111110,0b00111100,0b00011000,0b11111111,0b11111111}; //K
	const char L[] = {0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111}; //L
	const char M[] = {0,0,0b11111111,0b11111111,0b01100000,0b01110000,0b01110000,0b01100000,0b11111111,0b11111111}; //M
	const char N[] = {0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111}; //N
	const char O[] = {0,0,0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110}; //O
	const char P[] = {0,0,0b01110000,0b11111000,0b11001100,0b11001100,0b11001100,0b11111111,0b11111111}; //P
	const char Q[] = {0,0,0b01111110,0b11111111,0b11001111,0b11011111,0b11011011,0b11000011,0b11111111,0b01111110}; //Q
	const char R[] = {0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111}; //R
	const char S[] = {0,0,0b11001110,0b11011111,0b11011011,0b11011011,0b11011011,0b11011011,0b11111011,0b01110011}; //S
	const char T[] = {0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000}; //T
	const char U[] = {0,0,0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110}; //U
	const char V[] = {0,0,0b11100000,0b11111100,0b00011110,0b00000011,0b00000011,0b00011110,0b11111100,0b11100000}; //V
	const char W[] = {0,0,0b11111110,0b11111111,0b00000011,0b11111111,0b11111111,0b00000011,0b11111111,0b11111110}; //W
	const char X[] = {0,0,0b01000010,0b11100111,0b01111110,0b00111100,0b00111100,0b01111110,0b11100111,0b01000010}; //X
	const char Y[] = {0,0,0b01000000,0b11100000,0b01110000,0b00111111,0b00111111,0b01110000,0b11100000,0b01000000}; //Y
	const char Z[] = {0,0,0b11000011,0b11100011,0b11110011,0b11111011,0b11011111,0b11001111,0b11000111,0b11000011}; //Z
	
	int length = strlen(string);
	int j = 0;
	for(int i = length; i>0; i--){
		switch(string[i]){
			/*
			case('A'): answer[j] = A; answer[j+1] = '\0'; j++; break;
			case('B'): answer[j] = B; answer[j+1] = '\0'; j++; break;
			case('C'): answer[j] = C; answer[j+1] = '\0'; j++; break;
			case('D'): answer[j] = D; answer[j+1] = '\0'; j++; break;
			case('E'): answer[j] = E; answer[j+1] = '\0'; j++; break;
			case('F'): answer[j] = F; answer[j+1] = '\0'; j++; break;
			case('G'): answer[j] = G; answer[j+1] = '\0'; j++; break;
			case('H'): answer[j] = H; answer[j+1] = '\0'; j++; break;
			case('I'): answer[j] = I; answer[j+1] = '\0'; j++; break;
			case('J'): answer[j] = J; answer[j+1] = '\0'; j++; break;
			case('K'): answer[j] = K; answer[j+1] = '\0'; j++; break;
			case('L'): answer[j] = L; answer[j+1] = '\0'; j++; break;
			case('M'): answer[j] = M; answer[j+1] = '\0'; j++; break;
			case('N'): answer[j] = N; answer[j+1] = '\0'; j++; break;
			case('O'): answer[j] = O; answer[j+1] = '\0'; j++; break;
			case('P'): answer[j] = P; answer[j+1] = '\0'; j++; break;
			case('Q'): answer[j] = Q; answer[j+1] = '\0'; j++; break;
			case('R'): answer[j] = R; answer[j+1] = '\0'; j++; break;
			case('S'): answer[j] = S; answer[j+1] = '\0'; j++; break;
			case('T'): answer[j] = T; answer[j+1] = '\0'; j++; break;
			case('U'): answer[j] = U; answer[j+1] = '\0'; j++; break;
			case('V'): answer[j] = V; answer[j+1] = '\0'; j++; break;
			case('W'): answer[j] = W; answer[j+1] = '\0'; j++; break;
			case('X'): answer[j] = X; answer[j+1] = '\0'; j++; break;
			case('Y'): answer[j] = Y; answer[j+1] = '\0'; j++; break;
			case('Z'): answer[j] = Z; answer[j+1] = '\0'; j++; break;
			case('\0'): answer[j] = '\0'; break;
			default: break;
			
			case('A'): strcat(answer, A); break;
			case('B'): strcat(answer, B); break;
			case('C'): strcat(answer, C); break;
			case('D'): strcat(answer, D); break;
			case('E'): strcat(answer, E); break;
			case('F'): strcat(answer, F); break;
			case('G'): strcat(answer, G); break;
			case('H'): strcat(answer, H); break;
			case('I'): strcat(answer, I); break;
			case('J'): strcat(answer, J); break;
			case('K'): strcat(answer, K); break;
			case('L'): strcat(answer, L); break;
			case('M'): strcat(answer, M); break;
			case('N'): strcat(answer, N); break;
			case('O'): strcat(answer, O); break;
			case('P'): strcat(answer, P); break;
			case('Q'): strcat(answer, Q); break;
			case('R'): strcat(answer, R); break;
			case('S'): strcat(answer, S); break;
			case('T'): strcat(answer, T); break;
			case('U'): strcat(answer, U); break;
			case('V'): strcat(answer, V); break;
			case('W'): strcat(answer, W); break;
			case('X'): strcat(answer, X); break;
			case('Y'): strcat(answer, Y); break;
			case('Z'): strcat(answer, Z); break;
			case('\0'): break;
			default: break;
		}
	}
	return answer;
}
*/

#endif