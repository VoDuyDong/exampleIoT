/*****************************************************************************
 *  Solomon Systech. SSD1963 LCD controller driver
 *****************************************************************************
 * FileName:        SSD1963.h
 * Processor:       STM32F10X
 * Compiler:       	RealView MDK
 * Company:			PowerMCU Company
 * Remarks:			The origin of this file was the ssd1926.c driver released
 *					by Microchip Technology Incorporated. 
 * Versions:        1.0
 *
 * Author:          PowerAVR 	    2010/06/03
 * www.PowerMCU.com
 * www.PowerAVR.com
******************************************************************************/

#ifndef _SSD1963_H
#define _SSD1963_H

//include the command table for SSD1963
#include "SSD1963_CMD.h"
#include "main.h"
//#include "AsciiLib_65k.h"
#include "dSDigital_36pt.h"
#include "EurostileExtended28pts.h"
#include "EurostileExtended18pts.h"
#include "Digital72pt.h"




/* 使用总线方式时定义地址 */
/* 挂在不同的BANK,使用不同地址线时请自行换算地址 */
#define LCD_REG              (*((volatile unsigned short *) 0x60000000)) /* RS = 0 */
#define LCD_RAM              (*((volatile unsigned short *) 0x60020000)) /* RS = 1 */

///////////// GRAPHICS DISPLAYS CODES FOR DRIVER LAYER ////////////// 
#define TYX700TFT800480				101
//#define TYX350TFT320240				102	//3.5" TFT LCD
//#define TYX430TFT480272				103
#define DISPLAY_PANEL		TYX350TFT320240

#define USE_16BIT_PMP


	/*********************************************************************
	* Overview: Image orientation (can be 0, 90, 180, 270 degrees).
	*********************************************************************/	
  	#define DISP_ORIENTATION    0
	/*********************************************************************
	* Overview: Panel Data Width (R,G,B) in (6,6,6)
	*********************************************************************/
	#define DISP_DATA_WIDTH                 18
	/*********************************************************************
	* Overview: Horizontal and vertical display resolution
	*                  (from the glass datasheet).
	*********************************************************************/
	#define DISP_HOR_RESOLUTION 800
	#define DISP_VER_RESOLUTION 480
	/*********************************************************************
	* Overview: Horizontal synchronization timing in pixels
	*                  (from the glass datasheet).
	*********************************************************************/
	#define DISP_HOR_PULSE_WIDTH		1
	#define DISP_HOR_BACK_PORCH			210
	#define DISP_HOR_FRONT_PORCH		45	
	/*********************************************************************
	* Overview: Vertical synchronization timing in lines
	*                  (from the glass datasheet).
	*********************************************************************/
	#define DISP_VER_PULSE_WIDTH		1
	#define DISP_VER_BACK_PORCH			34	
	#define DISP_VER_FRONT_PORCH		10
	/*********************************************************************
	* Definition for SPI interface for SSD1963 
	* Hardware dependent!
	*********************************************************************/
	#define GPIO3 3
	#define GPIO2 2
	#define GPIO1 1
	#define GPIO0 0
	#define LCD_RESET 	0
	#define LCD_SPENA	0
	#define LCD_SPCLK	0
	#define LCD_SPDAT	0
	/* End of definition for DISPLAY_PANEL == TYX700TFT800480 */


#if (DISP_ORIENTATION == 90) || (DISP_ORIENTATION == 270)
	#define	GetMaxX() 			(DISP_VER_RESOLUTION-1)	
#elif (DISP_ORIENTATION == 0) || (DISP_ORIENTATION == 180)
	#define	GetMaxX() 			(DISP_HOR_RESOLUTION-1)
#endif

#if (DISP_ORIENTATION == 90) || (DISP_ORIENTATION == 270)
	#define	GetMaxY() 			(DISP_HOR_RESOLUTION-1)
#elif (DISP_ORIENTATION == 0) || (DISP_ORIENTATION == 180)
	#define	GetMaxY() 			(DISP_VER_RESOLUTION-1)
#endif

                             
/* RGB color definitions */
#define Black           0x0000		/*   0,   0,   0 */
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255, 0   */
#define White           0xFFFF      /* 255, 255, 255 */
#define MAX_X						800
#define MAX_Y						480

#define POINT_COLOR RED
#define BACK_COLOR	0xFFFF

void DelayMs (int cnt);
void ResetDevice(void);
void SetBacklight(uint8_t intensity);
void ClearDevice(uint16_t StartX,uint16_t StartY,uint16_t EndX,uint16_t EndY,uint16_t color);
void LCD_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void LCD_DrawPicture(uint16_t StartX,uint16_t StartY,uint16_t EndX,uint16_t EndY,const unsigned short *pic);
void LCD_DrawPicture1(uint16_t StartX,uint16_t StartY,uint16_t Xend,uint16_t Yend,const unsigned short *pic);
void LCD_DrawRectangle(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color);
void LCD_DrawLine(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color);
void tft_puts98x128(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);
void Guitext_number_48pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);
void Guitext_text_28pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);
void Guitext_text_18pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);
void Guitext_text_72pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);
void Guitext_text_27pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);
void Guitext_text_35pts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);
void Guitext_text_72dspts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);
void Guitext_text_18dspts(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);
void FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void Guitext_text_eurostile_28pt(uint16_t row,uint16_t column,int8_t *string,unsigned short charColor,unsigned short bkColor);

#endif // _SSD1963_H
