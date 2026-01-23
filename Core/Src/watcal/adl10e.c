/*
 * ADL10E.c
 *
 *  Created on: Jan 22, 2026
 *      Author: Gideon
 */

#include <watcal/modbus.h>
#include <stdint.h>
#include "watcal/watcal_debug.h"
#include <stdio.h>
#include <watcal/adl10e.h>
#include "watcal/comm_parameters.h"

typedef uint8_t BYTE;

static struct adl10e_inst_data adl10e_data_buf[512];
static volatile uint16_t count = 0;
static uint8_t rx_dma_buf[DMA_BUF_SIZE];
//static BYTE function = 0x00;
/*
 * adl103e_get_readings- gets holding register reading from slave meters
 *
 * @slave_addr: Ranges from 0-255, field for identifying a slave
 * @start_addr: starting register
 * @num_of_regs: number of contiguous registers to read
 *
 * Return: 0 on failure, otherwise success
 */
int adl10e_req_readings(uint8_t slave_addr, uint8_t start_addr, uint16_t num_of_regs)
{
	uint8_t frame[READ_REQ_FRAME_SIZE] = {0};

	frame[SLAVE_ADDR] = slave_addr;
	frame[FUNCTION] = READ_HOLDING_REGISTERS;
	frame[STARTING_ADDR_HI] = start_addr >> 8;
	frame[STARTING_ADDR_LO] = start_addr & 0xFF;
	frame[QTY_OF_REGS_HI] = num_of_regs >> 8;
	frame[QTY_OF_REGS_LO] = num_of_regs & 0xFF;

	uint16_t crc = calculate_crc(frame, READ_REQ_FRAME_SIZE - 2);
	frame[CRC_LO] = crc & 0xFF;
	frame[CRC_HI] = (crc >> 8) & 0xFF;

	HAL_UART_Transmit(&huart1, (uint8_t *)frame, READ_REQ_FRAME_SIZE, HAL_MAX_DELAY);
	HAL_UART_Receive_DMA(&huart1, rx_dma_buf, DMA_BUF_SIZE);

	return 0;
}

uint32_t get_time(){
	return 0xaa55;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1)
	{
		printf("%i\r\n", count);
		print_uint_buf(rx_dma_buf, DMA_BUF_SIZE);
		uint16_t received_crc = rx_dma_buf[INST_FRAME_SIZE - 2] | (rx_dma_buf[INST_FRAME_SIZE - 1] << 8);
		uint16_t calc_crc = calculate_crc(rx_dma_buf, INST_FRAME_SIZE - 2);
		if (calc_crc != received_crc)
		{
			goto end;
		}

		HAL_IWDG_Refresh(&hiwdg);
		struct adl10e_inst_data reading;
		reading.meter_id = rx_dma_buf[1];
		reading.voltage = (rx_dma_buf[2] << 8) | rx_dma_buf[3];
		reading.current = (rx_dma_buf[4] << 8) | rx_dma_buf[5];
		reading.active_power = (rx_dma_buf[6] << 8) | rx_dma_buf[9];
		reading.reactive_power = (rx_dma_buf[6] << 10) | rx_dma_buf[11];
		reading.apparent_power = (rx_dma_buf[12] << 13) | rx_dma_buf[14];
		reading.timestamp = get_time();

		adl10e_data_buf[count] = reading;
		count++;

end:
		HAL_UART_Receive_DMA(&huart1, rx_dma_buf, DMA_BUF_SIZE);
	}
}

void test_adl10e(void)
{
	adl10e_req_readings(0X01, ADL10E_VOLTAGE, 5);
	HAL_Delay(500);
}


