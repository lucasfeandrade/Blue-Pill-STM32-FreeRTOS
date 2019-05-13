/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include<stdio.h>
//#include<stdint.h>
#include "stm32f10x.h"
#include "stm32f1xx_nucleo.h"
#include "FreeRTOS.h"
#include "task.h"


TaskHandle_t xTaskHandle1=NULL;
TaskHandle_t xTaskHandle2=NULL;

void vTask1_handler(void *params);
void vTask2_handler(void *params);

//used for semihosting
//#ifdef USE_SEMIHOSTING
	extern void initialise_monitor_handles();
//#endif

int main(void)
{

//#ifdef USE_SEMIHOSTING
	initialise_monitor_handles();
	printf("Hello world from task 1\n");
//#endif
	//1. Turn on internal clock
	//HSI ON, PLL OFF, HSE OFF
	RCC_DeInit();
	//2. update the systemCoreClock variable
	SystemCoreClockUpdate();
	//3. create task 1 and 2
	//vTask1_handler: funcao task, "Task-1" nome task,
	//512: num bytes (numero min da freeRTOSConfig.h * 4 pois la sao words)
	//2 prioridade, quanto menor maior, tem o maximo no freeRTOSConfig.h
	xTaskCreate( vTask1_handler, "Task-1",configMINIMAL_STACK_SIZE , NULL, 2, &xTaskHandle1);
	xTaskCreate( vTask2_handler, "Task-2",configMINIMAL_STACK_SIZE , NULL, 2, &xTaskHandle2);

	//4. Start the scheduler
	vTaskStartScheduler();

	int i = 0;
	i++;
	if(i=1) {
		for(;;);
	}

}

void vTask1_handler(void * params) {
	while(1) {
		printf("Hello world from task 1\n");
	}

}

void vTask2_handler(void * params) {
	while(1) {
		printf("Hello world from task 2\n");
	}
}
//
//static void prvSetupHardware(void)
//{
//	//1. Enable the UART Peripheral clock
//}

