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

int extraTime=0;

int main(void)

{

	DDRD=0x01;
	TCCR0A=(1<<WGM01)|(1<<WGM00)|(1<<WGM02);//sets ctc bits, CTC = clear timer on compare.
	OCR0A=156;//compares the counter with 156 ticks.

	
	TIMSK0=(1<<OCIE0A);
	sei(); // sets I bit for interrupt to occur.
	
	TCCR0B=(1<<CS02)|(1<<CS00);// start at prescalar of 1024.
	
	
	

	//DDRB= (1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(0x00);
while(1){
	
	if(OCR0A==255)
		OCR0A=0;
	else
		OCR0A++;
	
	
	
}
	//add your codes here

}

//The interrupt service routine are written as follow:

ISR(TIMER0_COMPA_vect)

{
	
	extraTime++;
	if(extraTime>1000){
		PORTD^=(1<<PORTD0);
		
	}	
	
	
	
	
}
