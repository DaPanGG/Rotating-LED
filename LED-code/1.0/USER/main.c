#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "huayang.h"
#include "zimo.h"
#include "xianshi.h"

extern u8 BUF1[DISPLAY_BUFFER_SIZE];
//extern u8 BUF2[DISPLAY_BUFFER_SIZE];

//��ʾ���ƺ��ַ�
void display(void);

/*******************************************************************************
* ������         : int main(void)
* ��������		 : ������
* ����           : ��
* ���         	 : ��
*******************************************************************************/
 int main(void)
 {	
	Clear_All(BUF1);	
//	Clear_All(BUF2);	//���������ʾ������
	delay_init();	    //��ʱ������ʼ��
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	LED28 = 0;
	delay_ms(5000);		//��ʱ5����,�ȴ�����ȶ�
	delay_ms(5000);		//��ʱ5����,�ȴ�����ȶ�
	delay_ms(5000);		//��ʱ5����,�ȴ�����ȶ�
	delay_ms(5000);		//��ʱ5����,�ȴ�����ȶ�
	delay_ms(5000);		//��ʱ5����,�ȴ�����ȶ�
	delay_ms(5000);		//��ʱ5����,�ȴ�����ȶ�
	while(1)
	{
		display();	//��ʾ�ַ��ͻ���
	}
 }
 
 
 /*******************************************************************************
* ������         : void display(void)
* ��������		 : ��ʾ���ƺ��ַ�
* ����           : ��
* ���         	 : ��
*******************************************************************************/
void display(void)
{
	u16 i,j;
	u8 qiDian;	//������ʾʱ�����λ��
	Clear_All(BUF1);	
//	Clear_All(BUF2);	//���������ʾ������
//��ʾ����,Ԥ����ʼ��ʾ
	Bowen();
//��Ȧ�ָ�����
	LED16 = 0;	//�м���Ȧ��
	LED28 = 0;	//���ڲ�׹�Ȧ��
	
	qiDian = Get_Centre(Reai_SIZE);//����"�Ȱ�"
//��������"�Ȱ�",��������⻨��
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Reai, qiDian, qiDian + Reai_SIZE / 2, 1);
//		ShangYi(BUF2, JianHuaban, 0 , BUF2_SIZE / 2, 1);
		Disp(BUF1, BUF1_SIZE);
	}
	Disp_Delay(200);	//������ʾ200��
//������������,�����Ȱ������
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Xinghao, qiDian - 20, qiDian - 4, 1);
		Disp(BUF1,BUF1_SIZE);
	}
//�������밮��,�����Ȱ����Ҳ�
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Xinghao, qiDian + Reai_SIZE / 2 + 4, qiDian + Reai_SIZE / 2 + 20, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(20);	//������ʾ20��
//ˢ����ʾ������������,ʵ��ð��Ч��
	for(j = 0; j < 3; j++)
	{
		for(i = 0; i < 16; i++)
		{
			ShangYi(BUF1, Xinghao, qiDian - 20, qiDian - 4, 1);
			Disp(BUF1,BUF1_SIZE);
		}
		for(i = 0; i < 16; i++)
		{
			ShangYi(BUF1, Xinghao, qiDian + Reai_SIZE / 2 + 4, qiDian + Reai_SIZE / 2 + 20, 1);
			Disp(BUF1,BUF1_SIZE);
		}
	}
//������������"�Ȱ�"
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Reai, qiDian, qiDian + Reai_SIZE / 2, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(200);	//������ʾ200��
//�����Ƴ�"�Ȱ�",�����Ƴ��⻨��
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Reai, qiDian, qiDian + Reai_SIZE / 2, 0);
//		XiaYi(BUF2, (void *)0, 0 , BUF2_SIZE / 2, 0);
		Disp(BUF1,BUF1_SIZE);
	}
//�����Ƴ���������	
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, (void *)0, qiDian - 20, qiDian + Reai_SIZE / 2 + 20, 0);
		Disp(BUF1,BUF1_SIZE);
	}
//����������������ַ���
	while(ZuoYi(Fuhuaqi, Fuhuaqi_SIZE, 0, BUF1_SIZE / 2 ,1)==0)
	{
		Disp(BUF1,BUF1_SIZE);
	}
//�����Ƴ����������ַ���
	for(i = 0; i < BUF1_SIZE / 2; i++)
	{
		ZuoYi((void *)0, 0, 0, BUF1_SIZE / 2, 0);
		Disp(BUF1, BUF1_SIZE);
	}
	Disp_Delay(20);	//������ʾ20��
////��������⻨��
//	for(i = 0; i < 16; i++)
//	{
//		ShangYi(BUF2, YuanHuaban, 0 , BUF2_SIZE / 2, 1);
//		Disp(BUF1,BUF1_SIZE);
//	}
//	Disp_Delay(5);	//������ʾ5��
//�����������
	qiDian = Get_Centre(Geyan_SIZE);
	while(YouYi(Geyan, Geyan_SIZE, qiDian, qiDian + Geyan_SIZE / 2, 1)==0)
	{
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(100);	//������ʾ100��
//��˸��ʾ����
	for(i = 0; i < 10; i ++)
	{
		Clear_All(BUF1);	
		Disp_Delay(3);
		Copy_to_Buf(Geyan, &BUF1[qiDian * 2], Geyan_SIZE-1);
		Disp_Delay(3);
	}
//�����Ƴ�����
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, (void *)0, qiDian, qiDian + Geyan_SIZE / 2, 0);
		Disp(BUF1, BUF1_SIZE);
	}
////�����Ƴ��⻨��
//	for(i = 0; i < 16; i++)
//	{
//		XiaYi(BUF2, (void *)0, 0 , BUF2_SIZE / 2, 0);
//		Disp(BUF1, BUF2, BUF1_SIZE);
//	}
	LED16 = 1;	//�м���Ȧ��
}
		
