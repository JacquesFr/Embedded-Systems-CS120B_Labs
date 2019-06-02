#ifndef LEVELONE_H
#define LEVELONE_H

#define F_CPU 11059200UL //defining crystal frequency
#include <util/delay.h>  //delay header
#include <string.h>
#include <stdlib.h>
#include <time.h>


unsigned char continueGame;
unsigned char i = 0x00;
unsigned char j = 0x00;
unsigned char joystick = 0x00;
unsigned char key[];
unsigned char key_LED[];
unsigned char levelOne[20];
unsigned char next = 0x00;
unsigned char accept = 0x00;
unsigned char key_length = 0x00;
unsigned char temp;
unsigned char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0' };
int HORIZONTAL=141; //neutral value on x-axis
int HORIZONTALMOV =0;
int specialKey;

unsigned char success = 0x00;
const unsigned char* failed = "GAME OVER";
const unsigned char* successful = "LEVEL COMPLETE";
const unsigned char* nextLvlStr = "NEXT LEVEL...";
int levelSpeed = 15;
unsigned char successTimer = 0x00;
unsigned char failTimer = 0x00;
unsigned char one_nextLvlTimer = 0x00;
unsigned char currentLevel = 0;
unsigned char highScore = 0;
unsigned char displayCurr = 0x00;
unsigned char nextLevel = 0x00;
unsigned char levels[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '\0' };


unsigned char word1[] = {'O', 'C', 'C', 'L', 'U', 'D', 'E', '\0'};
unsigned char word2[] = {'Q', 'U', 'I', 'B', 'B', 'L', 'E', '\0'};
unsigned char word3[] = {'A', 'R', 'R', 'A', 'N', 'T', '\0'};
unsigned char word4[] = {'F', 'O', 'M', 'E', 'N', 'T', '\0'};
unsigned char word5[] = {'R', 'E', 'C', 'R', 'E', 'A', 'N', 'C', 'Y', '\0'};

unsigned char word1_LED[] = { 0,0,0,0,0,0,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b01111110,0b10111101,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0,0,0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110,0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110,0,0,0,0,0,0,0,0,0,0 };
unsigned char word2_LED[] = { 0,0,0,0,0,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111,0,0,0b00111100,0b01111110,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b00111100,0b01111110,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011,0,0,0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110,0,0,0b01111110,0b11111111,0b11001111,0b11011111,0b11011011,0b11000011,0b11111111,0b01111110,0,0,0,0,0,0,0,0,0,0 };
unsigned char word3_LED[] = { 0,0,0,0,0,0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0,0,0,0,0,0,0,0 };
unsigned char word4_LED[] = { 0,0,0,0,0,0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11111111,0b11111111,0b01100000,0b01110000,0b01110000,0b01100000,0b11111111,0b11111111,0,0,0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110,0,0,0b11011000,0b11011000,0b11011000,0b11011000,0b11011000,0b11111111,0b11111111,0,0,0,0,0,0,0,0,0,0 };
unsigned char word5_LED[] = { 0,0,0,0,0,0,0,0b01000000,0b11100000,0b01110000,0b00111111,0b00111111,0b01110000,0b11100000,0b01000000,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0,0,0,0,0,0,0,0};

int getRandomKey(){
	int num;
	num = rand();
	num = num % 4;
	return num;
	
}

void append(unsigned char* s, unsigned char c) {
	int len = strlen(s);
	s[len] = c;
	s[len+1] = '\0';
}

