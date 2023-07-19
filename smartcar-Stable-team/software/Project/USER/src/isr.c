/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2016,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		isr.c
 * @brief      		�жϺ�����
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		Go For It(1325536866)
 * @version    		v1.0
 * @Software 		IAR 7.7 or MDK 5.17
 * @Target core		MK60DN512VLL10
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2016-02-25
 ********************************************************************************************************************/



#include "isr.h"

extern uint8 TIME1flag_1ms   ;     //��ʱ��ʱ���жϱ�־λ
//extern uint8 TIME1flag_10ms  ;
extern uint8 TIME1flag_20ms  ;
//extern uint8 TIME1flag_50ms  ;
//extern uint8 TIME1flag_80ms  ;
//extern uint8 TIME1flag_100ms ;



//-------------------------------------------------------------------------------------------------------------------
//  @brief      PROTA�ж�ִ�к���
//  @return     void   
//  @since      v1.0
//  Sample usage:               ��A�������жϹ����ҷ����жϵ�ʱ����Զ�ִ�иú���
//-------------------------------------------------------------------------------------------------------------------
void PORTA_IRQHandler(void)
{
    //����жϱ�־��һ�ַ���ֱ�Ӳ����Ĵ�����ÿһλ��Ӧһ������
	PORTA->ISFR = 0xffffffff;
	//ʹ�����Ǳ�д�ĺ궨����������жϵ�����
	//PORTA_FLAG_CLR(A1);

}


void PORTC_IRQHandler(void)
{
    //����жϱ�־��һ�ַ���ֱ�Ӳ����Ĵ�����ÿһλ��Ӧһ������
	PORTC->ISFR = 0xffffffff;
	//ʹ�����Ǳ�д�ĺ궨����������жϵ�����
//		ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median);  
//		ftm_quad_clean(ftm2);//��������������
//		ftm_pwm_duty(ftm0,ftm_ch7,600); 
//		ftm_pwm_duty(ftm0,ftm_ch5,0); 	
//				while(ftm_quad_get(ftm2) < 16000);
//	
//			ftm_pwm_duty(ftm0,ftm_ch7,0); 
//		ftm_pwm_duty(ftm0,ftm_ch5,180); 	
//		systick_delay_ms(1000);
//		ftm_pwm_duty(ftm0,ftm_ch7,0); 
//		ftm_pwm_duty(ftm0,ftm_ch5,0);
//		
//			ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median);  
	keycan();
	PORTC_FLAG_CLR(C3);
		PORTC_FLAG_CLR(C4);
//    VSYNC();
}


void DMA0_IRQHandler(void)
{
	DMA_IRQ_CLEAN(DMA_CH0);
    row_finished();
	
}

void PIT0_IRQHandler(void)
{
	PIT_FlAG_CLR(pit0);

}


void PIT2_IRQHandler(void)
{
	PIT_FlAG_CLR(pit2);

	
	
	
		printf("pit2\r\n");

if(0)//��ͣ����·��
{

//				ftm_quad_clean(ftm2);//��������������


////		printf(" ftm_quad_get(ftm2)=%d\r\n",(uint16)ftm_quad_get(ftm2));
//			ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median); 
//		ftm_pwm_duty(ftm0,ftm_ch7,450); 
//		ftm_pwm_duty(ftm0,ftm_ch5,0); 	
//				while(ftm_quad_get(ftm2) < 15000);
			ftm_quad_clean(ftm2);//��������������
			
		//�Ҵ� ��ǰ��
		ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median+Turn_error_max);  
		ftm_pwm_duty(ftm0,ftm_ch7,450); 
		ftm_pwm_duty(ftm0,ftm_ch5,0); 
		while(ftm_quad_get(ftm2) < 9000);
		printf(" youzhuan=%d\r\n",ftm_quad_get(ftm2));
		ftm_quad_clean(ftm2);//��������������
	
		//�������ֱ��
		ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median);  
		ftm_pwm_duty(ftm0,ftm_ch7,450); 
		ftm_pwm_duty(ftm0,ftm_ch5,0); 
		while(ftm_quad_get(ftm2) < 8000);
				printf(" zhizou=%d\r\n",ftm_quad_get(ftm2));
		ftm_quad_clean(ftm2);//��������������

		
		//ֱ�ߺ���ת
		ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median-Turn_error_max);  
		while(ftm_quad_get(ftm2) < 22000);
			printf(" zuozhuan=%d\r\n",ftm_quad_get(ftm2));
		ftm_quad_clean(ftm2);//��������������
	
		
		
		//ǰ��ʱ ��ɲ��
			ftm_pwm_duty(ftm0,ftm_ch7,0); 
		ftm_pwm_duty(ftm0,ftm_ch5,160); 	
		systick_delay_ms(200);
		ftm_pwm_duty(ftm0,ftm_ch7,0); 
		ftm_pwm_duty(ftm0,ftm_ch5,0);
		
			ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median);  


}


