#include <clock.h>

#include <stm32f1xx.h>

int main() {
    Clock_Init();
    // Blinks the led just for now
    RCC->APB2ENR |= (1ul << 4);

    GPIOC->CRH &= ~(0xFul << 20);
    GPIOC->CRH |= 0x6ul << 20;
    while (1) {
        GPIOC->BSRR |= 1ul << 13;
        Clock_Delay(500000);
        GPIOC->BRR |= 1ul << 13;
        Clock_Delay(500000);
    }
    return 0;
}
