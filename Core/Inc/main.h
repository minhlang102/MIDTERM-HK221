/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define LED_TEST_Pin GPIO_PIN_5
#define LED_TEST_GPIO_Port GPIOA
#define s0_Pin GPIO_PIN_0
#define s0_GPIO_Port GPIOB
#define s1_Pin GPIO_PIN_1
#define s1_GPIO_Port GPIOB
#define s2_Pin GPIO_PIN_2
#define s2_GPIO_Port GPIOB
#define BUTTON1_Pin GPIO_PIN_11
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_12
#define BUTTON2_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_13
#define BUTTON3_GPIO_Port GPIOA
#define s3_Pin GPIO_PIN_3
#define s3_GPIO_Port GPIOB
#define s4_Pin GPIO_PIN_4
#define s4_GPIO_Port GPIOB
#define s5_Pin GPIO_PIN_5
#define s5_GPIO_Port GPIOB
#define s6_Pin GPIO_PIN_6
#define s6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