if(1)//ͣ����·��
{

				ftm_quad_clean(ftm2);//��������������

////		printf(" ftm_quad_get(ftm2)=%d\r\n",(uint16)ftm_quad_get(ftm2));
//			ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median); 
//		ftm_pwm_duty(ftm0,ftm_ch7,650); 
//		ftm_pwm_duty(ftm0,ftm_ch5,0); 	
//				while(ftm_quad_get(ftm2) < 20000);
				
		
		//ǰ��ʱɲ��ɲ��
		ftm_pwm_duty(ftm0,ftm_ch7,0); 
		ftm_pwm_duty(ftm0,ftm_ch5,600); 	
			systick_delay_ms(50);
		ftm_pwm_duty(ftm0,ftm_ch7,0); 
		ftm_pwm_duty(ftm0,ftm_ch5,0); 	
			systick_delay_ms(50);
			ftm_quad_clean(ftm2);//��������������
			
			
		//��� ������
		ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median-Turn_error_max);  
		ftm_pwm_duty(ftm0,ftm_ch7,0); 
		ftm_pwm_duty(ftm0,ftm_ch5,999); 
		while(ftm_quad_get(ftm2) > -6600);
				ftm_quad_clean(ftm2);//��������������
		printf(" ftm2_-7000=%d\r\n",ftm_quad_get(ftm2));
		
		
		//����ʱ��ɲ��
		ftm_pwm_duty(ftm0,ftm_ch7,200); 
		ftm_pwm_duty(ftm0,ftm_ch5,0); 	
		systick_delay_ms(200);
		ftm_pwm_duty(ftm0,ftm_ch7,0); 
		ftm_pwm_duty(ftm0,ftm_ch5,0);
		
		
				//���������ת
		ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median+Turn_error_max);  
		ftm_pwm_duty(ftm0,ftm_ch7,999); 
		ftm_pwm_duty(ftm0,ftm_ch5,0); 
		while(ftm_quad_get(ftm2) < 100);
				ftm_quad_clean(ftm2);//��������������
		printf(" ftm2_6000=%d\r\n",ftm_quad_get(ftm2));
		
		
		//�������ֱ��
		ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median);  
		ftm_pwm_duty(ftm0,ftm_ch7,999); 
		ftm_pwm_duty(ftm0,ftm_ch5,0); 
		while(ftm_quad_get(ftm2) < 900);
				ftm_quad_clean(ftm2);//��������������
		printf(" ftm2_6000=%d\r\n",ftm_quad_get(ftm2));
		
		//ֱ�ߺ���ת
		ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median-Turn_error_max);  
		while(ftm_quad_get(ftm2) < 26000);
				ftm_quad_clean(ftm2);//��������������
		printf(" ftm2_25000=%d\r\n",ftm_quad_get(ftm2));
		
		
		//ǰ��ʱ ��ɲ��
//			ftm_pwm_duty(ftm0,ftm_ch7,0); 
//		ftm_pwm_duty(ftm0,ftm_ch5,160); 	
//		systick_delay_ms(200);
//		ftm_pwm_duty(ftm0,ftm_ch7,0); 
//		ftm_pwm_duty(ftm0,ftm_ch5,0);
//		
			ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median);  


}
//	ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median-Turn_error_max);  
	
	
	
