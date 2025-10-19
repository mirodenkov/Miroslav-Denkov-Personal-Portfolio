
#include "functions.h"
#define BUFLENGHT 100

/*global variables*/
char sndbuf[BUFLENGHT];
//////////////////////

int main(void)
{
    // Configure the system clock
    SystemClock_Config();
    GPIOx_Init();
    USART2_Init();

    /*User button state is HIGH*/
    int lastButtonState1 = 1;
    /*PA6 button state is HIGH*/
    int lastButtonState2 = 1;

    while (true)
    {

        /*Check for user button state*/
        int currentButtonState1 = (GPIOC->IDR & GPIO_IDR_13) ? 1 : 0;
        /*Check for PA6 button state*/
        int currentButtonState2 = (GPIOA->IDR & GPIO_IDR_6) ? 1 : 0;

        /*Toggle LED on PA8*/
        if (lastButtonState1 == 1 && currentButtonState1 == 0)
        {
            snprintf(sndbuf,BUFLENGHT, "LED on PA8 toggled!\r\n");
            USART2_SendString(sndbuf);
            GPIOA->ODR ^= GPIO_ODR_8;
            Delay(200);
        }
        lastButtonState1 = currentButtonState1;

        /*LED PA9 on and off after 3 seconds */
        if (lastButtonState2 == 1 && currentButtonState2 == 0)
        {
            snprintf(sndbuf, BUFLENGHT, "Turning PA9 on!\r\n");
            USART2_SendString(sndbuf);
            GPIOA->ODR ^= GPIO_ODR_9;
            Delay(3000);
            snprintf(sndbuf, BUFLENGHT, "Turning PA9 off!\r\n");
            USART2_SendString(sndbuf);
            GPIOA->ODR ^= GPIO_ODR_9;
        }
        lastButtonState2 = currentButtonState2;

        /*Morse code logic*/
        if (!(GPIOC->IDR & GPIO_IDR_13) && !(GPIOA->IDR & GPIO_IDR_6))
        {
            snprintf(sndbuf, BUFLENGHT, "Running morse code!(.... . .-.. .-.. ---)\r\n");
            USART2_SendString(sndbuf);
            Morse_code();
        }
    }
}