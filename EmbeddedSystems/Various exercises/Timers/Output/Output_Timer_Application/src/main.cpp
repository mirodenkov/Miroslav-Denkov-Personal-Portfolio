#include "SystemClock.hpp"
#include "SysTick.hpp"
#include "GPIOPin.hpp"

int main()
{
    SystemClock::config72MHz();
    SysTickTimer systick;

    // init builtin led
    GpioPin ledBuiltin(GPIOA, 5, GpioMode::Output); // set up internal led for testing
    ledBuiltin.init();

    /*Init PB6 and setto AF mode*/

    GpioPin ledPB6(GPIOB, 6, GpioMode::Output);
    GPIOB->MODER &= ~GPIO_MODER_MODER6;           // Clear bits for PB6
    GPIOB->MODER |= (2 << GPIO_MODER_MODER6_Pos); // PB6 to AF mode

    GPIOB->AFR[0] &= ~GPIO_AFRL_AFRL6;           // Clear alternate function bits for PB6
    GPIOB->AFR[0] |= (2 << GPIO_AFRL_AFRL6_Pos); // AF2 for TIM3_CH2 for PB6

    /*millis variables*/
    const uint32_t interval = 1000;
    uint32_t previous_millis_PB6 = 0;

    while (true)
    {
        uint32_t currentMillis = SysTickTimer::millis();

        if (currentMillis - previous_millis_PB6 >= interval)
        {
            previous_millis_PB6 = currentMillis;
            ledPB6.digitalWrite(!ledPB6.digitalRead());
        }
    }
}