unsigned char compare(unsigned char* user, unsigned char* game){
	unsigned char pass = 0x01;
	key_length = strlen(game);
	for(int x=0; x<key_length; x++){
		if(user[x] != game[x]){
			pass = 0x00;
		}
	}
	return pass;
}

	
void levelOneLEDisplay(){
	//unsigned char* Letters = buildWords(occlude);
	char PORT[8] = {1,2,4,8,16,32,64,128}; //pin values of a port 2^0,2^1,2^2……2^7
	specialKey = getRandomKey();
		
	if(specialKey == 0){
		for(int x=75; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i=0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word1_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
	}
	
	if(specialKey == 1){
		for(int x = 75; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i=0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word2_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
	}
	
	if(specialKey == 2){
		for(int x = 75; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i=0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word3_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
	}
	
	if(specialKey == 3){
		for(int x = 75; x >= 0; x--){
			for(int a = 0; a < levelSpeed; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word4_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
	}
	
	if(specialKey == 4) {
		for(int x = 100; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word5_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
	}
	PORTB = 0x00;
	PORTC = 0x00;
}

void ADC_init() {
	ADCSRA |=(1<<ADEN) |(1<ADPS2)|(1<ADPS1) |(1<<ADPS0);
	ADMUX |=(1<<REFS0);
}

int getJoystick(){
	ADMUX = 0x40;
	ADCSRA |=(1<<ADSC);//start ADC conversion
	while ( !(ADCSRA & (1<<ADIF)));//wait till ADC conversion	
	HORIZONTALMOV = ADC;//moving value
	ADC=0;//reset ADC register	
	
	return HORIZONTALMOV;	
}

enum SM2_States { one_wait, one_getKey, one_displayLED, one_displayLCD, check_string, one_debounce, one_enter, one_failed, one_success, display_CL, next_level, one_reset, one_scroll_up, one_scroll_down };

int levelOneLED(int state) {
	next = PINA & 0x10;
	accept = PINA & 0x20;
	
	switch (state) {
		
		case one_wait:			
			if (continueGame){    // Wait for button press
				state = one_getKey;
			}
			else{
				state = one_wait;
			}
			break;
		
		case one_getKey:
			state = one_displayLED;
			break;
			

		case one_displayLED:
			state = one_displayLCD;
			break;
			
		case one_displayLCD:
			joystick = getJoystick();
			
			if(next){
				state = one_debounce;
			}
			
			else if(joystick>(HORIZONTAL+50)){
				if(i>=0 && i<26){
					state = one_scroll_up;
					
				}
				else{
					state = one_displayLCD;
				}
			}
			
			else if(joystick<(HORIZONTAL-100)){
				if(i>=0 && i<26){
					state = one_scroll_down;
				}
				else{
					state = one_displayLCD;
				}
			}
			
			else if(accept){
				temp = alphabet[i];
				append(levelOne, temp);
				state = check_string;
			}
			
			else{	
				state = one_displayLCD;
			}	
			break;
		
		case one_debounce:
			if(next){
				state = one_debounce;
			}
			else{
				state = one_enter;
			}
			break;
		
		case one_enter:
			state = one_displayLCD;
			break;
			
		case check_string:
			if(specialKey == 0){
				success = compare(levelOne, word1);
			}
			else if(specialKey == 1){
				success = compare(levelOne, word2);
			}
			else if(specialKey == 2){
				success = compare(levelOne, word3);
			}
			else if(specialKey == 3){
				success = compare(levelOne, word4);
			}
			else {
				success = compare(levelOne, word5);
			}
			
			if(success){
				state = one_success;
			}
			else{
				state = one_failed;
			}
			break;
		
		case one_scroll_down:
			state = one_displayLCD;
			break;
		
		case one_scroll_up:
			state = one_displayLCD;
			break;
		
		case one_failed:
			if(failTimer < 50){
				state = one_failed;
			}
			else{
				LCD_ClearScreen();
				state = one_reset;
			}
			break;

		case one_success:
			if(successTimer < 50){
				state = one_success;
			}
			else{
				LCD_ClearScreen();
				currentLevel = currentLevel + 1;
				highScore = currentLevel;
				state = display_CL;	
			}
			break;
		
		case display_CL:
			if(displayCurr < 50){
				state = display_CL;
			}
			else{
				state = next_level;
			}
			break;
		
		case next_level:
			if(nextLevel < 30){
				state = next_level;
			}
			else{
				state = one_reset;
			}
			break;
			
		case one_reset:
			if(success){
				continueGame = 0x01;
				state = one_wait;
			}
			else{
				continueGame = 0x00;
				state = one_wait;
			}
			break;

		default:
			state = one_wait; // default: Initial state
			break;
	}

	//State machine actions
	switch (state) {
		case one_wait:
			
			break;
		
		case one_getKey:
			specialKey = getRandomKey();
			break;

		case one_displayLED:
			LCD_ClearScreen();
			levelOneLEDisplay();
			break;

		case one_displayLCD:
			LCD_Cursor(j+1);
			LCD_WriteData(alphabet[i]);
			break;
			
		case one_debounce:
			break;
			
		case one_enter:
			temp = alphabet[i];
			append(levelOne, temp);
			j++;
			break;
		
		case one_scroll_down:
			if(i>0){
				i--;
			}
			break;
		
		case one_scroll_up:
			if(i<25){
				i++;
			}
			break;
			
		case check_string:
			LCD_ClearScreen();
			break;
			
		case one_failed:
			LCD_DisplayString(1, failed);
			failTimer++;
			success = 0x00;
			break;
	
		case one_success:
			LCD_DisplayString(1, successful);
			successTimer++;
			continueGame = 0x01;
			success = 0x01;
			break;
			
		case display_CL:
			LCD_DisplayString(1, "Next Level: ");
			LCD_Cursor(13);
			LCD_WriteData(levels[currentLevel]);
			displayCurr++;
			break;
		
		case next_level:
			LCD_DisplayString(1, "High Score: ");
			LCD_Cursor(13);
			LCD_WriteData(levels[highScore]);
			nextLevel++;
			break;
			
		case one_reset:
			i = 0x00;
			j = 0x00;
			LCD_ClearScreen();
			LCD_Cursor(0);		
			levelOne[0] = 0;
			key[0] = 0;
			key_LED[0] = 0;
			successTimer = 0x00;
			failTimer = 0x00;
			nextLevel = 0x00;
			levelSpeed--;
			displayCurr = 0x00;
			break;
		
		default:
			state = one_wait; // default: Initial state
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