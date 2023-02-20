#include <stm32f1xx_it.h>

void HardFault_Handler(void) {
    // Stub hard fault handler
    while (1) {}
}

void SysTick_Handler(void) {
    HAL_IncTick();
}
