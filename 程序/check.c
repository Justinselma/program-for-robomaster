#include "check.h"
void check (void)					//¼ì²éº¯Êý				*				  
{																	  
    if((hour == ahour) && (minute == aminute) && (second == asecond)) 
    {						
		P17=1;
		delayms(10000);
		P17=0;			
    }							               
        										
}	