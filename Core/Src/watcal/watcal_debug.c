/*
 * watcal_debug.c
 *
 *  Created on: Jan 21, 2026
 *      Author: Pilolo Electronics
 */
#include <stdint.h>
#include "watcal/watcal_debug.h"
#include "stdio.h"
#include "watcal/adl10e.h"

int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;

}

void test(void)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
	printf("HERE: ");
	adl10e_get_readings(0X01, ADL10E_VOLTAGE, 2);
	HAL_Delay(100);
}
