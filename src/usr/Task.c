#include "cmsis_os.h"
#include "SSD1963.h"
#include "GUI_Table.h"
#include "Task.h"

#define STACK_SIZE_MIN	128	/* usStackDepth	- the stack size DEFINED IN WORDS.*/

void initTask(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	__GPIOD_CLK_ENABLE();
	GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	xTaskCreate(	Task1, (const signed char*)"task1", 
					STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate(	Task2, (const signed char*)"task2", 
					STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	// xTaskCreate(	Task3, (const signed char*)"task3", 
	// 				STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	// xTaskCreate(	Task4, (const signed char*)"task4", 
	// 				STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );

	vTaskStartScheduler();
}
void Task1(void)
{
	ResetDevice();
	SetBacklight(0xff);
	vTaskDelay( 200 / portTICK_RATE_MS );
	ClearDevice(0,0,800,480,White);
	GUI();
	while (1)
	{
	}
}
void Task2(void)
{
	while(1)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); 
		vTaskDelay( 200 / portTICK_RATE_MS );
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET); 
		vTaskDelay( 200 / portTICK_RATE_MS );
	}
}
