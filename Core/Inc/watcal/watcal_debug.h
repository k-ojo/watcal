/*
 * watcal_debug.h
 *
 *  Created on: Jan 21, 2026
 *      Author: Pilolo Electronics
 */

#ifndef INC_WATCAL_DEBUG_H_
#define INC_WATCAL_DEBUG_H_

#include "stm32f1xx_hal.h"

int _write(int file, char *ptr, int len);
void print_uint_buf(uint8_t *buf, uint32_t len);

void test_debug(void);

#endif /* INC_WATCAL_DEBUG_H_ */
