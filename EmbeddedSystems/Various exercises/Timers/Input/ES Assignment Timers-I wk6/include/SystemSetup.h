#pragma once

#include "stm32f303xe.h"
#include <stdio.h>

#define AF_TIM2 1
#define AF_TIM3 2
#define AF_TIM4 2

extern volatile uint32_t msTicks;

/// @brief Enabling System clock
/// @param void Empty
extern void SysTick_Init(void);

/// @brief Enable GPIOA clock for HC-SR04
/// @param void Empty
extern void GPIOA_Trigger_Init(void);

/// @brief Enable GPIOB clock for HC-SR04
/// @param void Empty
extern void GPIOB_Echo_Init(void);

/// @brief Initialize USART2
/// @param void Empty
extern void USART2_Init(void);

/// @brief Send a string through USART2.
/// @param str String you'd like to send
extern void USART2_SendString(char *str);

/// @brief Increments uint32_t msTicks
/// @param void Empty
extern "C" void SysTick_Handler(void);

/// @brief Returns msTicks value
/// @param void Empty
/// @return Returns msTicks
extern uint32_t GetMillis(void);

/// @brief Delay function (Blocking)
/// @param ms Time in milliseconds
extern void Delay(uint32_t ms);

void SystemClock_Config(void);
