#include "functions.h"

char buf[BUFLENGHT];

int main(void)
{
    SystemClock_Config();
    GPIO_Interrupt_Init();
    GPIO_RotaryEncoder_Init();
    USART2_Init();

    int volatile previous_encoder = 0;
    bool message = false;
    bool previous_message = false;

    while (true)
    {

        uint8_t PA6_state = (GPIOA->IDR & GPIO_IDR_6) ? 1 : 0;
        // check if the button is pressed
        // true: turn PA9 on
        // false: turn PA9 off
        if (!(PA6_state))
        {
            message = true;
            if (message != previous_message)
            {
                snprintf(buf, BUFLENGHT, "PA9 On!\r\n");
                USART2_SendString(buf);
                previous_message = message;
            }
            GPIOA->ODR |= GPIO_ODR_9;
        }
        else
        {
            message = false;
            if (message != previous_message)
            {
                snprintf(buf, BUFLENGHT, "PA9 Off!\r\n");
                USART2_SendString(buf);
                previous_message = message;
            }

            GPIOA->ODR &= ~GPIO_ODR_9;
        }
        
        if (previous_encoder != encoder_count)
        {
            snprintf(buf, BUFLENGHT, "Encoder count: %d\r\n", encoder_count);
            USART2_SendString(buf);
            previous_encoder = encoder_count;
        }
    }
}