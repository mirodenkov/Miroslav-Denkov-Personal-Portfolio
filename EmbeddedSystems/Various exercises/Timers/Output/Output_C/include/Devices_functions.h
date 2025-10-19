//
// Created by pyronit3 on 5/10/25.
//

#ifndef LED_FUNCTIONS_H
#define LED_FUNCTIONS_H
#include "Timer_functions.h"
#include "System_Functions.h"

/**
 * @brief: Configures and initializes pins
 *  @note All pins should be initialized there
 */
void GPIOx_Init();

/**
 * @brief Brightens LED
 */
void LED_up();

/**
 * @brief Dims LED
 */
void LED_down();

/**
 * @brief Does the breathing routine(brightens up then dims down)
 */
void LED_Breathe(uint32_t interval_ms);

void servo_set_angle(int16_t angle);

void servo_move(uint32_t stepDelay);

#endif //LED_FUNCTIONS_H
