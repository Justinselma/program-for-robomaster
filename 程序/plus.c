#include "plus.h"
void jia(void)			//���ǼӰ�						  *
{
	if(P35 == 0)
	{
		delayms(5);               //����ȷ����һֱ����
		if(P35 == 0)
		{
			switch(reset)
			{
				case 0 :
					{
						second_1++;
						if(second_1 > 59)
							second_1 = 0;						
					} break;
				case 1 :
					{
						minute_1++;
						if(minute_1 > 59)
							minute_1 = 0;						
					} break;
				case 2 :
					{
						hour_1++;
						if(hour_1 > 24)
							hour_1 = 0;					
					}
				default : break; 
			}

		}
		while(P35 == 0);
	}		
}
