# Blue-Pill-STM32-FreeRTOS
This is the porting made while doing the course "Mastering RTOS: Hands on FreeRTOS and STM32Fx with Debugging", it should run in STM32 System workspace.

To add the FreeRTOS in a project you already have you should do the following steps:

1 - Add Third-Party folder to the root of your project

2 - Add Config folder to the root of your project

3 - In STM32 System Workspace right click on your project, then "properties-> C/C++ Build -> Settings -> Add+ (icon)", there you should add the following folders:
''''
Third-Party/FreeRTOS/org/Source/include
Third-Party/FreeRTOS/org/portable/GCC/ARM_CM3
Config/
''''

4 - Right click on Config folder, go to properties and unclick "Exclude resource from build". Do the same for the Third-Party folder



In order to run it I had to change some configurations relative to the course:

1 - To run semihosting I had to change the following define from Config/FreeRTOSConfig.h:
From:
#define configTOTAL_HEAP_SIZE		( ( size_t ) ( 17 * 1024 ) )
To:
#define configTOTAL_HEAP_SIZE		( ( size_t ) ( 16 * 1024 ) )


2 - To get the scheduler to run properly I had to add into Config/FreeRTOSConfig.h the following lines:

#define vPortSVCHandler SVC_Handler

#define xPortPendSVHandler PendSV_Handler

#define xPortSysTickHandler SysTick_Handler
