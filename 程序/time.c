#include "pwm.h"
void zjs(void)	//����ʱ
{	
	second++;
	if(second==60)
	{
		minute++;
		second=0;
	}
	if(minute==60)
	{
	 	hour++;
		minute=0;	
	}
	if(hour==24)
	{
		hour=0;
	}	
}
