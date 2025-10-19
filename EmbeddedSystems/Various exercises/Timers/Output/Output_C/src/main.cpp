#include "System_Functions.h"
#include "Devices_functions.h"

int main() {
    //setup
    SystemClock_Config();
    SysTick_Init();
    GPIOx_Init();
    timer_LED_init();
    timer_Servo_init();

    //loop
    while (true) {
        LED_Breathe(1);
        servo_move(20); // Note to self: this moves the servo 1 degree every 20 ms
    }
}
