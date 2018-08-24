#include "main.h"


    uchar xliang[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; //段选码 小亮 共阳
	uchar dliang[]={0x80,0x40,/*0x20,*/0x10,0x08,/*0x04,*/0x02,0x01}; //位选码 大亮
	uchar second,minute,hour,x,i,cases=0,t0=0,j,reset=0,second_1,minute_1,hour_1;
	uchar asecond=0,aminute=0,ahour=0;
	uchar add[]={0,0,0,0,0,0,0,0};
	uchar bdd[]={0,0,0,0,0,0,0,0};
	uint light=0;
void main()						   //主函数		  *
{	
	start();
	while(1)				             
	{	
		pwm();
		if(cases==1)
		{
			second_1= second;	   //second_1作为辅助
			minute_1= minute;
			hour_1 = hour;
			jia();
			second = second_1;
			minute = minute_1;
			hour = hour_1;
		}
		if(cases==2)
		{
			second_1= asecond;	   //second_1作为辅助
			minute_1= aminute;
			hour_1 = ahour;
			jia();
			asecond = second_1;
			aminute = minute_1;
			ahour = hour_1;
		}
	}
}