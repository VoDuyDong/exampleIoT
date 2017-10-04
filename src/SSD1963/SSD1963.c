#include "SSD1963.h"
// Color
uint32_t  _color;
// Clipping region control
uint16_t _clipRgn;
// Clipping region borders
uint16_t _clipLeft;
uint16_t _clipTop;
uint16_t _clipRight;
uint16_t _clipBottom;

// Active Page
uint8_t  _activePage;
// Visual Page
uint8_t  _visualPage;

// ssd1963 specific
uint8_t _gpioStatus = 0;


void DelayMs (int ms) 
{
 vTaskDelay( ms*10 / portTICK_RATE_MS );
}

void WriteCommand(uint16_t cmd)
{ 
	/* Write cmd */
  LCD_REG = cmd;	
} 

void WriteData(uint16_t data)
{ 
	/* Write 16-bit data */
  LCD_RAM = data;
} 

uint16_t ReadData(void)
{
	/* Read 16-bit data */
  return LCD_RAM;
}

/* FSMC initialization function */
void MX_FSMC_Init(void)
{
<<<<<<< HEAD
	int FSMC_Bank = 0;
	FSMC_Bank1->BTCR[FSMC_Bank+1] = FSMC_BTR1_ADDSET_1 | FSMC_BTR1_DATAST_1;

	// Bank1 NOR/SRAM control register configuration
	FSMC_Bank1->BTCR[FSMC_Bank] = FSMC_BCR1_MWID_0 | FSMC_BCR1_WREN | FSMC_BCR1_MBKEN;

	SRAM_HandleTypeDef sram_init_struct;
	FSMC_NORSRAM_TimingTypeDef Timing;

	/** Perform the SRAM1 memory initialization sequence
	*/
	sram_init_struct.Instance = FSMC_NORSRAM_DEVICE;
	sram_init_struct.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
	/* hsram1 */
	sram_init_struct.Init.NSBank = FSMC_NORSRAM_BANK1;
	sram_init_struct.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
	sram_init_struct.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
	sram_init_struct.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
	sram_init_struct.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
	sram_init_struct.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
	sram_init_struct.Init.WrapMode = FSMC_WRAP_MODE_DISABLE;
	sram_init_struct.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
	sram_init_struct.Init.WriteOperation = FSMC_WRITE_OPERATION_ENABLE;
	sram_init_struct.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
	sram_init_struct.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
	sram_init_struct.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
	sram_init_struct.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
	/* Timing */

	Timing.AddressSetupTime = 5;
	Timing.AddressHoldTime = 1;
	Timing.DataSetupTime = 9;
	Timing.BusTurnAroundDuration = 0;
	Timing.CLKDivision = 1;
	Timing.DataLatency = 0;
	Timing.AccessMode = FSMC_ACCESS_MODE_A;

	/* ExtTiming */

	HAL_SRAM_Init(&sram_init_struct, &Timing,&Timing);
}

void HAL_FSMC_MspInit(void)
{
	static uint8_t FSMC_Initialized=0;
	GPIO_InitTypeDef GPIO_InitStruct;
	if (FSMC_Initialized) {
	return;
	}
	FSMC_Initialized = 1;
	/* Peripheral clock enable */
	__FSMC_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();
	__GPIOA_CLK_ENABLE();
	__GPIOE_CLK_ENABLE();


	GPIO_InitStruct.Pin =	GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
							|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
							|GPIO_PIN_14|GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF12_FSMC;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	GPIO_InitStruct.Pin =	GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
							|GPIO_PIN_14|GPIO_PIN_15 | GPIO_PIN_7
							|GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4| GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF12_FSMC;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET); 
=======
SRAM_HandleTypeDef sram_init_struct;
FSMC_NORSRAM_TimingTypeDef fsmc_norsram_timing_struct = {0};

sram_init_struct.Instance = FSMC_NORSRAM_DEVICE;
sram_init_struct.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;

