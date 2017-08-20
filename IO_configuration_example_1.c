//Example shows how to configure I/O pins.

#include <htc.h>

int main()
{								
	//TRISGPIO	-	register deciding about pin direction ( I/O )
	//0 - Output, 1 - Input
	//GP3 input only ( 1 )
	//Value on Power on Reset 1b111		
	TRISGPIO = 1b000;			//GP3 as input, rest as outputs


	GPIO = 0b000;				//GPIO initial value
	COUTEN = 1;				//Comparator output is not placed on the COUT ( GP2 ) pin
	CMPON = 0;				//Comparator is off

	OPTION = 1b1011111;			//T0CS = 0 for not overwriting GP2


	while(1)
	{
		if(GP3 == 1)			//If 5V on GP3
		GP0 = 1;			//Set GP0
		else				//else reset GP0
		GP0 = 0;
	}
}
