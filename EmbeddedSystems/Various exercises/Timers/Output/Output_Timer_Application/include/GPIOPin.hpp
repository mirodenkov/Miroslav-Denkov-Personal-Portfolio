#pragma once
#include "stm32f303xe.h"

enum class GpioMode
{
    Input,
    Output
};
enum class GpioPull
{
    None,
    PullUp,
    PullDown
};
enum class GpioAltFunc
{
    AF0 = 0,
    AF1,
    AF2,
    AF3,
    AF4,
    AF5,
    AF6,
    AF7,
    AF8,
    AF9,
    AF10,
    AF11,
    AF12,
    AF13,
    AF14,
    AF15
};

class GpioPin
{
private:
    GPIO_TypeDef *port_;
    uint8_t pin_;
    GpioMode mode_;
    GpioPull pull_;

public:
    GpioPin(GPIO_TypeDef *port, uint8_t pin, GpioMode mode, GpioPull pull = GpioPull::None);
    void init();
    void digitalWrite(bool input);
    bool digitalRead() const;
};