fsmc_norsram_timing_struct.AddressSetupTime       = 0;
fsmc_norsram_timing_struct.AddressHoldTime        = 0; // n/a for SRAM mode A
fsmc_norsram_timing_struct.DataSetupTime          = 0x0A;
fsmc_norsram_timing_struct.BusTurnAroundDuration  = 0; 
fsmc_norsram_timing_struct.CLKDivision            = 0; // n/a for SRAM mode A
fsmc_norsram_timing_struct.DataLatency            = 0; // n/a for SRAM mode A
fsmc_norsram_timing_struct.AccessMode             = FSMC_ACCESS_MODE_A;

// fsmc_norsram_timing_struct.AddressSetupTime=0x00;
// fsmc_norsram_timing_struct.DataSetupTime=0x0A;
// fsmc_norsram_timing_struct.CLKDivision=0x0;
// fsmc_norsram_timing_struct.AccessMode=FSMC_ACCESS_MODE_A;

sram_init_struct.Init.NSBank             = FSMC_NORSRAM_BANK1;
sram_init_struct.Init.DataAddressMux     = FSMC_DATA_ADDRESS_MUX_DISABLE;
sram_init_struct.Init.MemoryType         = FSMC_MEMORY_TYPE_SRAM;
sram_init_struct.Init.MemoryDataWidth    = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
sram_init_struct.Init.BurstAccessMode    = FSMC_BURST_ACCESS_MODE_DISABLE;
sram_init_struct.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
sram_init_struct.Init.WrapMode           = FSMC_WRAP_MODE_DISABLE;
sram_init_struct.Init.WaitSignalActive   = FSMC_WAIT_TIMING_DURING_WS;
sram_init_struct.Init.WriteOperation     = FSMC_WRITE_OPERATION_ENABLE;
sram_init_struct.Init.WaitSignal         = FSMC_WAIT_SIGNAL_DISABLE;
sram_init_struct.Init.ExtendedMode       = FSMC_EXTENDED_MODE_DISABLE; // maybe enable?
sram_init_struct.Init.AsynchronousWait   = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
sram_init_struct.Init.WriteBurst         = FSMC_WRITE_BURST_DISABLE;


HAL_SRAM_Init(&sram_init_struct, &fsmc_norsram_timing_struct, NULL);
  // __HAL_RCC_FSMC_CLK_ENABLE();

  // int FSMC_Bank = 0;
  // FSMC_Bank1->BTCR[FSMC_Bank+1] = FSMC_BTR1_ADDSET_1 | FSMC_BTR1_DATAST_1;

  // // Bank1 NOR/SRAM control register configuration
  // FSMC_Bank1->BTCR[FSMC_Bank] = FSMC_BCR1_MWID_0 | FSMC_BCR1_WREN | FSMC_BCR1_MBKEN;

  // SRAM_HandleTypeDef sram_init_struct;
  // FSMC_NORSRAM_TimingTypeDef Timing;
 
  // /** Perform the SRAM1 memory initialization sequence
  // */
  // sram_init_struct.Instance = FSMC_NORSRAM_DEVICE;
  // sram_init_struct.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
  // /* hsram1 */
  // sram_init_struct.Init.NSBank = FSMC_NORSRAM_BANK1;
  // sram_init_struct.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
  // sram_init_struct.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
  // sram_init_struct.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
  // sram_init_struct.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
  // sram_init_struct.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  // sram_init_struct.Init.WrapMode = FSMC_WRAP_MODE_DISABLE;
  // sram_init_struct.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
  // sram_init_struct.Init.WriteOperation = FSMC_WRITE_OPERATION_ENABLE;
  // sram_init_struct.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
  // sram_init_struct.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
  // sram_init_struct.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  // sram_init_struct.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
  // /* Timing */
  // Timing.AddressSetupTime = 5;
  // Timing.AddressHoldTime = 1;
  // Timing.DataSetupTime = 9;
  // Timing.BusTurnAroundDuration = 0;
  // Timing.CLKDivision = 1;
  // Timing.DataLatency = 0;
  // Timing.AccessMode = FSMC_ACCESS_MODE_A;
  // /* ExtTiming */
 
  // HAL_SRAM_Init(&sram_init_struct, &Timing,&Timing);
 
 
}
 int FSMC_Initialized=0;

