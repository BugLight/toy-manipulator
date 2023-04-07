#ifndef CLOCK_H_
#define CLOCK_H_

#include <stdint.h>

#define SYSCLCK_FREQUENCY 48000000

extern volatile uint64_t ticks;  // SysTick counter
extern volatile uint64_t rtc;    // Realtime clock in us

void Clock_Init();

void Clock_Delay(uint64_t us);

#endif  // CLOCK_H_
