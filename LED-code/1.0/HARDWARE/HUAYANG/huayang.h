#ifndef __HUAYANG_H
#define __HUAYANG_H
#include "sys.h"

//������������ַ��ź�,֧��10��16�ŵ��ַ�
#define DISPLAY_BUFFER_SIZE		(32*10)	
#define BUF1_SIZE (sizeof(BUF1)/sizeof(BUF1[0]))	//������1����
//#define BUF2_SIZE (sizeof(BUF2)/sizeof(BUF2[0]))	//������2����
	
extern u8 BUF1[DISPLAY_BUFFER_SIZE];
extern u8 BUF2[DISPLAY_BUFFER_SIZE];

u8 Get_Centre(u32 size);
void Clear_All(u8 *buf);
void Clear_Line(u32 begin, u32 end);
void Copy_to_Buf(u8 *Source, u8 *Location, u32 cnt);
u8 ZuoYi(u8 *Source, u32 size, u32 begin, u32 end, u8 mode);
u8 YouYi(u8 *Source, u32 size, u32 begin, u32 end, u8 mode);
u8 XiaYi(u8 *buf, u8 *Source, u32 begin, u32 end, u8 mode);
u8 ShangYi(u8 *buf, u8 *Source, u32 begin, u32 end, u8 mode);

#endif
