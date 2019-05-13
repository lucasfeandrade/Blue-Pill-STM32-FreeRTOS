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
#ifdef USE_SEMIHOSTING
	extern void initialise_monitor_handles();
#endif

int main(void)
{

#ifdef USE_SEMIHOSTING
	initialise_monitor_handles();
	printf("Hello world from task 1\n");
#endif

	DWT->CTRL |= (1 <<0); //Enable counter for SEGGER timestamp

	//1. Turn on internal clock
	//HSI ON, PLL OFF, HSE OFF
	RCC_DeInit();
	//2. update the systemCoreClock variable
	SystemCoreClockUpdate();
	//Starting Segger
	SEGGER_SYSVIEW_Conf();
	SEGGER_SYSVIEW_Start();
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

	}

}

void vTask2_handler(void * params) {
	while(1) {

	}
}

static void prvSetupHardware(void)
{
	GPIO_InitTypeDef gpio_uart_pins;
	//1. Enable the UART and GPIOAPeripheral clock
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//PA2 is UART2_TX, PA3 is UART2_RX

	//2 Alternate function configuration of MCU pins to behave as UART2 TX and RX

	gpio_uart_pins.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	gpio_uart_pins.GPIO_Mode = 0x02; //alternate function
//	gpio_uart_pins.GPIO_PuPd = GPIO_PuPd_UP;
	gpio_uart_GPIO_Init(GPIOA, &gpio_uart_pins);

	//3. AF mode settings for the pins
//	GPIO_PinAFConfig(GPIOA, GPIO_PinSource, GPIO_AF_USART2);



}

