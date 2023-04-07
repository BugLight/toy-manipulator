#include <clock.h>

void SysTick_Handler() {
    ++ticks;
    if (ticks % SYSCLCK_FREQUENCY == 0) {
        ++rtc;
    }
}

void HardFault_Handler() {
    // Stub hard fault handler
    while (1) {}
}
