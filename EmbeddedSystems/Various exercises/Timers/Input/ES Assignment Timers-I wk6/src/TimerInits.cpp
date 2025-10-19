#include "TimerInits.h"

void Timer4_TriggerIN_Init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; // Enable TIM4 clock

    TIM4->PSC = (SystemCoreClock / 1000000) - 1;

    // Set CC1 channel as input with IC1 mapped on TI1
    TIM4->CCMR1 &= ~TIM_CCMR1_CC1S;  
    TIM4->CCMR1 |= TIM_CCMR1_CC1S_0; 

    // Set CC1NP/CC1P bits to non-inverted / rising edge
    TIM4->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP); 

    // Enable Capture/Compare 1 capture
    TIM4->CCER |= TIM_CCER_CC1E;

    // Set CC2 channel as input with IC2 mapped on TI1
    TIM4->CCMR1 &= ~TIM_CCMR1_CC2S;  
    TIM4->CCMR1 |= TIM_CCMR1_CC2S_1; 

    // Set CC2NP/CC2P bits to inverted / falling edge
    TIM4->CCER &= ~TIM_CCER_CC2NP; 
    TIM4->CCER |= TIM_CCER_CC2P;   

    // Enable Capture/Compare 2 capture
    TIM4->CCER |= TIM_CCER_CC2E;

    // Set Trigger selection to Filtered Timer Input 1
    TIM4->SMCR &= ~TIM_SMCR_TS;                  
    TIM4->SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_0; 

    // Set Slave mode selection to Reset Mode
    TIM4->SMCR &= ~TIM_SMCR_SMS;  
    TIM4->SMCR |= TIM_SMCR_SMS_2; 

    // Enable counter
    TIM4->CR1 |= TIM_CR1_CEN;
}

void Timer4_EchoOUT_Init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; // Enable TIM4 clock

    TIM4->PSC = (SystemCoreClock / 1000000) - 1; 

    // Setting ARR to max because echo pulse has a max duration of around 25ms
    TIM4->ARR = 0xFFFF; // Ensures that the overflow doesn't happen prematurely

    TIM4->CCER &= ~TIM_CCER_CC1E; // Configure capture on rising edge
    TIM4->CCER |= TIM_CCER_CC1E;

    TIM4->DIER |= TIM_DIER_CC1IE; // Enable capture/compare interrupt

    TIM4->CR1 |= TIM_CR1_CEN; // Enabling the counter

    NVIC_EnableIRQ(TIM4_IRQn); // Enabling TIM4 interrupt
}