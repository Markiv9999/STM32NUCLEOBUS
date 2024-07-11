/*
 * SystemInit.h
 *
 *  Created on: Jul 11, 2024
 *      Author: vikra
 */

#ifndef INC_BOARDINIT_H_
#define INC_BOARDINIT_H_


//Pin Defines
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB


#include "stm32l4xx_hal.h"
//Function which calls all initialization functions
void BoardInit();

//Add Board Feature Initialization Functions here
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void Error_Handler(void);




#endif /* INC_BOARDINIT_H_ */
