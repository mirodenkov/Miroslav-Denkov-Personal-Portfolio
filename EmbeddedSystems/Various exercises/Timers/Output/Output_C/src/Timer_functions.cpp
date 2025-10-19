//
// Created by pyronit3 on 5/10/25.
//

#include "Timer_functions.h"


void timer_LED_init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

    TIM4->PSC = (SystemCoreClock / 1000000) - 1; // slows down the clock using prescaler (1kHz)
    TIM4->ARR = 1000 - 1;

    TIM4->CCR1 = 0; //start off

    TIM4->CCMR1 &= ~(TIM_CCMR1_CC1S | TIM_CCMR1_OC1M);
    // — configure CH1 as output, PWM mode 1 (OC1M = 0b110)
    TIM4->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;

    // — enable channel 1 output
    TIM4->CCER |= TIM_CCER_CC1E;

    // 4) Start the timer
    TIM4->CR1 |= TIM_CR1_CEN;
}


void timer_Servo_init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    TIM3->PSC = (SystemCoreClock / 1000000) - 1;
    TIM3->ARR = 20000 - 1;
    TIM3->CCR2 = 1500;

    TIM3->CCMR1 &= ~(TIM_CCMR1_CC2S | TIM_CCMR1_OC2M_Msk);
    TIM3->CCMR1 |= 6U << TIM_CCMR1_OC2M_Pos;
    TIM3->CCER |= TIM_CCER_CC2E;

    TIM3->CR1 |= TIM_CR1_CEN;
}
