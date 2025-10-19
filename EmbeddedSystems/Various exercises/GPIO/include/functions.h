#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "stm32f303xe.h"
#include <stdio.h>
#include <string.h>

/*macros*/
#define BUFLENGHT 100

void SystemClock_Config(void);
void GPIOx_Init(void);
void USART2_Init(void);
void USART2_SendString(char *str);
char *USART2_ReceiveString(char rcvBuf[]);
void Delay(uint32_t time_ms);

void Morse_code(void);





#endif