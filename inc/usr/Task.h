#ifndef __TASK_H
#define __TASK_H

#include "stm32f4xx_hal.h"
void initTask(void);
void Task1(void *pvParameters);
void Task2(void *pvParameters);

#endif