#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart3;

int _write(int fd, char *str, int len)
{
	int ret;

	if (fd != 1) return -1;

	ret = HAL_UART_Transmit(&huart3, (uint8_t *)str, len, 0xFF);
	if (ret < 0) return -1;

	return len;
}
