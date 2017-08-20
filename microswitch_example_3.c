//You switch LED mode every time You press BUTTON.
//This example doesn't use interrupts.
//GP0 LED
//GP3 PRZYCISK


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
	unsigned LED_MODE = 0;
	unsigned i = 0;
	while(1)
	{
		unsigned button_state = BUTTON;
		if(button_state != last_button_state)
		{
			__delay_ms(20);
			if(button_state)
			LED_MODE ^= 1;
		}
		last_button_state = button_state;
		switch(LED_MODE & 1)					//Only LSB
		{
			case 0:	LED = 1;
				break;
			case 1: for(i = 0; i<500; i++)
				{
					__delay_ms(1);
					if(BUTTON != last_button_state)
					break;
				}
				LED ^= 1;
				break;
				
		}	
	}
}
