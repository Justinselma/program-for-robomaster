#include "display.h"
void modess(void)								//ʵ��0.5s������˸ ʱ����˸����		   *
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

void xmodess(void)								//ʵ��0.5s������˸ ������˸����		  *
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

void mode(void)			 //mode ɨ�躯��					*
{
	for(i=0;i<6;i++)
	{
		P2=dliang[i];
		P0=xliang[add[i]];
		delayms(5);
		/*	P0=0xff; */


	}
	/*		//����	0     1	   2	 3	  4	  5	   6   7	8	 9
	uchar xliang[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};                //��ѡ�� С�� ����   P0
	uchar dliang[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; */             //λѡ�� ����	  P2
				//��8	  7	   6	  5		 4		3	   2	 1	 ������				  
    P2=0x24;		//��Ϊ24	  ԭΪc0
	P0=0xbf;
	delayms(5);	
}
