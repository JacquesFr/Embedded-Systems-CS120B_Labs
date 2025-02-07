#ifndef LEVELFUNCTIONS_H
#define LEVELFUNCTIONS_H

/*
 * Jacques Fracchia
 * Level Functions
*/

//Level Variables
unsigned char sqr0[8] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char sqr1[8] = {0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
unsigned char sqr2[8] = {0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00};
unsigned char sqr3[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF};
unsigned char sqr4[8] = {0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00};
unsigned char sqr5[8] = {0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00};
unsigned char sqr6[8] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	
unsigned char word1_LED[] = { 0,0,0,0,0,0,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b01111110,0b10111101,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0,0,0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110,0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110,0,0,0,0,0,0,0,0,0,0 };
unsigned char word2_LED[] = { 0,0,0,0,0,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111,0,0,0b00111100,0b01111110,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b00111100,0b01111110,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011,0,0,0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110,0,0,0b01111110,0b11111111,0b11001111,0b11011111,0b11011011,0b11000011,0b11111111,0b01111110,0,0,0,0,0,0,0,0,0,0 };
unsigned char word3_LED[] = { 0,0,0,0,0,0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0,0,0,0,0,0,0,0 };
unsigned char word5_LED[] = { 0,0,0,0,0,0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11111111,0b11111111,0b01100000,0b01110000,0b01110000,0b01100000,0b11111111,0b11111111,0,0,0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110,0,0,0b11011000,0b11011000,0b11011000,0b11011000,0b11011000,0b11111111,0b11111111,0,0,0,0,0,0,0,0,0,0 };
unsigned char word4_LED[] = { 0,0,0,0,0,0,0,0b01000000,0b11100000,0b01110000,0b00111111,0b00111111,0b01110000,0b11100000,0b01000000,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0,0,0,0,0,0,0,0};
unsigned char word6_LED[] = { 0,0,0,0,0,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110,0,0,0b01111110,0b11111111,0b11001111,0b11011111,0b11011011,0b11000011,0b11111111,0b01111110,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b01110000,0b11111000,0b11001100,0b11001100,0b11001100,0b11111111,0b11111111,0,0,0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110,0,0,0,0,0,0,0 };
unsigned char word7_LED[] = { 0,0,0,0,0,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b11111111,0b11111111,0b01100000,0b01110000,0b01110000,0b01100000,0b11111111,0b11111111,0,0,0b00011111,0b11011111,0b11011000,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011,0,0,0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0,0,0,0,0};
unsigned char word8_LED[] = { 0,0,0,0,0,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111,0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111,0,0,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011,0,0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b11100000,0b11111100,0b00011110,0b00000011,0b00000011,0b00011110,0b11111100,0b11100000,0,0,0,0,0,0,0,0,0};
unsigned char word9_LED[] = { 0,0,0,0,0,0,0,0b01000000,0b11100000,0b01110000,0b00111111,0b00111111,0b01110000,0b11100000,0b01000000,0,0,0b11111111,0b11111111,0b00011000,0b00011000,0b00011000,0b11111111,0b11111111,0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0b01110000,0b11111000,0b11001100,0b11001100,0b11001100,0b11111111,0b11111111,0,0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111,0,0,0,0,0,0,0,0,0 };
unsigned char word10_LED[] = { 0,0,0,0,0,0,0,0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111,0,0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,0b11001110,0b11011111,0b11011011,0b11011011,0b11011011,0b11011011,0b11111011,0b01110011,0,0,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111,0,0,0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110,0,0,0b00111100,0b01111110,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,0,0,0,0,0,0,0};
//Level Functions


int getRandomKey(){
	int num;
	num = rand();
	num = num % 9;
	return num;
}

void WriteCustom (unsigned char loc, unsigned char *msg){
	int j;
	LCD_WriteCommand (0x40 + (loc*8));
	for(j = 0; j < 8; j++)
	LCD_WriteData(msg[j]);
	LCD_WriteCommand(0x80);
}

void createCustom(unsigned char pos, unsigned char j){
	switch(pos){
		case 0:
			WriteCustom(0, sqr0);
			LCD_Cursor(j);
			LCD_WriteData(0);
			break;
			
		case 1:
			WriteCustom(1, sqr1);
			LCD_Cursor(j);
			LCD_WriteData(1);
			break;
			
		case 2:
			WriteCustom(2, sqr2);
			LCD_Cursor(j);
			LCD_WriteData(2);
			break;
		case 3:
			WriteCustom(3, sqr3);
			LCD_Cursor(j);
			LCD_WriteData(3);
			break;
		case 4:
			WriteCustom(4, sqr4);
			LCD_Cursor(j);
			LCD_WriteData(4);
			break;
		
		case 5:
			WriteCustom(5, sqr5);
			LCD_Cursor(j);
			LCD_WriteData(5);
			break;
		case 6:
			WriteCustom(6, sqr6);
			LCD_Cursor(j);
			LCD_WriteData(6);
			break;
		case 7:
			WriteCustom(5, sqr5);
			LCD_Cursor(j);
			LCD_WriteData(5);
			break;
		case 8:
			WriteCustom(4, sqr4);
			LCD_Cursor(j);
			LCD_WriteData(4);
			break;
		case 9:
			WriteCustom(3, sqr3);
			LCD_Cursor(j);
			LCD_WriteData(3);
			break;
		case 10:
			WriteCustom(2, sqr2);
			LCD_Cursor(j);
			LCD_WriteData(2);
			break;
		case 11:
			WriteCustom(1, sqr1);
			LCD_Cursor(j);
			LCD_WriteData(1);
			break;
		case 12:
			WriteCustom(0, sqr0);
			LCD_Cursor(j);
			LCD_WriteData(0);
			break;
	}
	
}

void append(unsigned char* s, unsigned char c) {
	int len = strlen(s);
	s[len] = c;
	s[len+1] = '\0';
}



void levelOneLEDisplay(unsigned char specialKey2){
	//unsigned char* Letters = buildWords(occlude);
	char PORT[8] = {1,2,4,8,16,32,64,128}; //pin values of a port 2^0,2^1,2^2��2^7
	if(specialKey2 == 0){
		for(int x=60; x >= 0; x--){
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
	
	if(specialKey2 == 1){
		for(int x = 60; x >= 0; x--){
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
	
	if(specialKey2 == 2){
		for(int x = 60; x >= 0; x--){
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
	
	if(specialKey2 == 3){
		for(int x = 60; x >= 0; x--){
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
	
	if(specialKey2 == 4) {
		for(int x = 60; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word5_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
	}
	
	if(specialKey2 == 5) {
		for(int x = 60; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word6_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
	}
	
	if(specialKey2 == 6) {
		for(int x = 60; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word7_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
	}
	
	if(specialKey2 == 7) {
		for(int x = 60; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word8_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
	}
	
	if(specialKey2 == 8) {
		for(int x = 60; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word9_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
	}
	
	if(specialKey2 == 9) {
		for(int x = 60; x >= 0; x--){
			for(int a=0; a < levelSpeed; a++){
				for (int i = 0; i < 8; i++){
					PORTB = ~PORT[i];    //ground the PORTB pin
					PORTC = word10_LED[i+x];  //power the PORTC
					_delay_ms(1);
					PORTB = PORT[i];     //clear pin after 1msec
				}
			}
		}
		PORTB = 0x00;
		PORTC = 0x00;
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
	HORIZONTALMOV = ADC;//moving value
	ADC=0;//reset ADC register
	
	return HORIZONTALMOV;
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