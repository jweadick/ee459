/* Josh Weadick Servo code*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

static inline void initServo(void){
	TCCR0A = 0;
	TCCR0B = 0;
	// Use fast pwm. Define TOP as 0xFF (255)
	//TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A0); // bits for fast PWM mode on ATmega328p
	//TCCR0B |=  /*(1 << WGM02) | (1 << CS01); // Sets prescaler to divide clock by 8
	
	OCR0A = 254;
	TCCR0A = (1<<COM0B1) | (1<<WGM00) | (1<<WGM01);
	TCCR0B = (1<<WGM02) | (1<<CS12);
	DDRD |= (1<<PD5);
}
	
inline void changePos(float duty_cycle){
	
	OCR0B = 254*(duty_cycle/100.0);
	_delay_ms(3000);
}
int main(void)
{
	initServo();
	int16_t x = 0;
	while(1)
	{	
		/*if(x > 26){
			x = 0;
		}
		else{
			x += 2;
		}*/

//	OCR0B = 64;//255*(duty_cycle/100.0);
		changePos(29); //all the way counterclockwise
		changePos(5); // all the way clockwise
		changePos(15);
	}
	return 0;
}

