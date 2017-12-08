#include "xianshi.h"
#include "led.h"
#include "huayang.h"
#include "delay.h"

static u8 *Backup_PTR1  = (void *)0;	//����ָ��
//static u8 *Backup_PTR2  = (void *)0;	//����ָ��
static u32 Backup_SIZE = 0;	//���ݴ�С

/*******************************************************************************
* ������         : void Zi_Disp(u8 *Source, u32 size)
* ��������		 : ��ʾ�ַ�
* ����           : Source:��ʾ���ݵĻ�����
				   size:�������Ĵ�С(��λ: �ֽ�)
* ���         	 : ��
*******************************************************************************/
void Disp(u8 *Zifu, u32 size)
{
	u8 i;
//	u32 temp;
	u16 temp1;
	Backup_PTR1 = Zifu;	//����ָ��
//	Backup_PTR2 = Huawen;
	Backup_SIZE = size;	//���ݴ�С
	while(TongBu == 1);	//�ȴ�����ͬ���źŵĵ���
	for(i = 0; i < size / 2; i ++)
	{
		temp1 = (*(Zifu + 1) << 8) | *Zifu;
		Zifu += 2;
//		temp2 = (*(Huawen + 1) << 8) | *Huawen;
//		Huawen += 2;
//		temp = (temp2 << 16) | temp1;
		LED_Disp(temp1);//��ʾ����
		delay_us(250);	//�ʵ���ʱ
		LED_Disp(0);	//�����ʾ
		
	}
}
/*******************************************************************************
* ������         : void Disp_Delay(u32 num)
* ��������		 : ˢ��,���ö����ʾ�ﵽ��ʱĿ�ĵĺ���
* ����           : num: ͣ����ʾ�Ĵ���
* ���         	 : ��
*******************************************************************************/
void Disp_Delay(u32 num)
{
	while(num --)
	{
		Disp(Backup_PTR1,Backup_SIZE);//�ظ���ʾ��һ֡������
	}
}
/*******************************************************************************
* ������         : void Bowen(void)
* ��������		 : ��ʾһȦȦ��С����Ĳ���
* ����           : ��
* ���         	 : ��
*******************************************************************************/
void Bowen(void)
{
	u32 temp1 = 1 << 26;
	u32 temp2 = 150;
	while(temp1 >= 1)
	{
		LED_Disp(temp1);
		delay_ms(temp2);//�ʵ���ʱ
		temp1 >>= 1;
//		temp2 -= 15;
		if(temp1==(1<<15))
		{
			LED17 = 1;
			LED16 = 0;
			delay_ms(temp2);//�ʵ���ʱ
//			temp2 -= 15;
			LED16 = 1;
		}
	}
	LED0 = 1;
}
