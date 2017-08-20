//LED ON when BUTTON PRESSED
//GP0 LED
//GP3 BUTTON

#include <htc.h>
#define LED GP0
#define BUTTON GP3


int main()
{
	TRISGPIO = 1b000;
	GPIO = 0b000;
	CMCON0 = 1b1110111;	//Comparator OFF
	OPTION = 1b1011111;	//T0CS = 0
	while(1)
	{
		if(BUTTON)
		LED=1;
		else
		LED=0;
	}
}
