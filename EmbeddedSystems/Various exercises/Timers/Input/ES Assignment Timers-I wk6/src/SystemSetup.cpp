#include "SystemSetup.h"

volatile uint32_t msTicks = 0;

void SysTick_Init(void)
{
    // CTRL must be manipulated to enable/disable the SysTick timer
    SysTick->CTRL = 0; // Disable SysTick

    // SystemCl runs at 72MHz, you must divide it by 1000 to count down from 72.000
    SysTick->LOAD = (SystemCoreClock / 1000) - 1; // Set reload register

    // Reset the SysTick counter value
    SysTick->VAL = 0; // When the value reaches 0 while running, an interrupt will occur and reset

    // Enable timer, interrupt, and processor clock
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}

void GPIOA_Trigger_Init(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    GPIOA->MODER &= ~GPIO_MODER_MODER6;    // Clear bits for PA6
    GPIOA->MODER |= (GPIO_MODER_MODER6_1); // PA6 to AF Mode

    GPIOA->AFR[0] &= ~(GPIO_AFRL_AFRL6);               // Clear AF bits for PA6
    GPIOA->AFR[0] |= (AF_TIM4 << GPIO_AFRL_AFRL6_Pos); // AF2 (TIM3_CH1) for PA6
}

void GPIOB_Echo_Init(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    GPIOB->MODER &= ~GPIO_MODER_MODER6;  // Clear bits for PB6
    GPIOB->MODER |= GPIO_MODER_MODER6_1; // PB6 to AF Mode

    GPIOB->AFR[0] &= ~GPIO_AFRL_AFRL6;                 // Clear AF bits for PB6
    GPIOB->AFR[0] |= (AF_TIM4 << GPIO_AFRL_AFRL6_Pos); // AF2 (TIM3_CH1) for PB6
}

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
    USART2->BRR = 36000000 / 9600; // Assuming 36 MHz clock, 9600 baud rate.
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

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

extern "C" void SysTick_Handler(void)
{
    msTicks++;
}

uint32_t GetMillis(void)
{
    return msTicks;
}

void Delay(uint32_t ms)
{
    uint32_t startTime = GetMillis();

    while (GetMillis() - startTime < ms)
        ;
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