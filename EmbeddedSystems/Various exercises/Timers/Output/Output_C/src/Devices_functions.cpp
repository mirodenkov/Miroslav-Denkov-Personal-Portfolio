//
// Created by pyronit3 on 5/10/25.
//

#include "Devices_functions.h"

void GPIOx_Init() {
    // enable GPIOB and GPIOA clock
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOAEN;

    // set PB6 as output and set AF
    GPIOB->MODER &= ~GPIO_MODER_MODER6_Msk;
    GPIOB->MODER |= GPIO_MODER_MODER6_1;
    GPIOB->AFR[0] &= ~GPIO_AFRL_AFRL6_Msk;
    GPIOB->AFR[0] |= (2U << GPIO_AFRL_AFRL6_Pos);

    // PA7 as output and set AF
    GPIOA->MODER &= ~GPIO_MODER_MODER7_Msk;
    GPIOA->MODER |= GPIO_MODER_MODER7_1;
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFRL7_Msk;
    GPIOA->AFR[0] |= (2U << GPIO_AFRL_AFRL7_Pos);
}

void LED_up() {
    if (TIM4->CCR1 < TIM4->ARR) {
        TIM4->CCR1++;
    }
}

void LED_down() {
    if (TIM4->CCR1 > 0) {
        TIM4->CCR1--;
    }
}

void LED_Breathe(uint32_t intervalMs) {
    TIM4->CCR1 = 0; //start at 0

    uint32_t lastTick = GetMillis();

    // 2) up from 0 to 100%
    while (TIM4->CCR1 < TIM4->ARR) {
        // has intervalMs elapsed?
        if ((uint32_t) (GetMillis() - lastTick) >= intervalMs) {
            lastTick += intervalMs; // roll forward
            LED_up();
        }
    }

    // 3) down from 100% to 0%
    while (TIM4->CCR1 > 0) {
        if ((uint32_t) (GetMillis() - lastTick) >= intervalMs) {
            lastTick += intervalMs;
            LED_down();
        }
    }
}


void servo_set_angle(int16_t angle) {
    if (angle < -180)
        angle = -180;
    else if (angle > 180)
        angle = 180;
    TIM3->CCR2 = 1500 + (angle * 1000) / 180;
}

void servo_move(uint32_t stepDelay) {
    for (int16_t angle = -180; angle <= 180; ++angle) {
        servo_set_angle(angle);
        if (angle == 0) {
            Delay(1000);
        }
        Delay(stepDelay);
    }
    // sweep down
    for (int16_t angle = 180; angle >= -180; --angle) {
        servo_set_angle(angle);
        if (angle == 0) {
            Delay(1000);
        }
        Delay(stepDelay);
    }
}
