#ifndef __MYIIC_H
#define __MYIIC_H
//#include "sys.h"  // SMT32
#include "common.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//IIC 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/6
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
   	   		   
//IO方向设置
//#define SDA_IN()  {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=0<<9*2;}	//PB9输入模式
//#define SDA_OUT() {GPIOB->MODER&=~(3<<(9*2));GPIOB->MODER|=1<<9*2;} //PB9输出模式
#define SDA_IN()  gpio_ddr(D0,GPI)   //设置B11为输出模式	
#define SDA_OUT() gpio_ddr(D0,GPO)  //设置B11为输出模式

//IO操作函数	 
#define IIC_SCL    PDout(2) //SCL
#define IIC_SDA    PDout(0) //SDA	 
#define READ_SDA   PDin(0)  //输入SDA 
#define   systick_delay_us_iic   systick_delay_us(180);//IIC延时函数
//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(uint8 txd);			//IIC发送一个字节
uint8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
uint8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

void IIC_Write_One_Byte(uint8 daddr,uint8 addr,uint8 data);
uint8 IIC_Read_One_Byte(uint8 daddr,uint8 addr);	  
#endif
















