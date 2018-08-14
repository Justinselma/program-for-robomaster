#include <reg51.h>
#define T 80         
#define uint unsigned int
#define uchar unsigned char
	void start(void);	   //��ֵ����
	void zjs(void);		   //����ʱ����
	void mode(void);	  //mode ɨ�躯��
	void modess(void);	 //mode ʱ����˸����
	void xmodess(void);	  //mode ������˸����
	void check(void);	  //��麯��
	void jia(void);		 //�ӷ�������
	void huxi(void);      //�����ƺ���
	void delayms(uint z);	  //��ʱ����


	uchar xliang[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; //��ѡ�� С�� ����
	uchar dliang[]={0x80,0x40,/*0x20,*/0x10,0x08,/*0x04,*/0x02,0x01}; //λѡ�� ����
	uchar second,minute,hour,x,i,cases=0,t0=0,j,reset=0,second_1,minute_1,hour_1;
	uchar asecond=0,aminute=0,ahour=0;
	uchar add[]={0,0,0,0,0,0,0,0};
	uchar bdd[]={0,0,0,0,0,0,0,0};
	uint light=0;

	sbit P33 = P3^3;			  //mode
	sbit P32 = P3^2;			  //move
	sbit P34 = P3^4;			  //����
	sbit P35 = P3^5;			  //��
	sbit P17 = P1^7;			  //������


void main()						   //������
{	
	start();
	while(1)				             
	{	
		huxi();
		if(cases==1)
		{
			second_1= second;	   //second_1��Ϊ����
			minute_1= minute;
			hour_1 = hour;
			jia();
			second = second_1;
			minute = minute_1;
			hour = hour_1;
		}
		if(cases==2)
		{
			second_1= asecond;	   //second_1��Ϊ����
			minute_1= aminute;
			hour_1 = ahour;
			jia();
			asecond = second_1;
			aminute = minute_1;
			ahour = hour_1;
		}
	}
}

void start(void)			       //��ֵ����
{
	TMOD = 0x01;
	IE = 0x87;
	TH0 = (65536-45872)/256;
	TL0 = (65536-45872)%256;
	IT0 = 0;
	IT1 = 0;
	IP = 0x02;
	TR0 = 1;
	P17=0;
		
} 

void modess(void)								//ʵ��0.5s������˸ ʱ����˸����
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

void xmodess(void)								//ʵ��0.5s������˸ ������˸����
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

void mode(void)			 //mode ɨ�躯��
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

void jia(void)			//���ǼӰ�
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

void check (void)					//��麯��								  
{																	  
    if((hour == ahour) && (minute == aminute) && (second == asecond)) 
    {						
		P17=1;
		delayms(10000);
		P17=0;			
    }							               
        										
}											
void huxi(void)						//�����ƺ���
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

void delayms(uint z)		//��ʱ����
{	
	uint i,j;
	for(i=z;i>0;i--);
		for(j=110;j>0;j--);
} 