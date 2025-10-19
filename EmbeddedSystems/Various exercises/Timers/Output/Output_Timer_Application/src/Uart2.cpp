#include "Uart2.hpp"

Uart2::Uart2(uint32_t baud) : baud_(baud) {}

void Uart2::init()
{
    // 1) enable clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    // 2) gpio af7 on PA2/PA3 (same as your code)…
    // 3) set baud: USART2->BRR = (PCLK1 / baud_)
    USART2->BRR = (36'000'000U / baud_);
    USART2->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
}

void Uart2::send(const char *s)
{
    while (*s)
    {
        while (!(USART2->ISR & USART_ISR_TXE))
        {
        }
        USART2->TDR = *s++;
    }
}

std::string Uart2::recvLine()
{
    size_t i = 0;
    char c;
    // clear ORE
    USART2->ICR |= USART_ICR_ORECF;
    do
    {
        while (!(USART2->ISR & USART_ISR_RXNE))
        {
        }
        c = USART2->RDR;
        if (c == '\n' || i + 1 >= RXBUF)
            break;
        buf_[i++] = c;
    } while (true);
    buf_[i] = '\0';
    return std::string(buf_);
}