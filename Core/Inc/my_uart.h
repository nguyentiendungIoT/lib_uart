/*
 * my_uart.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Nguyen Tien Dung
 */

#ifndef LIBRARY_UART_MY_UART_H_
#define LIBRARY_UART_MY_UART_H_
#include "stm32f7xx_hal.h"  // Bao gồm HAL cho STM32F7
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  Gửi 1 byte qua UART.
 * @param  huart: Con trỏ đến cấu trúc UART_HandleTypeDef đã được khởi tạo.
 * @param  byte: Byte dữ liệu cần gửi.
 */
void UART_SendByte(UART_HandleTypeDef *huart, uint8_t byte);

/**
 * @brief  Gửi 1 mảng byte qua UART.
 * @param  huart: Con trỏ đến cấu trúc UART_HandleTypeDef đã được khởi tạo.
 * @param  pData: Con trỏ đến mảng dữ liệu cần gửi.
 * @param  Size: Số byte cần gửi.
 */
void UART_SendArray(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

/**
 * @brief  Gửi 1 chuỗi ký tự (string) qua UART.
 * @param  huart: Con trỏ đến cấu trúc UART_HandleTypeDef đã được khởi tạo.
 * @param  str: Con trỏ đến chuỗi ký tự kết thúc bằng ký tự '\0'.
 */
void UART_SendString(UART_HandleTypeDef *huart, char *str);

/**
 * @brief  Bật chức năng truyền (TX) của UART.
 * @param  huart: Con trỏ đến cấu trúc UART_HandleTypeDef đã được khởi tạo.
 */
void UART_EnableTX(UART_HandleTypeDef *huart);

/**
 * @brief  Tắt chức năng truyền (TX) của UART.
 * @param  huart: Con trỏ đến cấu trúc UART_HandleTypeDef đã được khởi tạo.
 */
void UART_DisableTX(UART_HandleTypeDef *huart);

/**
 * @brief  Bật chức năng nhận (RX) của UART.
 * @param  huart: Con trỏ đến cấu trúc UART_HandleTypeDef đã được khởi tạo.
 */
void UART_EnableRX(UART_HandleTypeDef *huart);

/**
 * @brief  Tắt chức năng nhận (RX) của UART.
 * @param  huart: Con trỏ đến cấu trúc UART_HandleTypeDef đã được khởi tạo.
 */
void UART_DisableRX(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif




#endif /* LIBRARY_UART_MY_UART_H_ */
