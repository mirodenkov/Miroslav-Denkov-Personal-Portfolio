#include "SysTick.hpp"

volatile uint32_t SysTickTimer::msTicks_ = 0;

// this is still the C‐linkage IRQ entry, but now it calls your public API
extern "C" void SysTick_Handler()
{
    SysTickTimer::tick();
}

// the new public tick() just increments the private counter
void SysTickTimer::tick()
{
    msTicks_++;
}

SysTickTimer::SysTickTimer(int tickFreqHz)
{
    // reload = SystemCoreClock/tickFreqHz – 1
    SysTick->LOAD = (SystemCoreClock / tickFreqHz) - 1;
    SysTick->VAL = 0; // clear current
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}

void SysTickTimer::delay(uint32_t ms)
{
    uint32_t end = msTicks_ + ms;
    while (msTicks_ < end)
    {
        ;
    }
}

uint32_t SysTickTimer::millis()
{
    return msTicks_;
}