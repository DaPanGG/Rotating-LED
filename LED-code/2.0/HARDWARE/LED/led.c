#include "led.h"

//��ʼ��PB5��PE5Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{ 	
	GPIO_InitTypeDef  GPIO_InitStructure;
	//ʹ��GPIOA��GPIOB��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
	
	//
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//���Ÿ���
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE); //��ֹJTAG-DP��ʹ��SW-DP

	
	GPIO_InitStructure.GPIO_Pin = ((uint16_t)0x1fff);	//A0~A12�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);	//�����趨������ʼ��GPIOA
	GPIO_SetBits(GPIOA,(uint16_t)0x1fff);	//A0~A12�����,��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;	//B0~B15�˿�����
	GPIO_Init(GPIOB, &GPIO_InitStructure);	//�����趨������ʼ��GPIOB
	GPIO_SetBits(GPIOB,GPIO_Pin_All);	//B0~B15�����,��
}
 
/*******************************************************************************
* ������         : void LED_Zi_Disp(u16 num)
* ��������		 : �����ַ����е�LED
* ����           : num: ��Ӧ�е�16λ����
* ���         	 : ��
*******************************************************************************/
void LED_Disp(u32 num)
{
	//�ӵ͵���
	//��ʾ�ַ�
	LED0  = (num & (1<<0))  > 0 ? 0 : 1;	//����1,���0,����
	LED1  = (num & (1<<1))  > 0 ? 0 : 1;
	LED2  = (num & (1<<2))  > 0 ? 0 : 1;
	LED3  = (num & (1<<3))  > 0 ? 0 : 1;
	LED4  = (num & (1<<4))  > 0 ? 0 : 1;
	LED5  = (num & (1<<5))  > 0 ? 0 : 1;
	LED6  = (num & (1<<6))  > 0 ? 0 : 1;
	LED7  = (num & (1<<7))  > 0 ? 0 : 1;
	LED8  = (num & (1<<8))  > 0 ? 0 : 1;
	LED9 =  (num & (1<<9))  > 0 ? 0 : 1;
	LED10 = (num & (1<<10)) > 0 ? 0 : 1;
	LED11 = (num & (1<<11)) > 0 ? 0 : 1;
	LED12 = (num & (1<<12)) > 0 ? 0 : 1;
	LED13 = (num & (1<<13)) > 0 ? 0 : 1;
	LED14 = (num & (1<<14)) > 0 ? 0 : 1;
	LED15 = (num & (1<<15)) > 0 ? 0 : 1;
	//��ʾ����
	LED17 = (num & (1<<16)) > 0 ? 0 : 1;
	LED18 = (num & (1<<17)) > 0 ? 0 : 1; 
	LED19 = (num & (1<<18)) > 0 ? 0 : 1;
	LED20 = (num & (1<<19)) > 0 ? 0 : 1;
	LED21 = (num & (1<<20)) > 0 ? 0 : 1;
	LED22 = (num & (1<<21)) > 0 ? 0 : 1;
	LED23 = (num & (1<<22)) > 0 ? 0 : 1;
	LED24 = (num & (1<<23)) > 0 ? 0 : 1;
	LED25 = (num & (1<<24)) > 0 ? 0 : 1;
	LED26 = (num & (1<<25)) > 0 ? 0 : 1;
	LED27 = (num & (1<<26)) > 0 ? 0 : 1;
}
