/*---------------------------------------------------------------------------
 * Copyright (c) 2021-2022 Arm Limited (or its affiliates).
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *      Name:    retarget_stdio.c
 *      Purpose: Retarget stdio to ST-Link (Virtual COM Port)
 *
 *---------------------------------------------------------------------------*/

#include "stm32g0xx_hal.h"

#define HUARTx            huart3

extern UART_HandleTypeDef HUARTx;

extern int stderr_putchar (int ch);
extern int stdout_putchar (int ch);
extern int stdin_getchar  (void);

/**
  Put a character to the stderr

  \param[in]   ch  Character to output
  \return          The character written, or -1 on write error.
*/
int stderr_putchar (int ch) {

  if (HAL_UART_Transmit(&HUARTx, (uint8_t *)&ch, 1U, 1000U) != HAL_OK) {
    return -1;
  }

  return ch;
}

/**
  Put a character to the stdout

  \param[in]   ch  Character to output
  \return          The character written, or -1 on write error.
*/
int stdout_putchar (int ch) {

  if (HAL_UART_Transmit(&HUARTx, (uint8_t *)&ch, 1U, 1000U) != HAL_OK) {
    return -1;
  }

  return ch;
}

/**
  Get a character from the stdio

  \return     The next character from the input, or -1 on read error.
*/
int stdin_getchar (void) {
  int ch = 0;
  HAL_StatusTypeDef hal_stat;

  do {
    hal_stat = HAL_UART_Receive(&HUARTx, (uint8_t *)&ch, 1U, 60000U);
  } while (hal_stat == HAL_TIMEOUT);

  if (hal_stat != HAL_OK) {
    return -1;
  }

  return ch;
}
