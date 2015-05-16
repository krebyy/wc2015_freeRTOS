//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>

#include "stm32f4xx_hal.h"

#include "FreeRTOS.h"
#include "task.h"

#include "main.h"

void vApplicationTickHook( void )
{
	HAL_IncTick();
}


// ----- main() ---------------------------------------------------------------

static void mainTask(void* pvParameters)
{
	(void)pvParameters;

	TickType_t xLastWakeTime;

	// Initialise the xLastWakeTime variable with the current time.
	xLastWakeTime = xTaskGetTickCount();

	for(;;)
	{


		// Wait for the next cycle.
		vTaskDelayUntil( &xLastWakeTime, 10);
		//vTaskDelay(10);
	}
}


int main(int argc, char* argv[])
{
	// Configuração e inicialização dos periféricos ----------------------------
	perifericosConfig();


	// Inicio do programa ------------------------------------------------------
	printf("Winter Challenge 2015 - uMaRT LITE+ V1.1\r\n");


	xTaskCreate(mainTask, "main task", configMAIN_TASK_STAKSIZE, NULL, tskMAIN_PRIORITY, NULL);

	vTaskStartScheduler();
	// Infinite loop
	while (1)
	{
		// Add your code here.
	}
}

// -----------------------------------------------------------------------------


// Configuração e inicialização dos periféricos --------------------------------
void perifericosConfig(void)
{
	buzzerConfig();
	ledsConfig();
	botaoConfig();
	motoresConfig();
	sensoresConfig();
	encodersConfig();
	usart1Config();
}
