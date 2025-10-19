

#include "functions.h"
volatile int encoder_count = 0;
char sndbuf[BUFLENGHT];

#ifdef __cplusplus
extern "C"
{
#endif

    void EXTI15_10_IRQHandler(void)
    {
        if (EXTI->PR & (1 << 13))
        {
            sniprintf(sndbuf, BUFLENGHT, "Toggling LED with interrupt!\r\n");
            USART2_SendString(sndbuf);
            EXTI->PR |= (1 << 13);
            GPIOA->ODR ^= GPIO_ODR_8;
        }
    }

    // Interrupt Service Routine (ISR) for EXTI7 (PA7 - CLK/A)
    void EXTI9_5_IRQHandler(void)
    {
        if (EXTI->PR & EXTI_PR_PR7) // Check if EXTI7 caused the interrupt
        {
            EXTI->PR |= EXTI_PR_PR7; // Clear EXTI7 flag

            if ((GPIOB->IDR & GPIO_IDR_6)) // Read PB6 (DT/B)
            {
                encoder_count++; // Clockwise rotation
            }
            else
            {
                encoder_count--; // Counterclockwise rotation
            }
        }
    }

#ifdef __cplusplus
}
#endif

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

    // Set pin PA8 as output -> LED 1, red
    GPIOA->MODER &= ~GPIO_MODER_MODER8;
    GPIOA->MODER |= (0b01 << GPIO_MODER_MODER8_Pos);

    // Set pin PA9 as output -> LED2, green
    GPIOA->MODER &= ~GPIO_MODER_MODER9;
    GPIOA->MODER |= (0b01 << GPIO_MODER_MODER9_Pos);

    // Set pin PA6 as INPUT_PULLUP -> button 1
    GPIOA->MODER &= ~GPIO_MODER_MODER6;
    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR6;
    GPIOA->PUPDR |= GPIO_PUPDR_PUPDR6_0;

    // Set built-in button as input
    GPIOC->MODER &= ~GPIO_MODER_MODER13_Msk;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR13_Msk;
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

void GPIO_Interrupt_Init(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOCEN;
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; // Enable system configuration controller (SYSCFG)

    GPIOC->MODER &= ~GPIO_MODER_MODER13_Msk; // Set PC13 as input
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR13_Msk; // Clear pull-up/pull-down configuration
    GPIOC->PUPDR |= GPIO_PUPDR_PUPDR13_0;    // Enable internal pull-up (optional, if no external pull)

    GPIOA->MODER &= ~GPIO_MODER_MODER8_Msk;
    GPIOA->MODER |= GPIO_MODER_MODER8_0; // Set PA8 as output

    SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI13_Msk; // clear EXTI6 mapping
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;   // map EXTI6 to PC13

    EXTI->IMR |= EXTI_IMR_IM13;   // unmask EXTI6 interrupt
    EXTI->FTSR |= EXTI_FTSR_FT13; // set falling-edge trigger (button press)

    NVIC_EnableIRQ(EXTI15_10_IRQn); // EXTI6 falls under EXTI9_5 handler

    /*Set up button PA6 as input*/
    GPIOA->MODER &= ~GPIO_MODER_MODER6_Msk;
    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR6_Msk;
    GPIOA->PUPDR |= GPIO_PUPDR_PUPDR6_0; // enable pull-up for PA6

    /*Set up LED PA9 as output*/
    GPIOA->MODER &= ~GPIO_MODER_MODER9_Msk;
    GPIOA->MODER |= GPIO_MODER_MODER9_0; // set as output
}

void GPIO_RotaryEncoder_Init(void)
{

    // enable GPIOB clock
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    // configure CLK PA7
    GPIOA->MODER &= ~GPIO_MODER_MODER7_Msk;
    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR7_Msk;
    GPIOA->PUPDR |= GPIO_PUPDR_PUPDR7_0;

    // configure DT PB6
    GPIOB->MODER &= ~GPIO_MODER_MODER6_Msk;
    GPIOB->PUPDR &= ~GPIO_PUPDR_PUPDR6_Msk;
    GPIOB->PUPDR |= GPIO_PUPDR_PUPDR6_0;

    // configure EXTI for CLK(PA7)
    SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI7_Msk;
    SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI7_PA;

    EXTI->IMR |= EXTI_IMR_IM7;
    EXTI->FTSR |= EXTI_FTSR_FT7;

    // Enable interrupt in NVIC
    NVIC_EnableIRQ(EXTI9_5_IRQn);
}