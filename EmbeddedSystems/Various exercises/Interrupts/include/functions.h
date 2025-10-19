#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "stm32f303xe.h"
#include <stdio.h>
#include <string.h>

/*macros*/
#define BUFLENGHT 100

extern volatile int encoder_count;
extern char sndbuf[BUFLENGHT];

void SystemClock_Config(void);
void GPIOx_Init(void);
void USART2_Init(void);
void USART2_SendString(char *str);
char *USART2_ReceiveString(char rcvBuf[]);
void Delay(uint32_t time_ms);
void GPIO_Interrupt_Init(void);
void GPIO_RotaryEncoder_Init(void);

#ifdef __cplusplus
extern "C"
{
#endif
    void EXTI9_5_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif