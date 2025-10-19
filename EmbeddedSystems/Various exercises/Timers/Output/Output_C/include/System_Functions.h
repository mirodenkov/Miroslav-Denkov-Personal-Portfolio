//
// Created by pyronit3 on 5/10/25.
//

#ifndef SYSTEM_FUNCTIONS_H
#define SYSTEM_FUNCTIONS_H

#include "stm32f303xe.h"
#include <stdio.h>
#include <string.h>

#define BUFLENGTH 100
extern volatile uint32_t msTicks; // millisec counter

/**
 * @brief  Configures the system clock
 */
void SystemClock_Config(void);

/**
 * @brief Initializes the USART2
 */
void USART2_Init(void);

/**
 * @brief Initializes the SysTick timer
 */
void SysTick_Init(void);

/**
 * @brief Blocking delay using the system tick timer
 * @param milliseconds is used to determine the how much time we block
 */
void Delay(uint32_t milliseconds);

/**
 * @brief Get milliseconds since the timer has been active
 * @return msTicks
 */
uint32_t GetMillis(void);

/**
 * @brief Sends a string through serial
 * @param str holds the message
 */
void USART2_SendString(char *str);

/**
 * @brief Receives message strings through serial
 * @param rcvBuf holds the message sent back to the board
 * @return rcvBuf
 */
char *USART2_ReceiveString(char rcvBuf[]);


#endif //SYSTEM_FUNCTIONS_H
