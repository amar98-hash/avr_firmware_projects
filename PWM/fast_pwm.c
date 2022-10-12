/*
 * _8bittimer.c
 *
 * Created: 10/3/2021 7:53:07 PM
 *  Author: Amar Dadel
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL    //Define CPU clock as 16Mhz

#include <util/delay.h>

#include <avr/interrupt.h>

#include <stdbool.h>

int extraTime=0;

int main(void)

{


	
	TIMSK1=(1<<OCIE1A);
	sei(); // sets I bit for interrupt to occur.
	
	
	DDRB=1<<1;
	TCCR1A=(0<<WGM11)|(1<<WGM10)|(1<<WGM12)| (1<<COM1A1);//sets ctc bits, CTC = clear timer on compare.
	//OCR0A=156;//compares the counter with 156 ticks.

	
	TCCR1B=(1<<CS10);// start at prescalar of 1.
	
	
	

	//DDRB= (1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(0x00);

	uint8_t pwm = 0x00;
	bool up = true;
	while(1) {

		OCR1A = pwm;

		if (pwm == 0xff) 
			pwm=0;

		else 
		    pwm++;
			

		_delay_ms(10);
	}


	//add your codes here

}

//The interrupt service routine are written as follow:
ISR(TIMER1_COMPA_vect){
	
	
}