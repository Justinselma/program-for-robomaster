#include "pwm.h"
void start(void)			       //³õÖµº¯Êý	   *
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