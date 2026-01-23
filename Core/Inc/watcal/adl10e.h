/*
 * ADL10E.h
 *
 *  Created on: Jan 20, 2026
 *      Author: Gideon
 */

#include <stdint.h>
#ifndef INC_ADL10E_H_
#define INC_ADL10E_H_

#define ADL10E_VOLTAGE 0X0001

#define NUMBER_OF_SLAVES 32
#define READINGS_BUFFER 100
#define NUMBER_BYTES_READING 32

#define DMA_MULTIPLIER 1
#define INST_FRAME_SIZE 15
#define DMA_BUF_SIZE INST_FRAME_SIZE * DMA_MULTIPLIER

struct adl10e_inst_data{
	uint32_t timestamp;
	uint16_t voltage;
	uint16_t current;
	uint16_t active_power;
	uint16_t reactive_power;
	uint16_t apparent_power;
	uint8_t meter_id;
};

int adl10e_req_readings(uint8_t slave_addr, uint8_t start_addr, uint16_t num_of_regs);
void test_adl10e(void);

#endif /* INC_ADL10E_H_ */