void HAL_FSMC_MspInit(void){

  GPIO_InitTypeDef GPIO_InitStruct;
  if (FSMC_Initialized) {
    return;
  }
  FSMC_Initialized = 1;
  /* Peripheral clock enable */
  __FSMC_CLK_ENABLE();
  __GPIOD_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
  __GPIOE_CLK_ENABLE();


  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          		  |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                         		  |GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF12_FSMC;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
 
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF12_FSMC;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
  
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET); 
>>>>>>> 1431b464f78c23b93aa0524273a82cd0c40c6d30
}

void GPIO_WR(uint8_t pin, uint8_t state)
{
	if(state==1)
		_gpioStatus = _gpioStatus|pin;
	else
		_gpioStatus = _gpioStatus&(~pin);

	WriteCommand(0xBA);				// Set GPIO value
	WriteData(_gpioStatus);
}


void ResetDevice(void)
{
<<<<<<< HEAD
=======
	//MX_FSMC_Init();
>>>>>>> 1431b464f78c23b93aa0524273a82cd0c40c6d30
	HAL_FSMC_MspInit();
	MX_FSMC_Init();
	//Set MN(multipliers) of PLL, VCO = crystal freq * (N+1)
	//PLL freq = VCO/M with 250MHz < VCO < 800MHz
	//The max PLL freq is around 120MHz. To obtain 120MHz as the PLL freq
//	WriteCommand(0x0000,0x0001);
//	DelayMs(5); // Delay_10ms 50 ms 
	///////////////////////////////////
							 //DelayMs(5); // delay 50 ms 
	WriteCommand(0x00E2);
							//PLL multiplier, set PLL clock to 120M
	WriteData(0x0023);  	 //N=0x36 for 6.5M, 0x23 for 10M crystal
	WriteData(0x0002);
	WriteData(0x0004);
	
	WriteCommand(0x00E0);	DelayMs(1);  // PLL enable
	WriteData(0x0001);		DelayMs(1);
						
	WriteCommand(0x00E0);
	WriteData(0x0003);		DelayMs(1);
							DelayMs(1);
	WriteCommand(0x0001);  // software reset
							DelayMs(1);
	WriteCommand(0x00E6);	DelayMs(1);	//PLL setting for PCLK, depends on resolution
	WriteData(0x0001);
	WriteData(0x0033);
	WriteData(0x0032);		DelayMs(1);

	WriteCommand(0x0036);
	WriteData(0x000a); 

	
	//Set panel mode, varies from individual manufacturer
	WriteCommand(0xB0);
	WriteData(0x10);				// set 18-bit for 7" panel TYX700TFT800480
	WriteData(0x80);				// set TTL mode
	WriteData((DISP_HOR_RESOLUTION-1)>>8); //Set panel size
	WriteData(DISP_HOR_RESOLUTION-1);
	WriteData((DISP_VER_RESOLUTION-1)>>8);
	WriteData(DISP_VER_RESOLUTION-1);
	WriteData(0x00);				//RGB sequence

	//Set horizontal period
	WriteCommand(0xB4);
	#define HT (DISP_HOR_RESOLUTION+DISP_HOR_PULSE_WIDTH+DISP_HOR_BACK_PORCH+DISP_HOR_FRONT_PORCH)
	WriteData((HT-1)>>8);	
	WriteData(HT-1);
	#define HPS (DISP_HOR_PULSE_WIDTH+DISP_HOR_BACK_PORCH)
	WriteData((HPS-1)>>8);
	WriteData(HPS-1);
	WriteData(DISP_HOR_PULSE_WIDTH-1);
	WriteData(0x00);
	WriteData(0x00);
	WriteData(0x00);

	//Set vertical period
	WriteCommand(0xB6);
	#define VT (DISP_VER_PULSE_WIDTH+DISP_VER_BACK_PORCH+DISP_VER_FRONT_PORCH+DISP_VER_RESOLUTION)
	WriteData((VT-1)>>8);
	WriteData(VT-1);
	#define VSP (DISP_VER_PULSE_WIDTH+DISP_VER_BACK_PORCH)
	WriteData((VSP-1)>>8);
	WriteData(VSP-1);
	WriteData(DISP_VER_PULSE_WIDTH-1);
	WriteData(0x00);
	WriteData(0x00);
	
	//Set pixel format, i.e. the bpp
/*	WriteCommand(0x3A);
	WriteData(0x55); 				// set 16bpp			   */

	//Set pixel data interface
	WriteCommand(0xF0);
#ifdef USE_16BIT_PMP
	WriteData(0x03);				//16-bit(565 format) data for 16bpp PIC32MX only
#else
	WriteData(0x00);				//8-bit data for 16bpp, PIC24 series
#endif


	WriteCommand(0x29);				// Turn on display; show the image on display		
}

