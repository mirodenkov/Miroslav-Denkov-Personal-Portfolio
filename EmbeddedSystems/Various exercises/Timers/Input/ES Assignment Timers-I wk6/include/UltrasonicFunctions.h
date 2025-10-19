#pragma once

#include "TimerInits.h"

extern const int BUFLENGTH;
extern char sndBuf[];
extern volatile int distance;
extern volatile uint32_t pulseWidth;

/// @brief Function which starts trigger and prints distance
/// @param nanoSeconds Trigger in nanoseconds
extern void PrintTrigger(int nanoSeconds);

/// @brief Function that resets counter and switches to Falling Edge
/// @param void Empty
extern void ResetCounter(void);

/// @brief Function that measures current distance and switches to Rising Edge
/// @param void Empty
extern void MeasureDistance(void);

