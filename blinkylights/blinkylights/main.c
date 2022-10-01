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
	DDRD=0xFF;
	
	
    while (1) 
    {
    }
}

ISR(XXX_vect)
{
	

}

