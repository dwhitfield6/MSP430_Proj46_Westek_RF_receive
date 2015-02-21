
#include <msp430.h>
#include "RF.h"

void resetBuffer(unsigned int* Array, unsigned char amount)
{
	unsigned char i;
	for(i =0; i<=(amount -1);i++)
	{
		Array[i] =0; //erase the int Array
	}
}

void resetBufferChar(unsigned char* Array, unsigned char amount)
{
	unsigned char i;
	for(i =0; i<=(amount -1);i++)
	{
		Array[i] =0; //Erase the the char array
	}
}

void send_rf(unsigned char pin, unsigned char* data)
{

	unsigned char i=0;

	for(i=0;i<12;i++)
	 {
		if(data[i] == 0)
		{
			zero(pin); //do the zero bit routine
		}
		else if(data[i] ==1)
		{
			one(pin);  //do the one bit routine
		}
		else
		{
			f(pin);    //do the float bit routine
		}
	}

	P2OUT |= pin; //wave form for the sync bit
	_delay_cycles(250);
	P2OUT &= ~pin;
	_delay_cycles(7000);
}

void zero(unsigned char pin)
{
	//zero bit waveform
	P2OUT |= pin; 
	_delay_cycles(250);
	P2OUT &= ~pin;
	_delay_cycles(690);
	P2OUT |= pin;
	_delay_cycles(250);
	P2OUT &= ~pin;
	_delay_cycles(690);
}
void one(unsigned char pin)
{
	//one bit waveform
	P2OUT |= pin;
	_delay_cycles(810);
	P2OUT &= ~pin;
	_delay_cycles(210);
	P2OUT |= pin;
	_delay_cycles(810);
	P2OUT &= ~pin;
	_delay_cycles(210);
}
void f(unsigned char pin)
{
	//two bit waveform
	P2OUT |= pin;
	_delay_cycles(250);
	P2OUT &= ~pin;
	_delay_cycles(700);
	P2OUT |= pin;
	_delay_cycles(810);
	P2OUT &= ~pin;
	_delay_cycles(200);
}

unsigned char ArrayCompare(unsigned int* Array1, unsigned int* Array2, int amount, unsigned char characters)
{
	unsigned char i;
	unsigned char differences =0;

	for(i=0;i<=(characters -1);i++ )
	{
		if(((int)Array1[i] - (int)Array2[i]) > amount) 
		{
			differences++;
		}
		else if(((int)Array2[i] - (int)Array1[i]) > amount)
		{
			differences++;
		}
	}
	return (differences ? 0 : 1);
}

unsigned char ArrayCompareChar(unsigned char* Array1, unsigned char* Array2, int amount, unsigned char characters)
{
	unsigned char i;
	unsigned char differences =0;
	for(i=0;i<=(characters -1);i++ )
	{
		if(((int)Array1[i] - (int)Array2[i]) > amount)
		{
			differences++;
		}
		else if(((int)Array2[i] - (int)Array1[i]) > amount)
		{
			differences++;
		}
	}
	return (differences ? 0 : 1);
}

void ArrayCopy(unsigned int* from, unsigned int* to, unsigned char characters)
{
	unsigned char i;
	for(i=0;i<=(characters -1);i++ )
	{
		to[i] = from[i];
	}
}

void ArrayCopyChar(unsigned char* from, unsigned char* to, unsigned char characters)
{
	unsigned char i;
	for(i=0;i<=(characters -1);i++ )
	{
		to[i] = from[i];
	}
}

unsigned char readSwitch_P2(unsigned char bit)
{
	unsigned char i;
	unsigned char count;


	
	while(1)
	{
		count =0;
		for(i=10;i>0;i--) // this is the debounce/average
			 {
	   	        	    if((P2IN & bit) != bit)
	           		    {
	           		    	count++;
	           		    }
	           	 	   _delay_cycles(10);
	       		  }
		if(count == 10)
		{
			return 1;
		}
		else if (count == 0)
		{
			return 0;		
		}
	}
}

unsigned char readSwitch_P1(unsigned char bit)
{
	unsigned char i;
	unsigned char count;


	
	while(1)
	{
		count =0;
		for(i=10;i>0;i--) // this is the debounce/average
			 {
	   	        	    if((P1IN & bit) != bit)
	           		    {
	           		    	count++;
	           		    }
	           	 	   _delay_cycles(10);
	       		  }
		if(count == 10)
		{
			return 1;
		}
		else if (count == 0)
		{
			return 0;		
		}
	}
}

void BlinkLED_P2(unsigned char bit)
{
	//blink routine using delay
	
	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);
	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);
	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);
	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);
	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);
}

void Blink2LED_P2(unsigned char bit, unsigned char bit2)
{
	//blink routine using delay for 2 leds
	
	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);
	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);
	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);
	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);
	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);
}
