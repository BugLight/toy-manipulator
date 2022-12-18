#include <stm32f103xb.h>

void HardFault_Handler() {
    // Stub hard fault handler
    while (1) {}
}

void Delay(unsigned t) {
    // TODO: Use Sys Clock instead
    volatile unsigned i = 0;
    for (; i < t; ++i);
}

int main() {
    // Blinks the led just for now
    RCC->APB2ENR |= (1ul << 4);

    GPIOC->CRH &= ~(0xFul << 20);
    GPIOC->CRH |= 0x6ul << 20;
    while (1) {
        GPIOC->BSRR |= 1ul << 13;
        Delay(500000);
        GPIOC->BRR |= 1ul << 13;
        Delay(500000);
    }
    return 0;
}
