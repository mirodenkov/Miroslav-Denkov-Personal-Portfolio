#include "LED.h"
#include <Arduino.h>


LED::LED(int pinNumber)
{
    pin = pinNumber;
}
void LED::setPinmode()
{
    pinMode(pin, OUTPUT); //set the pinMode to OUTPUT
    digitalWrite(pin, LOW); //make sure the LED is off
}

void LED::on()
{
    digitalWrite(pin, HIGH);
}

void LED::off()
{
    digitalWrite(pin,LOW);
}