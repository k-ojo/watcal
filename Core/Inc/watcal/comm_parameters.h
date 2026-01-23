/*
 * comm_parameters.h
 *
 *  Created on: Jan 22, 2026
 *      Author: Pilolo Electronics
 */

#ifndef INC_WATCAL_COMM_PARAMETERS_H_
#define INC_WATCAL_COMM_PARAMETERS_H_

#define UART1_BAUD_RATE 56700
#define UART2_BAUD_RATE 115200

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern IWDG_HandleTypeDef hiwdg;

#endif /* INC_WATCAL_COMM_PARAMETERS_H_ */
