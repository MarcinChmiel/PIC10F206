//Switch LED every 250ms.

#include <htc.h>
#define LED GP0
__CONFIG(MCLRDIS & WDTDIS & UNPROTECT);		//Configuration bits

int main()
{
	TRISGPIO = 1b000;
	GPIO = 0b000;
	OPTION = 1b1010111;			//T0CS = 0, PSA = 0, Prescaler 256, 1MHZ/256 = 4Khz
						//1s = 4000 cycles, 250ms = 1000 cycles = 4 * 250 cycles
	CMCON0 = 1b1110111;			//Comparator off
	unsigned i = 0;
	while(1)
	{
		while(TMR0 < 250);		//Wait for timer value 250
		TMR0 = 0;			//Clear timer value
		i++;
		if(i == 4)
		{
			i = 0;
			LED ^= 1;		//Switch LED
		}

	}
}
