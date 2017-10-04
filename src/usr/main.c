#include "main.h"
#include "Task.h"

int main(void)
{
	HAL_Init();
	/* Configure the system clock to 168 MHz */
	System_Clock_Config();
	/* Infinite the task */
	initTask();
	return 0;
}

