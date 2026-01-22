/*
 * watcal_debug.c
 *
 *  Created on: Jan 21, 2026
 *      Author: Pilolo Electronics
 */
#include <stdint.h>
#include "watcal/watcal_debug.h"

int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;

}
