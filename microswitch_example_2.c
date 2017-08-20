//Switch LED every time You press BUTTON
//GP0 LED
//GP3 BUTTON

#include <htc.h>
#define _XTAL_FREQ 4000000
#define LED GP0
#define BUTTON GP3


int main()
{
	TRISGPIO = 1b000;
	GPIO = 0b000;
	CMCON0 = 1b1110111;						//Comparator OFF
	OPTION = 1b1011111;						//T0CS = 0
	unsigned last_button_state = 0;
	while(1)
	{
		unsigned button_state = BUTTON;
		if(button_state != last_button_state)
		{
			__delay_ms(20);					//Debouncing	
			if(button_state)
			LED ^= 1;
		}
		last_button_state = button_state;
	}
}
