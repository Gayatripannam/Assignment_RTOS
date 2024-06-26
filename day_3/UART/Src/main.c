/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void vUartAperiodicTask(void *pvParam)
{
	char str[32];

		UartPuts("Enter Strings...\r\n");
		while(1) {
			UartGets(str);
			strupr(str);
			UartPuts(str);
		}
		vTaskDelete(NULL);
}







char str[32];

int main(void)
{
	SystemInit();
	UartInit(BAUD_9600);
	xTaskCreate(vUartAperiodicTask, "UART", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

	vTaskStartScheduler();
	while(1);
	return 0;
}
