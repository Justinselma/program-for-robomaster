#include "pwm.h"
void pwm(void)						//ºôÎüµÆº¯Êý
{
		P17=0;
		delayms(light);
		P17=1;
		delayms(T-light);

		light++;					  
		if(light==T)	 			 
		{
			for(;light>0;light--)	  
			{
				P17=0;
				delayms(light);
				P17=0xff;
				delayms(T-light);
			}
		}
}
