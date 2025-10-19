#pragma once
#include <string>
#include "stm32f303xe.h"

class Uart2
{
public:
    explicit Uart2(uint32_t baud = 9600);
    void init();
    void send(const char *s);
    std::string recvLine(); // blocks until '\n'
private:
    static constexpr size_t RXBUF = 100;
    char buf_[RXBUF];
    uint32_t baud_;
};