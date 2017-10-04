#include "GUI_Table.h"

void GUI(void)
{
LCD_DrawRectangle(2,2,796,476,Black); //full
LCD_DrawRectangle(3,3,795,475,Black);	//full
LCD_DrawLine(3,100,795,100,Black); 		//line 1
LCD_DrawLine(3,101,795,101,Black); 		//line 1	
LCD_DrawLine(3,180,795,180,Black); 		//line 2
LCD_DrawLine(3,181,795,181,Black); 		//line 2
LCD_DrawLine(3,254,185,254,Black); 			//line 3
LCD_DrawLine(3,255,185,255,Black); 			//line 3
LCD_DrawLine(3,328,795,328,Black); 			//line 4
LCD_DrawLine(3,329,795,329,Black); 			//line 4
LCD_DrawLine(3,362,555,362,Black); 			//line 5
LCD_DrawLine(3,363,555,363,Black); 			//line 5
LCD_DrawLine(3,417,555,417,Black); 			//line 6
LCD_DrawLine(3,418,555,418,Black); 			//line 6
LCD_DrawLine(185,181,185,475,Black); 		//cow 1
LCD_DrawLine(186,181,186,475,Black); 		//cow 1
LCD_DrawLine(370,101,370,475,Black); 		//cow 2
LCD_DrawLine(371,101,371,475,Black); 		//cow 2
LCD_DrawLine(583,101,583,328,Black); 		//cow 3
LCD_DrawLine(584,101,584,328,Black); 		//cow 3
LCD_DrawLine(555,329,555,475,Black); 		//cow 3.1
LCD_DrawLine(556,329,556,475,Black); 		//cow 3.1
///////////////////////////////////////////////////
Guitext_text_28pts  (90, 128,(signed char*)"System",Black,Black);
Guitext_text_28pts  (410, 128,(signed char*)"Temp",Black,Black);
Guitext_text_28pts  (605, 128,(signed char*)"Humidity",Black,Black);
Guitext_text_28pts  (305, 190,(signed char*)"pH",Black,Black);
Guitext_text_18pts  (720, 335,(signed char*)"PPM",Black,Black);
Guitext_text_18pts(10, 190,(signed char*)"Fan",Black,Black);
Guitext_text_18pts(10, 260,(signed char*)"Pump",Black,Black);
Guitext_text_18pts(30, 335,(signed char*)"Lamp1",Black,Black);
Guitext_text_18pts(220, 335,(signed char*)"Lamp2",Black,Black);
Guitext_text_18pts(410, 335,(signed char*)"Lamp3",Black,Black);
Guitext_text_18pts(145, 368,(signed char*)"lux",Black,Black);
Guitext_text_18pts(330, 368,(signed char*)"lux",Black,Black);
Guitext_text_18pts(515, 368,(signed char*)"lux",Black,Black);
Guitext_text_72dspts (510, 220,(signed char*)"C",Black,Black);
Guitext_text_72dspts (700, 225,(signed char*)"%",Black,Black);
Guitext_text_18dspts (495, 220,(signed char*)"o",Black,Black);

	Guitext_number_48pts (50+280,15,(signed char*)"09:30",Black,Black);
	Guitext_text_27pts (20 +280,68,(signed char*)"15;;-;;09;;-;;2017",Black,Black);
	Guitext_text_18dspts (190+280, 40,(signed char*)"AM",Black,Black);
}

void GUI_Lamp(void)
{
	LCD_DrawRectangle(90,70,710,410,Black); //full
	LCD_DrawRectangle(91,71,709,409,Black); //full
	LCD_DrawRectangle(92,72,708,408,Black); //full
	FillRect(120, 60, 120,100, White);
	Guitext_text_eurostile_28pt(220,130,(signed char*)"Please    enter    0    to    100:",Black,Black);
	Guitext_text_eurostile_28pt(620,370,(signed char*)"Ok(#)",Black,Black);
	Guitext_text_eurostile_28pt(100,370,(signed char*)"Clear(*)",Black,Black);
	LCD_DrawLine(370,340,430,340,Black);
	LCD_DrawLine(370,341,430,341,Black);
	LCD_DrawLine(370,342,430,342,Black);
	LCD_DrawLine(290,340,350,340,Black);
	LCD_DrawLine(290,341,350,341,Black);
	LCD_DrawLine(290,342,350,342,Black);
	LCD_DrawLine(450,340,510,340,Black);
	LCD_DrawLine(450,341,510,341,Black);
	LCD_DrawLine(450,342,510,342,Black);
}