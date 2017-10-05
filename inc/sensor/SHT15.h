/*************************************************************
                             \(^o^)/
  Copyright (C), 2013-2020, ZheJiang University of Technology
  File name  : SHT15.h 
  Author     : ziye334    
  Version    : V1.0 
  Data       : 2014/3/10      
  Description: Digital temperature and humidity sensor driver code
  
*************************************************************/
#ifndef __SHT15_H__
#define __SHT15_H__
#include "main.h"

enum {TEMP, HUMI};

/* GPIO��غ궨�� */
#define SHT15_RCC_Periph      GPIOC
#define SHT15_DATA_PIN        GPIO_PIN_1//GPIO_Pin_1
#define SHT15_SCK_PIN         GPIO_PIN_2
#define SHT15_DATA_PORT       GPIOC
#define SHT15_SCK_PORT        GPIOC

#define SHT15_DATA_H()        HAL_GPIO_WritePin(SHT15_DATA_PORT, SHT15_DATA_PIN, GPIO_PIN_SET)   
#define SHT15_DATA_L()        HAL_GPIO_WritePin(SHT15_DATA_PORT, SHT15_DATA_PIN, GPIO_PIN_RESET)                         //����DATA������
#define SHT15_DATA_R()        HAL_GPIO_ReadPin(SHT15_DATA_PORT, SHT15_DATA_PIN)
							  

#define SHT15_SCK_H()         HAL_GPIO_WritePin(SHT15_SCK_PORT, SHT15_SCK_PIN, GPIO_PIN_SET)
#define SHT15_SCK_L()         HAL_GPIO_WritePin(SHT15_SCK_PORT, SHT15_SCK_PIN, GPIO_PIN_RESET)                         //����SCKʱ����

/* ��������غ궨�� */
#define noACK        0
#define ACK          1
                                                                //addr  command         r/w
#define STATUS_REG_W       	 0x06        //000         0011          0          д״̬�Ĵ���
#define STATUS_REG_R       	 0x07        //000         0011          1          ��״̬�Ĵ���
#define MEASURE_TEMP         0x03        //000         0001          1          �����¶�
#define MEASURE_HUMI         0x05        //000         0010          1          ����ʪ��
#define SOFTRESET      		 0x1E        //000         1111          0          ��λ

void SHT15_Init(void);
void SHT15_ConReset(void);
uint8_t SHT15_SoftReset(void);
uint8_t SHT15_Measure(uint16_t *p_value, uint8_t *p_checksum, uint8_t mode);
void SHT15_Calculate(uint16_t t, uint16_t rh,uint8_t *p_temperature, uint8_t *p_humidity);
uint8_t SHT15_Measure_h(uint16_t *p_value, uint8_t *p_checksum, uint8_t mode);


#endif



