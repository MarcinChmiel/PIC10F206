//Example shows how to program LED blinking with delay function.

#include <htc.h>
#define _XTAL_FREQ 4000000			//Oscillator frequency for delay function

int main()
{								
	TRISGPIO = 1b000;			//GP3 input, rest outputs
	GPIO = 0b000;				//GPIO initial value
	COUTEN = 1;				//Comparator output is not placed on the COUT ( GP2 ) pin
	CMPON = 0;				//Comparator is off
	OPTION = 1b1011111;			//T0CS = 0, for not overwriting GP2


	while(1)
	{
		__delay_ms(250);		//Delay function
		GP0 ^= 1;			//Switch GP0 state
	}
}
