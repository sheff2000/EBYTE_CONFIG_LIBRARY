/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define UART4_M0_Pin GPIO_PIN_5
#define UART4_M0_GPIO_Port GPIOC
#define UART4_M1_Pin GPIO_PIN_0
#define UART4_M1_GPIO_Port GPIOB
#define UART4_AUX_Pin GPIO_PIN_1
#define UART4_AUX_GPIO_Port GPIOB
#define UART3_M0_Pin GPIO_PIN_13
#define UART3_M0_GPIO_Port GPIOE
#define UART3_M1_Pin GPIO_PIN_14
#define UART3_M1_GPIO_Port GPIOE
#define UART3_AUX_Pin GPIO_PIN_15
#define UART3_AUX_GPIO_Port GPIOE
#define UART5_M1_Pin GPIO_PIN_0
#define UART5_M1_GPIO_Port GPIOD
#define UART5_M0_Pin GPIO_PIN_1
#define UART5_M0_GPIO_Port GPIOD
#define UART5_AUX_Pin GPIO_PIN_3
#define UART5_AUX_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
