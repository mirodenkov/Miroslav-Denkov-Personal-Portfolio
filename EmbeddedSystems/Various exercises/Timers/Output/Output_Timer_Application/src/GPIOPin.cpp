#include "GPIOPin.hpp"

GpioPin::GpioPin(GPIO_TypeDef *port, uint8_t pin, GpioMode mode, GpioPull pull) : port_(port), pin_(pin), mode_(mode), pull_(pull) {}

void GpioPin::init()
{
    if (port_ == GPIOA)
    {
        RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    }
    if (port_ == GPIOB)
    {
        RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    }
    if (port_ == GPIOC)
    {
        RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
    }

    uint32_t m = (mode_ == GpioMode::Output) ? 1 : 0; // if gpio mode is output be 1 otherwise 0
    port_->MODER &= ~(0b11 << (2 * pin_));
    port_->MODER |= (m << (2 * pin_));

    port_->PUPDR &= ~(0b11 << (2 * pin_));
    port_->PUPDR |= (uint32_t(pull_) << (2 * pin_));
}

void GpioPin::digitalWrite(bool high)
{
    if (high)
        port_->BSRR = (1 << pin_);
    else
        port_->BSRR = (1 << (pin_ + 16));
}

bool GpioPin::digitalRead() const
{
    return (port_->IDR & (1 << pin_)) != 0;
}