//	  //���ռ�ձ�����	
//		ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median+Turn_error_max);  
//	 systick_delay_ms(400);   //��ʱ1000����
//	//D7   //�����
//	
//			ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median);  
//	 systick_delay_ms(600);   //��ʱ1000����



//			ftm_pwm_duty(ftm1,ftm_ch1,Direction_Median-Turn_error_max);  
//		 systick_delay_ms(1220);   //��ʱ1000����
//	
//	
//	
	
	
	


disable_irq(PIT2_IRQn);
}


void PIT1_IRQHandler(void)    //PIT1�ж��ó��������ģ�� ���� ���������ź�     1ms����һ���ж�
{
     static uint8  TimeCountTurn = 0 ;     //���򻷵�������
	 static uint8  TimeCountSpeed = 0 ;   //�ٶȻ���������
	 static uint8  TimeCountWave = 0 ;    //����������ź�����
	
	 PIT_FlAG_CLR(pit1);

   TimeCountTurn++;
	 TimeCountSpeed++;
	 TimeCountWave++;	
	
	
	
	
	
	
	
    //��кͶ������
			Read_ADC();//��ȡ�������ֵ
			direction_control(&Turn_error,&Dir_Kp,&Dir_Kd);
	//�ٶȻ�
 if(TimeCountSpeed >= 20 )
   {
		 TimeCountSpeed = 0 ;
			 Speed_control(&SpeedPID_Set,&Spe_Kp,&Spe_Ki,&Spe_Kd);
			/*
      Feedback_Speed = ftm_quad_get(ftm2);              //��ȡ����ٶ�
      ftm_quad_clean(ftm2);
			printf("ftm_quad_get(ftm2)=%d\r\n",Feedback_Speed);
			*/
   }
if(key27)
	 
 if(TimeCountWave >= 5)
	 {

		 TimeCountWave = 0 ;
		 
		 ultrasonic();


	 }
 }


//2019-07-16 00:13:39����
//void PIT1_IRQHandler(void)    //PIT1�ж��ó��������ģ�� ���� ���������ź�     1ms����һ���ж�
//{
//     static uint8  TimeCountTurn = 0 ;     //���򻷵�������
//	 static uint8  TimeCountSpeed = 0 ;   //�ٶȻ���������
//	 static uint8  TimeCountWave = 0 ;    //����������ź�����
//	
//	 PIT_FlAG_CLR(pit1);

//   TimeCountTurn++;
//	 TimeCountSpeed++;
//	 TimeCountWave++;	
//	
//	
//	
//	
//	
//	
//	
//    //��кͶ������
//			Read_ADC();//��ȡ�������ֵ
//			direction_control(&Turn_error,&Dir_Kp,&Dir_Kd);
//	//�ٶȻ�
// if(TimeCountSpeed >= 20 )
//   {
//		 TimeCountSpeed = 0 ;
//			 Speed_control(&SpeedPID_Set,&Spe_Kp,&Spe_Ki,&Spe_Kd);
//			/*
//      Feedback_Speed = ftm_quad_get(ftm2);              //��ȡ����ٶ�
//      ftm_quad_clean(ftm2);
//			printf("ftm_quad_get(ftm2)=%d\r\n",Feedback_Speed);
//			*/
//   }

//	 
// if(TimeCountWave >= 5)
//	 {

//		 TimeCountWave = 0 ;
//		 
//		 ultrasonic();


//	 }

//}



//-------------------------------------------------------------------------------------------------------------------
//  @brief      UART3�ж�ִ�к���
//  @return     void   
//  @since      v1.0
//  Sample usage:               ��UART3�����жϹ����ҷ����жϵ�ʱ����Զ�ִ�иú���
//-------------------------------------------------------------------------------------------------------------------
void UART3_RX_TX_IRQHandler(void)
{
    if(UART3->S1 & UART_S1_RDRF_MASK)                                     //�������ݼĴ�����
    {
        //�û���Ҫ������������
        mt9v032_cof_uart_interrupt();
    }
    if(UART3->S1 & UART_S1_TDRE_MASK )                                    //�������ݼĴ�����
    {
        //�û���Ҫ������������

    }
}


