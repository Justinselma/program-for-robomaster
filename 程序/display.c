#include "display.h"
void modess(void)								//实现0.5s亮灭闪烁 时钟闪烁函数		   *
{
	P2 = 0x24;	   //00100100
	P0 = 0xbf;	   //10111111
	delayms(5);
		
	if((reset==0) && (t0>9))	P2 = 0;
	else	P2 = dliang[0];
	P0 = xliang[add[0]];
	delayms(5);

	 if((reset==0) && (t0>9))	P2 = 0;
	else	P2 = dliang[1];	
	P0 = xliang[add[1]];
	delayms(5);

	if((reset==1) && (t0>9))	P2 = 0;
	else	P2 = dliang[2];
	P0 = xliang[add[2]];
	delayms(5);

	if((reset==1) && (t0>9))	P2 = 0;
	else	P2 = dliang[3];
	P0 = xliang[add[3]];
	delayms(5);

	if((reset==2) && (t0>9))	P2 = 0;
	else	P2 = dliang[4];
	P0 = xliang[add[4]];
	delayms(5);

	if((reset==2) && (t0>9))	P2 = 0;
	else	P2 = dliang[5];
	P0 = xliang[add[5]];
	delayms(5);
}

void xmodess(void)								//实现0.5s亮灭闪烁 闹钟闪烁函数		  *
{
	P2 = 0x24;	   //00100100
	P0 = 0xbf;	   //10111111
	delayms(5);
		
	if((reset==0) && (t0>9))	P2 = 0;
	else	P2 = dliang[0];
	P0 = xliang[bdd[0]];
	delayms(5);

	 if((reset==0) && (t0>9))	P2 = 0;
	else	P2 = dliang[1];	
	P0 = xliang[bdd[1]];
	delayms(5);

	if((reset==1) && (t0>9))	P2 = 0;
	else	P2 = dliang[2];
	P0 = xliang[bdd[2]];
	delayms(5);

	if((reset==1) && (t0>9))	P2 = 0;
	else	P2 = dliang[3];
	P0 = xliang[bdd[3]];
	delayms(5);

	if((reset==2) && (t0>9))	P2 = 0;
	else	P2 = dliang[4];
	P0 = xliang[bdd[4]];
	delayms(5);

	if((reset==2) && (t0>9))	P2 = 0;
	else	P2 = dliang[5];
	P0 = xliang[bdd[5]];
	delayms(5);
}

void mode(void)			 //mode 扫描函数					*
{
	for(i=0;i<6;i++)
	{
		P2=dliang[i];
		P0=xliang[add[i]];
		delayms(5);
		/*	P0=0xff; */


	}
	/*		//亮出	0     1	   2	 3	  4	  5	   6   7	8	 9
	uchar xliang[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};                //段选码 小亮 共阳   P0
	uchar dliang[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; */             //位选码 大亮	  P2
				//第8	  7	   6	  5		 4		3	   2	 1	 个灯亮				  
    P2=0x24;		//改为24	  原为c0
	P0=0xbf;
	delayms(5);	
}
