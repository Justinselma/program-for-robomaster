#ifndef __MAIN_H_
#define __MAIN_H_
#define T 80         
#define uint unsigned int
#define uchar unsigned char


#include "reg52.h"



#include "delayms.h"

#include "display.h"

#include "check.h"
#include "plus.h"
#include "start.h"
#include "time.h"
#include "pwm.h"
#include "interrupt.h"

	uchar xliang[]; //��ѡ�� С�� ����
extern	uchar dliang[]; //λѡ�� ����
extern	uchar second,minute,hour,x,i,cases,t0,j,reset,second_1,minute_1,hour_1;
extern	uchar asecond,aminute,ahour;
extern	uchar add[];
extern	uchar bdd[];
	uint light;

	sbit P33 = P3^3;			  //mode
	sbit P32 = P3^2;			  //move
	sbit P34 = P3^4;			  //����
	sbit P35 = P3^5;			  //��
	sbit P17 = P1^7;			  //������


#endif