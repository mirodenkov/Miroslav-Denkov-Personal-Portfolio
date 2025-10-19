//
// Created by pyronit3 on 5/10/25.
//
#include "System_Functions.h"
volatile uint32_t msTicks = 0;



#ifndef _cplusplus
extern "C"
{
#endif

    void SysTick_Handler(void)
    {
        msTicks++; // Increment every 1ms
    }
}
#ifdef _cplusplus
#endif

uint32_t GetMillis(void)
{
    return msTicks;
}

// Configure the system clock to 72 MHz. This means the APB1 peripheral clock and also the USART2 will be clocked at 36 MHz.
void SystemClock_Config(void)
{
    // Configure Flash latency for 48 < HCLK ≤ 72 MHz, see datasheet. Do this before setting the system clock to 72 MHz.
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR |= FLASH_ACR_LATENCY_2;

    // Enable the HSI (internal high-speed) oscillator
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY))
        ; // Wait until HSI is ready

    // Set the APB1 prescaler to 2
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    // Set the PLL SRC to HSI and PREDIV to /1
    RCC->CFGR &= ~RCC_CFGR_PLLSRC;
    RCC->CFGR |= RCC_CFGR_PLLSRC_HSI_PREDIV;

    // Set PLL multiplier to 9 (8 MHz * 9 = 72 MHz)
    RCC->CFGR &= ~RCC_CFGR_PLLMUL;
    RCC->CFGR |= RCC_CFGR_PLLMUL9;

    // Enable the PLL
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY))
        ; // Wait until PLL is ready

    // Select PLL as system clock source
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
        ; // Wait until PLL becomes the system clock

    // Update the system core clock variable
    SystemCoreClockUpdate();
}



// Initialize USART2
void USART2_Init(void)
{
    // Enable USART2 clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    // Set GPIO pin PA2 to alternate function.
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER2) | (0b10 << GPIO_MODER_MODER2_Pos);
    // Select alternate function AF7 (USART2_TX) for GPIO pin PA2.
    GPIOA->AFR[0] = (GPIOA->AFR[0] & ~GPIO_AFRL_AFRL2) | (0b0111 << GPIO_AFRL_AFRL2_Pos);
    // Set GPIO pin PA3 to alternate function.
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER3) | (0b10 << GPIO_MODER_MODER3_Pos);
    // Select alternate function AF7 (USART2_RX) for GPIO pin PA3.
    GPIOA->AFR[0] = (GPIOA->AFR[0] & ~GPIO_AFRL_AFRL3) | (0b0111 << GPIO_AFRL_AFRL3_Pos);

    // Configure USART2
    USART2->BRR = - / 9600; // Assuming 36 MHz clock, 9600 baud rate.
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

void SysTick_Init(void)
{
    SysTick->LOAD = (SystemCoreClock / 1000) - 1;
    SysTick->VAL = 0; // reset the counter
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}

// Send a string through USART2.
void USART2_SendString(char *str)
{
    while (*str)
    {
        // Wait until transmit data register is empty.
        while (!(USART2->ISR & USART_ISR_TXE))
            ;
        USART2->TDR = *str++;
    }
}

// Receive a string through USART2
// This function blocks until a newline '\n' character is received.
char *USART2_ReceiveString(char rcvBuf[])
{
    static int i = 0;
    char c = 0;
    USART2->ICR |= USART_ICR_ORECF; // Clear overrun error flag.
    while (i == 0 || c != '\0')
    {
        if (USART2->ISR & USART_ISR_RXNE)
        {

            c = USART2->RDR;
            if (c == '\n') // Return received, so string is complete.
            {
                c = '\0'; // Indicate end of string.
                rcvBuf[i++] = c;
            }
            else
            {
                if (i < BUFLENGTH - 1) // Prevent buffer overflow
                {
                    rcvBuf[i++] = c;
                }
            }
        }
    }
    i = 0; // Prepare for next string.
    return rcvBuf;
}

void Delay(uint32_t milliseconds)
{
    uint32_t timeWanted = msTicks + milliseconds;
    while (msTicks < timeWanted)
        ; // wait til time is over
}