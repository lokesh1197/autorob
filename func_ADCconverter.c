/*
 * func_ADCconverter.c
 *
 * Created: 03-12-2016 02:45:09
 *  Author: Lokesh Mohanty
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

float ADCconverter(int MUX);
float *accel(int x, int y,int z);

int main(void) 
{
	float *c;
	DDRB=255;
	while() {
		c=accel(0, 1, 2);
	}
}
	
float ADCconverter(MUX)
{
	float b;
	ADMUX=MUX;
	ADMUX|=(0<<REFS1)|(1<<REFS0)|(1<<ADLAR);
	ADCSRA|=(1<<ADEN)|(1<<ADSC)|(0<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	while(ADCSRA && (1<<ADSC)) {}
	b=ADC;
	return b;
}

float *accel(x, y, z)
{
		float *b;
		b[0]=ADCconverter(x);
		b[1]=ADCconverter(y);
		b[2]=ADCconverter(z);
		return b;
}	
