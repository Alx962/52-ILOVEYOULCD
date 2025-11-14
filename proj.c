#include "reg52.h"			 //头文件定义

typedef unsigned int u16;	  //对数据类型进行声明
typedef unsigned char u8;

sbit LSA=P3^0;
sbit LSB=P3^1;
sbit LSC=P3^2;

u8 code range[8] ={0xb0,0x38,0x3f,0x3e,0xf9,0x6e,0x3f,0xbe};//I.LOVE.YOU数组，共阴极

void delay(u16 i)		//延时函数
{
	while(i--);	
}

void DigDisplay()	//动态扫描函数
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
		   case(0):
				LSA=1;LSB=1;LSC=1; break;//显示第0位
			case(1):
				LSA=0;LSB=1;LSC=1; break;//显示第1位
			case(2):
				LSA=1;LSB=0;LSC=1; break;//显示第2位
			case(3):	
				LSA=0;LSB=0;LSC=1; break;//显示第3位
			case(4):
				LSA=1;LSB=1;LSC=0; break;//显示第4位
			case(5):
				LSA=0;LSB=1;LSC=0; break;//显示第5位
			case(6):
				LSA=1;LSB=0;LSC=0; break;//显示第6位
			case(7):
				LSA=0;LSB=0;LSC=0; break;//显示第7位	
		}
		P2=range[i];//发送段码
		delay(100); //间隔一段时间扫描，这里调节显示速度
		P2=0x00;//消隐
	}
}

void main()
{	
	while(1)
	{	
		DigDisplay();  //数码管显示函数	
	}		
}