#include "Timers_init.hpp"

void Timer3_PWMOUT_LED_Init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; 

    TIM3->PSC = (SystemCoreClock / 1000000) - 1;
    TIM3->ARR = 20000 - 1; 

    TIM3->CCMR1 &= ~TIM_CCMR1_CC2S;                    
    TIM3->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; 
    TIM3->CCMR1 |= TIM_CCMR1_OC2PE;                     

    TIM3->CCR2 = 0; 

    TIM3->CCER |= TIM_CCER_CC2E; 

    TIM3->CR1 |= TIM_CR1_CEN; 
}