/*********************************************************************
* Function:  SetArea(start_x,start_y,end_x,end_y)
*
* PreCondition: SetActivePage(page)
*
* Input: start_x, end_x	- start column and end column
*		 start_y,end_y 	- start row and end row position (i.e. page address)
*
* Output: none
*
* Side Effects: none
*
* Overview: defines start/end columns and start/end rows for memory access
*			from host to SSD1963
* Note: none
********************************************************************/
void SetArea(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t end_y)
{
	uint32_t offset;

	offset = (uint16_t)_activePage*(GetMaxY()+1);

	start_y = offset + start_y;
	end_y   = offset + end_y;

	WriteCommand(CMD_SET_COLUMN);
	WriteData(start_x>>8);
	WriteData(start_x);
	WriteData(end_x>>8);
	WriteData(end_x);
	
	WriteCommand(CMD_SET_PAGE);
	WriteData(start_y>>8);
	WriteData(start_y);
	WriteData(end_y>>8);
	WriteData(end_y);
}

void SetBacklight(uint8_t intensity)
{
	WriteCommand(0xBE);			// Set PWM configuration for backlight control
	WriteData(0x0E);			// PWMF[7:0] = 14, PWM base freq = PLL/(256*(1+14))/256 = 
								// 122Hz for a PLL freq = 120MHz
	WriteData(intensity);		// Set duty cycle, from 0x00 (total pull-down) to 0xFF 
								// (99% pull-up , 255/256)
	WriteData(0x01);			// PWM enabled and controlled by host (mcu)
	WriteData(0x00);
	WriteData(0x00);
	WriteData(0x00);
}

uint16_t PwmValue[6];

void GetBacklight(void)
{
	WriteCommand(0xBF);			// Set PWM configuration for backlight control
	PwmValue[0] = ReadData();			// PWMF[7:0] = 2, PWM base freq = PLL/(256*(1+5))/256 = 
								// 300Hz for a PLL freq = 120MHz
	PwmValue[1] = ReadData();		// Set duty cycle, from 0x00 (total pull-down) to 0xFF 
								// (99% pull-up , 255/256)
	PwmValue[2] = ReadData();			// PWM enabled and controlled by host (mcu)
	PwmValue[3] = ReadData();
	PwmValue[4] = ReadData();
	PwmValue[5] = ReadData();
}

void GetPllStatus(void)
{
	WriteCommand(0xE4);			
	PwmValue[0] = ReadData();			
}

