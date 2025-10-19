#ifndef TIMERS_INITS_H
#define TIMERS_INITS_H

#include "stm32f303xe.h"
#define AF_TIM2 1
#define AF_TIM3 2
#define AF_TIM4 2


/// @brief Initialize PWMOUT for Servo
/// @param void Empty
extern void Timer2_PWMOUT_Servo_Init(void);

/// @brief Initialize PWMOUT for LED
/// @param void Empty
extern void Timer3_PWMOUT_LED_Init(void);

#endif