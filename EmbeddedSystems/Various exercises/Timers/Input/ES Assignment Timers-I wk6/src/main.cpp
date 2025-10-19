#include "ISR_handler.h"

int main(void)
{
    SystemClock_Config();
    SysTick_Init();
    GPIOB_Echo_Init();
    GPIOA_Trigger_Init();
    USART2_Init();

    Timer4_TriggerIN_Init();
    Timer4_EchoOUT_Init();

    while (1)
    {
        PrintTrigger(10);
        Delay(100);
    }
}