void LCD_SetPoint(uint16_t Xpos,uint16_t Ypos,uint16_t point)
{
  if(_clipRgn){
		if(Xpos<_clipLeft)
			return;
		if(Xpos>_clipRight)
			return;
		if(Ypos<_clipTop)
			return;
		if(Ypos>_clipBottom)
			return;
	}
  	
	SetArea(Xpos,Ypos,GetMaxX(),GetMaxY());
	WriteCommand(CMD_WR_MEMSTART);
	WriteData(point);
}

/*********************************************************************
* Function: void ClearDevice(void)
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: clears screen with current color 
*
* Note: none
*
********************************************************************/
void ClearDevice(uint16_t StartX,uint16_t StartY,uint16_t EndX,uint16_t EndY,uint16_t color)
{
//	uint32_t     counter;
	uint32_t xcounter, ycounter;

	SetArea(StartX,StartY,EndX,EndY);

	WriteCommand(CMD_WR_MEMSTART);

	for(ycounter=StartY;ycounter<EndY+1;ycounter++)
	{
		for(xcounter=StartX;xcounter<EndX+1;xcounter++)
		{
			WriteData(color);
		}
	}		 
}
void LCD_DrawPicture(uint16_t StartX,uint16_t StartY,uint16_t EndX,uint16_t EndY, const unsigned short *pic)
{
  uint16_t  i;

  SetArea(StartX,StartY,EndX+StartX-1,EndY+StartY-1);
  WriteCommand(CMD_WR_MEMSTART);
  for (i=0;i<(EndX*EndY);i++)
  {
      WriteData(*pic++);
  }
}


void WriteData_Prepare(void)
{
	WriteCommand(0x002C);
}


void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos)
{
	WriteCommand(0x002A);	
	WriteData(Xpos>>8);	    
	WriteData(Xpos&0x00ff);
	WriteData(479>>8);	    
	WriteData(479&0x00ff);
    WriteCommand(0x002b);	
	WriteData(Ypos>>8);	    
	WriteData(Ypos&0x00ff);
	WriteData(271>>8);	    
	WriteData(271&0x00ff);
}

void LCD_DrawPoint(uint16_t xsta, uint16_t ysta, uint16_t color)
{
	LCD_SetCursor(xsta, ysta);  /*\C9\E8\D6ù\E2\B1\EAλ\D6\C3  */
	WriteData_Prepare();           /*\BF\AAʼд\C8\EBGRAM */
	WriteData(color); 

}

///////////=========================================================================================

void LCD_DrawLine( uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1 , uint16_t color)
{
  short dx,dy;
  short temp;

  if( x0 > x1 )
  {
    temp = x1;
    x1 = x0;
    x0 = temp;   
  }
  if( y0 > y1 )
  {
    temp = y1;
    y1 = y0;
    y0 = temp;   
  }

  dx = x1-x0;
  dy = y1-y0;

  if( dx == 0 )
  {
    do
    { 
      LCD_SetPoint(x0, y0, color);
      y0++;
    }
    while( y1 >= y0 ); 
    return; 
  }
  if( dy == 0 )
  {
    do
    {
      LCD_SetPoint(x0, y0, color);
      x0++;
    }
    while( x1 >= x0 ); 
		return;
  }

	/* Based on Bresenham's line algorithm  */
  if( dx > dy )
  {
    temp = 2 * dy - dx;
    while( x0 != x1 )
    {
	    LCD_SetPoint(x0,y0,color);
	    x0++;
	    if( temp > 0 )
	    {
	      y0++;
	      temp += 2 * dy - 2 * dx; 
	 	  }
      else         
      {
			  temp += 2 * dy;
			}       
    }
    LCD_SetPoint(x0,y0,color);
  }  
  else
  {
    temp = 2 * dx - dy;
    while( y0 != y1 )
    {
	  LCD_SetPoint(x0,y0,color);     
      y0++;                 
      if( temp > 0 )           
      {
        x0++;               
        temp+=2*dy-2*dx; 
      }
      else
	  {
        temp += 2 * dy;
	  }
    } 
    LCD_SetPoint(x0,y0,color);
  }
} 
void LCD_DrawRectangle(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color)
{
	LCD_DrawLine(xsta, ysta, xend, ysta, color);
	LCD_DrawLine(xsta, ysta, xsta, yend, color);
	LCD_DrawLine(xsta, yend, xend, yend, color);
	LCD_DrawLine(xend, ysta, xend, yend, color);
} 

void FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
	uint16_t x_index, y_index;

	if (x > 800)
		x = 800;
	if (y > 480)
		y = 480;

	if ((x+w) > 800)
		w = 800 - x;

	if ((y+h) > 480)
		h = 480 - y;

	for(x_index = x; x_index < x+w; x_index++)
	{
		for(y_index = y; y_index < y+h; y_index++)
		{
			LCD_SetPoint(x_index, y_index, color);
		}
	}

}

/* text
//void tft_putchar98x128(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
//{
//	static uint16_t n=0,m=0;
//	ClearDevice(x,y,n,m,White);
//	if((y>GetMaxX()-98)||(x>GetMaxY()-128)) return;
//	uint8_t i,j,k,temp,countx=0, county=0;
//	
//	SetArea(x,y,x+98-1,y+128-1); 

//	for(i=0;i<128/8;i++)
//	{
//		for(j=0;j<8;j++)
//		{
//			for(k=0;k<70;k++)
//			{
////				temp=Digital726x48[(data-' ')*(48/8)*26+k*(48/8)+i];
//				temp=Digital98x128[(data-' ')*(128/8)*98+k*(128/8)+i];
//					if(temp&(0x01<<j))
//					{
//						LCD_SetPoint(y+k,x+(8*i+j),charColor);
//						
//					}
//					else
//					{
//						//if(!(bkColor==Null))
//							LCD_SetPoint(y+k,x+(8*i+j),bkColor);   \B1\B3\BE\B0\D1\D5ɫ 
//									
//					}
//				}
//			}
//		}
//	n=y+k;		m=x+(8*i+j);
//	}

//void tft_puts98x128(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
//{
//	uint8_t i=0;
//	  while(*(string+i)!='\0')
//    {       
//				tft_putchar98x128(column,row,*(string+i),charColor,bkColor);
//        row+=70;
//        i++;
//    }  
//}
*/
uint16_t w ;
uint16_t offset=0;
uint8_t asccii;
uint16_t i,j,k,temp2;
uint16_t size;
uint16_t sizeByteLine;
uint16_t a,b;
void number_48pts(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
{
	asccii = (uint8_t)data;
	w = dSDigital_36ptDescriptors[asccii-45][0];
	offset =  dSDigital_36ptDescriptors[asccii-45][1];
  size = 6*w;
  sizeByteLine = (size/w);
	for(i=offset;i<offset+size;i+=(size/w)) //row
	{
		for(j=0;j<sizeByteLine;j++) //col
		{
			temp2=dSDigital_36ptBitmaps[i+j];
			for(k=0;k<8;k++)
			{
					if(temp2 &(0x01<<(7-k)))
					{
						a=x+(j*8)+k;
						b=y+((i-offset)/(size/w));
						LCD_SetPoint(b,a,charColor);
					}
			}
		}
	}
}
void Guitext_number_48pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
{
	uint8_t i=0;
	  while(*(string+i)!='\0')
    {
				number_48pts(column,row,*(string+i),charColor,bkColor);
        row+=(size/sizeByteLine)+3;
        i++;
    }  
}

void text_28pts(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
{
	asccii = (uint8_t)data;
	w = eurostileExtended_28ptDescriptors[asccii-72][0];
	offset =  eurostileExtended_28ptDescriptors[asccii-72][1];
  size = 5*w;
  sizeByteLine = (size/w);
	for(i=offset;i<offset+size;i+=(size/w)) //row
	{
		for(j=0;j<sizeByteLine;j++) //col
		{
			temp2=eurostileExtended_28ptBitmaps[i+j];
			for(k=0;k<8;k++)
			{
					if(temp2 &(0x01<<(7-k)))
					{
						a=x+(j*8)+k;
						b=y+((i-offset)/(size/w));
						LCD_SetPoint(b,a,charColor);
					}
				}
			}
		}
}
void Guitext_text_28pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
{
	uint8_t i=0;
	  while(*(string+i)!='\0')
    {
				text_28pts(column,row,*(string+i),charColor,bkColor);
        row+=(size/sizeByteLine)+3;
        i++;
    }  
}
void text_18pts(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
{
	asccii = (uint8_t)data;
	w = eurostileExtended_18ptDescriptors[asccii-49][0];
	offset =  eurostileExtended_18ptDescriptors[asccii-49][1];
  size = 3*w;
  sizeByteLine = (size/w);
	for(i=offset;i<offset+size;i+=(size/w)) //row
	{
		for(j=0;j<sizeByteLine;j++) //col
		{
			temp2=eurostileExtended_18ptBitmaps[i+j];
			for(k=0;k<8;k++)
			{
					if(temp2 &(0x01<<(7-k)))
					{
						a=x+(j*8)+k;
						b=y+((i-offset)/(size/w));
						LCD_SetPoint(b,a,charColor);
					}
				}
			}
		}
}
void Guitext_text_18pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
{
	uint8_t i=0;
	  while(*(string+i)!='\0')
    {
				text_18pts(column,row,*(string+i),charColor,bkColor);
        row+=(size/sizeByteLine)+3;
        i++;
    }  
}
void text_72pts(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
{
	asccii = (uint8_t)data;
	w = digital_72ptDescriptors[asccii-37][0];
	offset =  digital_72ptDescriptors[asccii-37][1];
  size = 9*w;
  sizeByteLine = (size/w);
	for(i=offset;i<offset+size;i+=(size/w)) //row
	{
		for(j=0;j<sizeByteLine;j++) //col
		{
			temp2=digital_72ptBitmaps[i+j];
			for(k=0;k<8;k++)
			{
				a=x+(j*8)+k;
				b=y+((i-offset)/(size/w));
					if(temp2 &(0x01<<(7-k)))
					{
						LCD_SetPoint(b,a,charColor);
					}
				}
			}
		}
}
void Guitext_text_72pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
{
	uint8_t i=0;
	  while(*(string+i)!='\0')
    {
				text_72pts(column,row,*(string+i),charColor,bkColor);
        row+=(size/sizeByteLine)+5;
        i++;
    }  
}
void text_27pts(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
{
	asccii = (uint8_t)data;
	w = digital_28ptDescriptors[asccii-37][0];
	offset =  digital_28ptDescriptors[asccii-37][1];
  size = 4*w;
  sizeByteLine = (size/w);
	for(i=offset;i<offset+size;i+=(size/w)) //row
	{
		for(j=0;j<sizeByteLine;j++) //col
		{
			temp2=digital_28ptBitmaps[i+j];
			for(k=0;k<8;k++)
			{
					if(temp2 &(0x01<<(7-k)))
					{
						a=x+(j*8)+k;
						b=y+((i-offset)/(size/w));
						LCD_SetPoint(b,a,charColor);
					}
				}
			}
		}
}
void Guitext_text_27pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
{
	uint8_t i=0;
	  while(*(string+i)!='\0')
    {
				text_27pts(column,row,*(string+i),charColor,bkColor);
        row+=(size/sizeByteLine)+3;
        i++;
    }  
}
void text_35pts(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
{
	asccii = (uint8_t)data;
	w = dSDigital_35ptDescriptors[asccii-70][0];
	offset =  dSDigital_35ptDescriptors[asccii-70][1];
  size = 4*w;
  sizeByteLine = (size/w);
	for(i=offset;i<offset+size;i+=(size/w)) //row
	{
		for(j=0;j<sizeByteLine;j++) //col
		{
			temp2=dSDigital_35ptBitmaps[i+j];
			for(k=0;k<8;k++)
			{
					if(temp2 &(0x01<<(7-k)))
					{
						a=x+(j*8)+k;
						b=y+((i-offset)/(size/w));
						LCD_SetPoint(b,a,charColor);
					}
				}
			}
		}
}
void Guitext_text_35pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
{
	uint8_t i=0;
	  while(*(string+i)!='\0')
    {
				text_35pts(column,row,*(string+i),charColor,bkColor);
        row+=(size/sizeByteLine)+3;
        i++;
    }  
}


void text_72dspts(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
{
	asccii = (uint8_t)data;
	w = dSDigital_72ptDescriptors[asccii-37][0];
	offset =  dSDigital_72ptDescriptors[asccii-37][1];
  size = 8*w;
  sizeByteLine = (size/w);
	for(i=offset;i<offset+size;i+=(size/w)) //row
	{
		for(j=0;j<sizeByteLine;j++) //col
		{
			temp2=dSDigital_72ptBitmaps[i+j];
			for(k=0;k<8;k++)
			{
					if(temp2 &(0x01<<(7-k)))
					{
						a=x+(j*8)+k;
						b=y+((i-offset)/(size/w));
						LCD_SetPoint(b,a,charColor);
					}
				}
			}
		}
}
void Guitext_text_72dspts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
{
	uint8_t i=0;
	  while(*(string+i)!='\0')
    {
				text_72dspts(column,row,*(string+i),charColor,bkColor);
        row+=(size/sizeByteLine)+3;
        i++;
    }  
}
void text_18dspts(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
{
	asccii = (uint8_t)data;
	w = dSDigital_18ptDescriptors[asccii-65][0];
	offset =  dSDigital_18ptDescriptors[asccii-65][1];
  size = 2*w;
  sizeByteLine = (size/w);
	for(i=offset;i<offset+size;i+=(size/w)) //row
	{
		for(j=0;j<sizeByteLine;j++) //col
		{
			temp2=dSDigital_18ptBitmaps[i+j];
			for(k=0;k<8;k++)
			{
					if(temp2 &(0x01<<(7-k)))
					{
						a=x+(j*8)+k;
						b=y+((i-offset)/(size/w));
						LCD_SetPoint(b,a,charColor);
					}
				}
			}
		}
}
void Guitext_text_18dspts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
{
	uint8_t i=0;
	  while(*(string+i)!='\0')
    {
				text_18dspts(column,row,*(string+i),charColor,bkColor);
        row+=(size/sizeByteLine)+3;
        i++;
    }  
}


void text_eurostile_28pt(uint16_t x,uint16_t y,uint8_t data,unsigned short charColor,unsigned short bkColor)
{
	asccii = (uint8_t)data;
	w = eurostile_28ptDescriptors[asccii-35][0];
	offset =  eurostile_28ptDescriptors[asccii-35][1];
  size = 4*w;
  sizeByteLine = (size/w);
	for(i=offset;i<offset+size;i+=(size/w)) //row
	{
		for(j=0;j<sizeByteLine;j++) //col
		{
			temp2=eurostile_28ptBitmaps[i+j];
			for(k=0;k<8;k++)
			{
					if(temp2 &(0x01<<(7-k)))
					{
						a=x+(j*8)+k;
						b=y+((i-offset)/(size/w));
						LCD_SetPoint(b,a,charColor);
					}
				}
			}
		}
}
void Guitext_text_eurostile_28pt(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor)
{
	uint8_t i=0;
	  while(*(string+i)!='\0')
    {
				text_eurostile_28pt(column,row,*(string+i),charColor,bkColor);
        row+=(size/sizeByteLine)+3;
        i++;
    }  
}
