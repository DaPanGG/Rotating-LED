#ifndef __LED_H
#define __LED_H
#include "sys.h"

//LED�ӿڶ���
//���⵽��
//��ʾ�ַ� ��ɫLED
#define LED0 PBout(9)
#define LED1 PBout(8)
#define LED2 PBout(7)
#define LED3 PBout(6)
#define LED4 PBout(5)
#define LED5 PBout(4)
#define LED6 PBout(3)
#define LED7 PAout(12)
#define LED8 PAout(11)
#define LED9 PAout(9)
#define LED10 PAout(10)
#define LED11 PAout(8)
#define LED13 PBout(13)
#define LED12 PBout(15)
#define LED14 PBout(14)
#define LED15 PBout(12)
//��ʾ���� ��ɫ
#define LED16 PBout(11)
//��ʾ���� ��ɫ
#define LED17 PBout(10)
#define LED18 PBout(2)
#define LED19 PBout(1)
#define LED20 PBout(0)
#define LED21 PAout(7)
#define LED22 PAout(6)
#define LED23 PAout(5)
#define LED24 PAout(4)
#define LED25 PAout(3)
#define LED26 PAout(2)
#define LED27 PAout(1)
//��ʾ���� ��ɫ
#define LED28 PAout(0)

void LED_Init(void);//��ʼ��
void LED_Disp(u32 num);

#endif
