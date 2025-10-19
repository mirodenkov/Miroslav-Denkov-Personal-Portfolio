#include "functions.h"
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

void GPIOx_Init(void)
{
    // Enable GPIOA clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    // Enable GPIOC clock
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

    // Set pin PA5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODER5;            // Reset bits
    GPIOA->MODER |= 0b01 << GPIO_MODER_MODER5_Pos; // Set bits for output mode

    // Set pin PA8 as output -> LED 1, red
    GPIOA->MODER &= ~GPIO_MODER_MODER8;
    GPIOA->MODER |= (1 << GPIO_MODER_MODER8_Pos);

    // Set pin PA9 as output -> LED2, green
    GPIOA->MODER &= ~GPIO_MODER_MODER9;
    GPIOA->MODER |= (1 << GPIO_MODER_MODER9_Pos);

    // Set pin PA7 as INPUT_PULLUP -> button 1
    GPIOA->MODER &= ~GPIO_MODER_MODER7;
    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR7;
    GPIOA->PUPDR |= GPIO_PUPDR_PUPDR7_0;

    // Set pin PA6 as INPUT_PULLUP -> button 1
    GPIOA->MODER &= ~GPIO_MODER_MODER6;
    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR6;
    GPIOA->PUPDR |= GPIO_PUPDR_PUPDR6_0;

    // Set built-in button as input
    GPIOC->MODER &= ~GPIO_MODER_MODER13;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR13;
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
    USART2->BRR = 36000000 / 9600; // Assuming 36 MHz clock, 9600 baud rate.
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
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
                if (i < BUFLENGHT - 1) // Prevent buffer overflow
                {
                    rcvBuf[i++] = c;
                }
            }
        }
    }
    i = 0; // Prepare for next string.
    return rcvBuf;
}

// Simple delay function, should not be used in serious applications.
void Delay(uint32_t time_ms)
{
    volatile uint32_t i, j;

    for (i = 0; i < time_ms; i++)
        for (j = 0; j < 2000; j++)
            ; // Adjust this loop for shorter or longer delays
}

/*the led attached to PA9 says "Hello" in morse code "*/
void Morse_code(void)
{
    // H
    for (int i = 0; i < 4; i++)
    {
        GPIOA->ODR ^= GPIO_ODR_9;
        Delay(300);
        GPIOA->ODR ^= GPIO_ODR_9;
        Delay(300);
    }
    // e
    Delay(1500);
    GPIOA->ODR ^= GPIO_ODR_9;
    Delay(300);
    GPIOA->ODR ^= GPIO_ODR_9;

    // l (repeated twice)
    Delay(1500);
    for (int i = 0; i < 2; i++)
    {
        // .
        GPIOA->ODR ^= GPIO_ODR_9;
        Delay(300);
        GPIOA->ODR ^= GPIO_ODR_9;
        Delay(300);

        //-
        GPIOA->ODR ^= GPIO_ODR_9;
        Delay(1000);
        GPIOA->ODR ^= GPIO_ODR_9;
        Delay(300);

        //. x2
        for (int j = 0; j < 2; j++)
        {
            GPIOA->ODR ^= GPIO_ODR_9;
            Delay(300);
            GPIOA->ODR ^= GPIO_ODR_9;
            Delay(300);
        }
        Delay(1500);
    }

    // o
    for (int i = 0; i < 3; i++)
    {
        GPIOA->ODR ^= GPIO_ODR_9;
        Delay(1000);
        GPIOA->ODR ^= GPIO_ODR_9;
        Delay(300);
    }
}