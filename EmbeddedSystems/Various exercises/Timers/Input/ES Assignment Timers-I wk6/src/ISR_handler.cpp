#include "ISR_handler.h"

extern "C" void TIM4_IRQHandler(void)
{
    // Rising edge event
    if (TIM4->SR & TIM_SR_CC1IF)
    {
        TIM4->SR &= ~TIM_SR_CC1IF;

        if (!(TIM4->CCER & TIM_CCER_CC1P)) // If rising edge
        {
            ResetCounter();
        }
        else // If falling edge
        {
            MeasureDistance();
        }
    }
}