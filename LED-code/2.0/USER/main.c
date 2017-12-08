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
* ��������		 		 : ������
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

	qiDian = Get_Centre(Welcome_SIZE);//����"��������ӭ��"
//��������"��������ӭ��",��������⻨��
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Welcome, qiDian, qiDian + Welcome_SIZE / 2, 1);
//		ShangYi(BUF2, JianHuaban, 0 , BUF2_SIZE / 2, 1);
		Disp(BUF1, BUF1_SIZE);
	}
	Disp_Delay(200);	//������ʾ200��
//������������,���ڷ�������ӭ�������
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Xinghao, qiDian - 20, qiDian - 4, 1);
		Disp(BUF1,BUF1_SIZE);
	}
//������������,���ڷ�������ӭ�����Ҳ�
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Xinghao, qiDian + Welcome_SIZE / 2 + 4, qiDian + Welcome_SIZE / 2 + 20, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(20);	//������ʾ20��
//ˢ����ʾ��������������,ʵ��ð��Ч��
	for(j = 0; j < 3; j++)
	{
		for(i = 0; i < 16; i++)
		{
			ShangYi(BUF1, Xinghao, qiDian - 20, qiDian - 4, 1);
			Disp(BUF1,BUF1_SIZE);
		}
		for(i = 0; i < 16; i++)
		{
			ShangYi(BUF1, Xinghao, qiDian + Welcome_SIZE / 2 + 4, qiDian + Welcome_SIZE / 2 + 20, 1);
			Disp(BUF1,BUF1_SIZE);
		}
	}
//������������"��������ӭ��"
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Welcome, qiDian, qiDian + Welcome_SIZE / 2, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(200);	//������ʾ200��
//�����Ƴ�"��������ӭ��",�����Ƴ��⻨��
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Welcome, qiDian, qiDian + Welcome_SIZE / 2, 0);
//		XiaYi(BUF2, (void *)0, 0 , BUF2_SIZE / 2, 0);
		Disp(BUF1,BUF1_SIZE);
	}
	
	qiDian = Get_Centre(Reai_SIZE);//����"�Ȱ�"
//�������롰�Ȱ���
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Reai, qiDian, qiDian + Reai_SIZE / 2 , 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(50);	//������ʾ50��
//"�ȣ����ģ���"
	qiDian = Get_Centre(Rekongai_SIZE);//����"�Ȱ�"
	//�������롰��  ����
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, Rekongai, qiDian, qiDian + Rekongai_SIZE / 2, 1);
	//	ShangYi(BUF1, Aixin, qiDian + 16, qiDian + 16 + Aixin_SIZE / 2, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Aixin, qiDian + 16, qiDian + 16 + Aixin_SIZE / 2, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(50);	//������ʾ50��
	

	
	qiDian = Get_Centre(Welcome_SIZE);//����"��������ӭ��"
//�����Ƴ���������
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, (void *)0, qiDian - 20, qiDian + Welcome_SIZE / 2 + 20, 0);
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

	qiDian = Get_Centre(Xiaolian_SIZE);
//��������O(��_��)O
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Xiaolian, qiDian, qiDian + Xiaolian_SIZE / 2, 1);
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(100);	//������ʾ100��
//�����Ƴ�O(��_��)O
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, (void *)0, qiDian, qiDian + Xiaolian_SIZE / 2, 0);
		Disp(BUF1,BUF1_SIZE);
	}
	
	qiDian = Get_Centre(Goodstudy_SIZE);
//�������롰�ú�ѧϰ��
	while(YouYi(Goodstudy, Goodstudy_SIZE, qiDian, qiDian + Goodstudy_SIZE / 2, 1)==0)
	{	
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(100);	//������ʾ100��	
//�����Ƴ����ú�ѧϰ��
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, (void *)0, qiDian, qiDian + Goodstudy_SIZE / 2, 0);
		Disp(BUF1,BUF1_SIZE);		
	}
	
	qiDian = Get_Centre(Dayup_SIZE);
//�������롰�������ϡ�
	while(ZuoYi(Dayup, Dayup_SIZE, qiDian, qiDian + Dayup_SIZE / 2, 1)==0)
	{
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(100);	//������ʾ100��	
//�����Ƴ����������ϡ�
	for(i = 0; i < 16; i++)
	{
		XiaYi(BUF1, (void *)0, qiDian, qiDian + Dayup_SIZE / 2, 0);
		Disp(BUF1,BUF1_SIZE);		
	}
	qiDian = Get_Centre(Website_SIZE);
//��������"www.utii.org"
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, Website, qiDian, qiDian + Website_SIZE / 2, 1);	
		Disp(BUF1,BUF1_SIZE);
	}
	Disp_Delay(100);	//������ʾ20��
//�����Ƴ�"www.utii.org"
	for(i = 0; i < 16; i++)
	{
		ShangYi(BUF1, (void *)0, qiDian, qiDian + Website_SIZE / 2, 0);	
		Disp(BUF1,BUF1_SIZE);
	}
	
	LED16 = 1;	//�м���Ȧ��	
	delay_ms(500);
}
		
