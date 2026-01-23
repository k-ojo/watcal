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
#include "watcal/comm_parameters.h"

int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;

}


void print_uint_buf(uint8_t *buf, uint32_t len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%02X", buf[i]);
	}
	printf("\r\n");
}

void test_debug(void)
{
	printf("PRINTF WORKS!\r\n ");
	HAL_Delay(100);
}
