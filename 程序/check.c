#include "check.h"
void check (void)					//��麯��				*				  
{																	  
    if((hour == ahour) && (minute == aminute) && (second == asecond)) 
    {						
		P17=1;
		delayms(10000);
		P17=0;			
    }							               
        										
}	