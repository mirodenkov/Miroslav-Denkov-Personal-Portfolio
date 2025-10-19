#ifndef SETUPFUNCTIONS_H
#define SETUPFUNCTIONS_H

#include "stm32f303xe.h"
#include <stdio.h>
#include <string.h>

#define BUFLENGHT 100


void SystemClock_Config(void);
void GPIOx_Init(void);
void USART2_Init(void);
void SysTick_Init(void);
void Delay(uint32_t milliseconds);
uint32_t GetMillis(void);
void USART2_SendString(char *str);
char *USART2_ReceiveString(char rcvBuf[]);

#endif