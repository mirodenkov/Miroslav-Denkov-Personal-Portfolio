#include "CoreFunctions.h"

char buf[BUFLENTGH];

int main(void)
{

    SystemClock_Config();
    SysTick_Init();
    GPIOx_Init();
    USART2_Init();

    while(true)
    {
        int millis = GetMillis();
        if(!(GPIOA->IDR & GPIO_IDR_6))
        {
            for(int i = 0; i < 3; i++)
            {
                snprintf(buf, BUFLENTGH, "Dot\r\n");
                USART2_SendString(buf);
                Dot();
            }
            for(int i = 0; i < 3; i++)
            {
                snprintf(buf, BUFLENTGH, "Dash\r\n");
                USART2_SendString(buf);
                Dash();
            }
        }
        else
        {
            GPIOA->BSRR = GPIO_BSRR_BR_8;//keep led8 off;
        }

        if(!(GPIOC->IDR & GPIO_IDR_13))
        {
            snprintf(buf, BUFLENTGH, "millis: %d\r\n", millis);
            USART2_SendString(buf);
        }
    }

}