/*
 * blinkylights.c
 *
 * Created: 10/1/2022 8:56:33 AM
 * Author : Amar
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL 

#include <util/delay.h>

#include <avr/interrupt.h>


int main(void)
{
    /* Replace with your application code */
	
	
	DDRD=(1<<6);
	//PIND=1;
	
    int i=0;
	
    while (1) 
    {
	   _delay_ms(1000);
	   PORTD= (0<<6);
	   _delay_ms(1000);
	   PORTD=(1<<6);
		
	
	}
}

ISR(XXX_vect)
{
	

}

