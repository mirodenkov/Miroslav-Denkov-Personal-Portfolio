#include "UltrasonicFunctions.h"

const int BUFLENGTH = 100;
char sndBuf[BUFLENGTH];
volatile int distance = 0;
volatile uint32_t pulseWidth = 0;

void PrintTrigger(int microseconds)
{
    TIM4->CCR1 = microseconds;
    snprintf(sndBuf, BUFLENGTH, "distance: %d cm\r\n", distance);
    USART2_SendString(sndBuf);
}

void ResetCounter(void)
{
    TIM4->CNT = 0;               // Reset counter
    TIM4->CCER |= TIM_CCER_CC1P; // Switch to detect falling edge
}

void MeasureDistance(void)
{
    pulseWidth = TIM4->CCR1;
    distance = pulseWidth / 58;   // 58 is the number needed to convert the pulse to centimeters.
    TIM4->CCER &= ~TIM_CCER_CC1P; // Switch to detect rising edge
}