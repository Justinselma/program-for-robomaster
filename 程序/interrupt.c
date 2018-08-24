#include "interrupt.h"
 
void ms() interrupt 0	//ģʽ�ⲿ�ж�
{
	delayms(5);
	if(P32==0)
	{
		cases++;
		reset=0;
		if(cases==3)
		cases=0;
	}
	while(P32==0); 
}

void jssm() interrupt 1	 //��ʱ���ڲ��ж�   ��ʱɨ��
{
	TH0=(65536-45872)/256;	//50ms
	TL0=(65536-45872)%256;
	/*P17=1*/;
	t0++;
	if(t0==20)
	{	
	/*	P17=0; */
		t0=0;
		if(cases!=1)
		zjs();
		check();
	}
		if(cases==2)
			   {
			    bdd[0]=asecond%10;
				bdd[1]=asecond/10;
				bdd[2]=aminute%10;
				bdd[3]=aminute/10;
				bdd[4]=ahour%10;
				bdd[5]=ahour/10;
			   }
		   else{
				add[0]=second%10; //0123456789
				add[1]=second/10;
				add[2]=minute%10;
				add[3]=minute/10;
				add[4]=hour%10;
				add[5]=hour/10;	
			   }
	  
	switch(cases)
	{
		case 0 :mode();break;		   //ɨ��
		case 1 :modess();break;		  //��˸
		case 2 :xmodess();break;		 //
		default	:break;
	}	   
}

void move() interrupt 2		//�ƶ�reset�ж�
{
	delayms(5);
	if(P33 == 0)
	{
		reset++;			 //ʱ������ڱ�־λ
		if(reset==3)
		reset=0;
	}
	while(P33 == 0);	
}