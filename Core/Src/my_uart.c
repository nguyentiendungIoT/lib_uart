/*
 * my_uart.c
 *
 *  Created on: Feb 5, 2025
 *      Author: Nguyen Tien Dung
 */
#include "my_uart.h"
#include <string.h>

/**
 * @brief Gửi 1 byte qua UART.
 *
 * Sử dụng hàm HAL_UART_Transmit với timeout là HAL_MAX_DELAY để đảm bảo truyền dữ liệu.
 */
void UART_SendByte(UART_HandleTypeDef *huart, uint8_t byte)
{
    HAL_UART_Transmit_IT(huart,&byte, 1);
}

/**
 * @brief Gửi 1 mảng byte qua UART.
 *
 * Hàm này gửi một mảng dữ liệu gồm Size byte từ bộ nhớ qua UART.
 */
void UART_SendArray(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
    HAL_UART_Transmit(huart, pData, Size, HAL_MAX_DELAY);
}

/**
 * @brief Gửi 1 chuỗi ký tự qua UART.
 *
 * Hàm này sử dụng hàm strlen để tính độ dài chuỗi và gửi toàn bộ chuỗi (bao gồm các ký tự đến '\0' không được gửi).
 */
void UART_SendString(UART_HandleTypeDef *huart, char *str)
{
    uint16_t len = (uint16_t)strlen(str); // Tính độ dài chuỗi
    HAL_UART_Transmit(huart, (uint8_t *)str, len, HAL_MAX_DELAY);
}

/**
 * @brief Bật chức năng truyền (TX) của UART.
 *
 * Ở đây chúng ta truy cập trực tiếp vào thanh ghi CR1 của UART để set bit TE (Transmitter Enable).
 */
void UART_EnableTX(UART_HandleTypeDef *huart)
{
    // Set bit TE trong thanh ghi CR1 để bật chức năng truyền
    huart->Instance->CR1 |= USART_CR1_TE;
}

/**
 * @brief Tắt chức năng truyền (TX) của UART.
 *
 * Xóa bit TE trong thanh ghi CR1 để tắt chức năng truyền.
 */
void UART_DisableTX(UART_HandleTypeDef *huart)
{
    // Xóa bit TE trong thanh ghi CR1 để tắt chức năng truyền
    huart->Instance->CR1 &= ~USART_CR1_TE;
}

/**
 * @brief Bật chức năng nhận (RX) của UART.
 *
 * Set bit RE (Receiver Enable) trong thanh ghi CR1 để bật chức năng nhận.
 */
void UART_EnableRX(UART_HandleTypeDef *huart)
{
    huart->Instance->CR1 |= USART_CR1_RE;
}

/**
 * @brief Tắt chức năng nhận (RX) của UART.
 *
 * Xóa bit RE trong thanh ghi CR1 để tắt chức năng nhận.
 */
void UART_DisableRX(UART_HandleTypeDef *huart)
{
    huart->Instance->CR1 &= ~USART_CR1_RE;
}

