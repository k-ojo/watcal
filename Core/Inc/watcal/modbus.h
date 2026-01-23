/*
 * MODBUS.h
 *
 *  Created on: Jan 20, 2026
 *      Author: Gideon
 */

#ifndef INC_MODBUS_H_
#define INC_MODBUS_H_

#include <stdint.h>

#define READ_COILS 0x01
#define READ_DISCRETE_INPUTS 0x02
#define READ_HOLDING_REGISTERS 0x03
#define READ_INPUT_REGISTERS 0x04
#define WRITE_SINGLE_COIL 0x05
#define WRITE_SINGLE_REGISTER 0x06

#define SLAVE_ADDR 0
#define FUNCTION 1
#define STARTING_ADDR_HI 2
#define STARTING_ADDR_LO 3
#define QTY_OF_REGS_HI 4
#define QTY_OF_REGS_LO 5
#define CRC_LO 6
#define CRC_HI 7

#define READ_REQ_FRAME_SIZE 8

uint16_t calculate_crc(uint8_t *frame, uint16_t w_length);

#endif /* INC_MODBUS_H_ */
