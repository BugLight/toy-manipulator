#include <clock.h>

#include <stdint.h>

#include <stm32f1xx.h>

volatile uint64_t ticks;

volatile uint64_t rtc;

void Clock_Init() {
    // Select HSI as PLL source
    RCC->CFGR &= ~RCC_CFGR_PLLSRC;
    // Set PLL multiplier to x12
    RCC->CFGR &= ~RCC_CFGR_PLLMULL;
    RCC->CFGR |= RCC_CFGR_PLLMULL12;
    // Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    // Select PLL as SYSCLCK source
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
}

void Clock_Delay(uint64_t us) {
    const uint64_t until = rtc + us;
    while (rtc < until);
}

