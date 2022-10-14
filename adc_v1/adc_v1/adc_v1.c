#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL

#include <avr/interrupt.h>

unsigned int ADC_read(unsigned char chnl)

{

	chnl= chnl & 0b00000111; // select adc channel between 0 to 7

	ADMUX = 0x40;        //channel A0 selected

	ADCSRA|=(1<<ADSC);   // start conversion

	while(!(ADCSRA & (1<<ADIF)));   // wait for ADIF conversion complete return

	ADCSRA|=(0<<ADIF);   // clear ADIF when conversion complete by writing 1

	return (ADC); //return calculated ADC value

}



int main(void)

{

	PORTD = 0xFF;         //make PORTC as output to connect 8 leds

	ADMUX=(1<<REFS0);      // Selecting internal reference voltage

	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);     // Enable ADC also set Prescaler as 128

	

	int i = 0; // define an integer to save adc read value

	

	while (1)

	{

		

		i = ADC_read(0);   //save adc read value in integer

		PORTD = i&0b11111111;        // send adc value to all pins of portc

	}

}
