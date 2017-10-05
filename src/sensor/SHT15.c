#include "SHT15.h"


/*************************************************************
  Function   ：SHT15_Dly  
  Description：SHT15时序需要的延时
  Input      : none        
  return     : none    
*************************************************************/
void SHT15_Dly(void)
{
 	vTaskDelay( 1 / portTICK_RATE_MS );
}


/*************************************************************
  Function   ：SHT15_Config  
  Description：初始化 SHT15引脚
  Input      : none        
  return     : none    
*************************************************************/
void SHT15_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  __GPIOC_CLK_ENABLE();

  GPIO_InitStruct.Pin = SHT15_DATA_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
  HAL_GPIO_Init(SHT15_DATA_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = SHT15_SCK_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
  HAL_GPIO_Init(SHT15_SCK_PORT, &GPIO_InitStruct);
   SHT15_ConReset();
}

void SHT15_DATAOut(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = SHT15_DATA_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
  HAL_GPIO_Init(SHT15_DATA_PORT, &GPIO_InitStruct);
}

void SHT15_DATAIn(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = SHT15_DATA_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Speed = GPIO_SPEED_MEDIUM;
  HAL_GPIO_Init(SHT15_DATA_PORT, &GPIO_InitStruct);
}

uint8_t SHT15_WriteByte(uint8_t value)
{
    uint8_t i, err = 0;
    
    SHT15_DATAOut();             

    for(i = 0x80; i > 0; i /= 2) 
    {
        if(i & value)
                SHT15_DATA_H();
        else
                SHT15_DATA_L();
        SHT15_Dly();
        SHT15_SCK_H();
        SHT15_Dly();
        SHT15_SCK_L();
        SHT15_Dly();
    }
    SHT15_DATAIn();           
    SHT15_SCK_H();
    err = SHT15_DATA_R();    
    SHT15_SCK_L();

    return err;
}

uint8_t SHT15_ReadByte(uint8_t Ack)
{
    uint8_t i, val = 0;

    SHT15_DATAIn();               
    for(i = 0x80; i > 0; i /= 2) 
    {
        SHT15_Dly();
        SHT15_SCK_H();
        SHT15_Dly();
        if(SHT15_DATA_R())
        {
           val = (val | i);
        }
        SHT15_SCK_L();
    }
    SHT15_DATAOut();            
    if(Ack)
            SHT15_DATA_L();      
    else
            SHT15_DATA_H();    
    SHT15_Dly();
    SHT15_SCK_H();
    SHT15_Dly();
    SHT15_SCK_L();
    SHT15_Dly();

    return val;              
}


/*************************************************************
  Function   ：SHT15_TransStart  
  Description：开始传输信号，时序如下：
                     _____         ________
               DATA:      |_______|
                         ___     ___
               SCK : ___|   |___|   |______        
  Input      : none        
  return     : none    
*************************************************************/
void SHT15_TransStart(void)
{
    SHT15_DATAOut();           

    SHT15_DATA_H();
    SHT15_SCK_L();
    SHT15_Dly();
    SHT15_SCK_H();
    SHT15_Dly();
    SHT15_DATA_L();
    SHT15_Dly();
    SHT15_SCK_L();
    SHT15_Dly();
    SHT15_SCK_H();
    SHT15_Dly();
    SHT15_DATA_H();
    SHT15_Dly();
    SHT15_SCK_L();
}


/*************************************************************
  Function   ：SHT15_ConReset  
  Description：通讯复位，时序如下：
                     _____________________________________________________         ________
               DATA:                                                      |_______|
                        _    _    _    _    _    _    _    _    _        ___     ___
               SCK : __| |__| |__| |__| |__| |__| |__| |__| |__| |______|   |___|   |______
  Input      : none        
  return     : none    
*************************************************************/
void SHT15_ConReset(void)
{
    uint8_t i;

    SHT15_DATAOut();

    SHT15_DATA_H();
    SHT15_SCK_L();

    for(i = 0; i < 9; i++)          
    {
        SHT15_SCK_H();
        SHT15_Dly();
        SHT15_SCK_L();
        SHT15_Dly();
    }
    SHT15_TransStart();          
}

uint8_t SHT15_SoftReset(void)
{
    uint8_t err = 0;

    SHT15_ConReset();           
    err += SHT15_WriteByte(SOFTRESET); 

    return err;
}

uint8_t SHT15_ReadStatusReg(uint8_t *p_value, uint8_t *p_checksum)
{
    uint8_t err = 0;

    SHT15_TransStart();
    err = SHT15_WriteByte(STATUS_REG_R);
    *p_value = SHT15_ReadByte(ACK);
    *p_checksum = SHT15_ReadByte(noACK);
    
    return err;
}



uint8_t SHT15_WriteStatusReg(uint8_t *p_value)
{
        uint8_t err = 0;

        SHT15_TransStart();                     
        err += SHT15_WriteByte(STATUS_REG_W);  
        err += SHT15_WriteByte(*p_value);    

        return err;
}

uint8_t SHT15_Measure(uint16_t *p_value, uint8_t *p_checksum, uint8_t mode)
{
    uint8_t err = 0;
    uint32_t i;
    uint8_t value_H = 0;
    uint8_t value_L = 0;

    SHT15_TransStart();  													                             
    switch(mode)                                                         
    {
    case TEMP:                                      
        err += SHT15_WriteByte(MEASURE_TEMP);						 
        break;
    case HUMI:
        err += SHT15_WriteByte(MEASURE_HUMI);						 
        break;
    default:
        break;
    }
    if(err != 0)
    {
        return err;
    }
    SHT15_DATAIn();																				 
    for(i = 0; i < 1200000; i++)  
    {
        if(SHT15_DATA_R() == 0) break; 										SHT15_Dly(); 
    }
    if(SHT15_DATA_R() == 1)  
    {
        err += 1;																			
        return err;																			 
    }
    value_H = SHT15_ReadByte(ACK);											
    value_L = SHT15_ReadByte(ACK);											
    *p_checksum = SHT15_ReadByte(noACK);								
    *p_value = (value_H << 8) | value_L;									
    return err;
}

void SHT15_Calculate(uint16_t t, uint16_t rh, uint8_t *p_temperature, uint8_t *p_humidity)
{

    const float d1 = -41.55;
    const float d2 = +0.01;
    const float C1 = -4;
    const float C2 = +0.0405;
    const float C3 = -0.0000028;        
    const float T1 = +0.01;
    const float T2 = +0.00008;

    float RH_Lin;                                                             
    float RH_Ture;                                                   
    float temp_C;

    temp_C = d1 + d2 * t;                                                  
    RH_Lin = C1 + C2 * rh + C3 * rh * rh;                          
    RH_Ture = (temp_C -25) * (T1 + T2 * rh) + RH_Lin;         
    RH_Ture = (RH_Ture > 100) ? 100 : RH_Ture;
    RH_Ture = (RH_Ture < 0.1) ? 0.1 : RH_Ture;

    *p_humidity = RH_Ture;
    *p_temperature = temp_C;

}