/*
�жϺ������ƣ��������ö�Ӧ���ܵ��жϺ���
Sample usage:��ǰ������DMA0�жϣ�Ȼ��͵�����ȥ���ĸ���DMA0���жϺ������ƣ��ҵ���дһ�������Ƶĺ�������
void DMA0_IRQHandler(void)
{
    ;
}
�ǵý����жϺ������־λ


DMA0_IRQHandler  
DMA1_IRQHandler  
DMA2_IRQHandler  
DMA3_IRQHandler  
DMA4_IRQHandler  
DMA5_IRQHandler  
DMA6_IRQHandler  
DMA7_IRQHandler  
DMA8_IRQHandler  
DMA9_IRQHandler  
DMA10_IRQHandler 
DMA11_IRQHandler 
DMA12_IRQHandler 
DMA13_IRQHandler 
DMA14_IRQHandler 
DMA15_IRQHandler 
DMA_Error_IRQHandler      
MCM_IRQHandler            
FTFL_IRQHandler           
Read_Collision_IRQHandler 
LVD_LVW_IRQHandler        
LLW_IRQHandler            
Watchdog_IRQHandler       
RNG_IRQHandler            
I2C0_IRQHandler           
I2C1_IRQHandler           
SPI0_IRQHandler           
SPI1_IRQHandler           
SPI2_IRQHandler           
CAN0_ORed_Message_buffer_IRQHandler    
CAN0_Bus_Off_IRQHandler                
CAN0_Error_IRQHandler                  
CAN0_Tx_Warning_IRQHandler             
CAN0_Rx_Warning_IRQHandler             
CAN0_Wake_Up_IRQHandler                
I2S0_Tx_IRQHandler                     
I2S0_Rx_IRQHandler                     
CAN1_ORed_Message_buffer_IRQHandler    
CAN1_Bus_Off_IRQHandler                
CAN1_Error_IRQHandler                  
CAN1_Tx_Warning_IRQHandler             
CAN1_Rx_Warning_IRQHandler             
CAN1_Wake_Up_IRQHandler                
Reserved59_IRQHandler                  
UART0_LON_IRQHandler                   
UART0_RX_TX_IRQHandler                 
UART0_ERR_IRQHandler                   
UART1_RX_TX_IRQHandler                 
UART1_ERR_IRQHandler  
UART2_RX_TX_IRQHandler
UART2_ERR_IRQHandler  
UART3_RX_TX_IRQHandler
UART3_ERR_IRQHandler  
UART4_RX_TX_IRQHandler
UART4_ERR_IRQHandler  
UART5_RX_TX_IRQHandler
UART5_ERR_IRQHandler  
ADC0_IRQHandler
ADC1_IRQHandler
CMP0_IRQHandler
CMP1_IRQHandler
CMP2_IRQHandler
FTM0_IRQHandler
FTM1_IRQHandler
FTM2_IRQHandler
CMT_IRQHandler 
RTC_IRQHandler 
RTC_Seconds_IRQHandler  
PIT0_IRQHandler  
PIT1_IRQHandler  
PIT2_IRQHandler  
PIT3_IRQHandler  
PDB0_IRQHandler  
USB0_IRQHandler  
USBDCD_IRQHandler
ENET_1588_Timer_IRQHandler
ENET_Transmit_IRQHandler  
ENET_Receive_IRQHandler
ENET_Error_IRQHandler  
Reserved95_IRQHandler  
SDHC_IRQHandler
DAC0_IRQHandler
DAC1_IRQHandler
TSI0_IRQHandler
MCG_IRQHandler 
LPTimer_IRQHandler 
Reserved102_IRQHandler 
PORTA_IRQHandler 
PORTB_IRQHandler 
PORTC_IRQHandler 
PORTD_IRQHandler 
PORTE_IRQHandler 
Reserved108_IRQHandler
Reserved109_IRQHandler
SWI_IRQHandler 
*/
                

