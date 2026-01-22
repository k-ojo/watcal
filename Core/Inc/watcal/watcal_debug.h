/*
 * watcal_debug.h
 *
 *  Created on: Jan 21, 2026
 *      Author: Pilolo Electronics
 */

#ifndef INC_WATCAL_DEBUG_H_
#define INC_WATCAL_DEBUG_H_

#include "stm32f1xx_hal.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
int _write(int file, char *ptr, int len);

#endif /* INC_WATCAL_DEBUG_H_ */
