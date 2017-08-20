//CIN+ GP0
//CIN- Internal voltage reference 0.6V
//COUT GP2
//If CIN+ > CIN- then COUT SET.

#include <htc.h>
__CONFIG(MCLRDIS & WDTDIS & UNPROTECT);


int main()
{
	CMCON0 = 1b0111011;		//Output of comparator at COUT pin, Negative pin = internal voltage reference

	while(1)
	{
		
	}
}
