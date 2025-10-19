#pragma once
#include "stm32f303xe.h"

class SysTickTimer
{
private:
    static volatile uint32_t msTicks_;

public:
    SysTickTimer(int tickFreqHz = 1000);
    static void tick();
    static uint32_t millis() ;
    static void delay(uint32_t ms);
};