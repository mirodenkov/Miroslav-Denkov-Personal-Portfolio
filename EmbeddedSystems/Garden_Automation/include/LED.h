#ifndef LED_H
#define LED_H

class LED
{
private:
     int pin;

public:
    LED(int pinNumber); // constructor with pin number
    void setPinmode(); //sets the pinMode
    /*These two functions turn the LED on and OFF*/
    void on();
    void off();

};

#endif
