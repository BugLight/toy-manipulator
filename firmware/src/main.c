#include <stm32f1xx.h>

void SystemClock_Config(void);

void GPIO_Config(void);

int main(void) {
    HAL_Init();

    SystemClock_Config();
    GPIO_Config();

    while (1) {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
        HAL_Delay(500);
    }
    return 0;
}

void SystemClock_Config(void) {
    RCC_OscInitTypeDef oscInitStruct = {
        .HSIState = RCC_HSI_ON,
        .HSEState = RCC_HSE_OFF,
        .LSEState = RCC_LSE_OFF,
        .LSIState = RCC_LSI_OFF,
        .HSEPredivValue = RCC_HSE_PREDIV_DIV1,
        .OscillatorType = RCC_OSCILLATORTYPE_HSI,
        .HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT,
        .PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2,
        .PLL.PLLState = RCC_PLL_ON,
        .PLL.PLLMUL = RCC_PLL_MUL16
    };

    RCC_ClkInitTypeDef clkInitStruct = {
        .ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2,
        .SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK,
        .AHBCLKDivider = RCC_SYSCLK_DIV1,
        .APB1CLKDivider = RCC_HCLK_DIV2,
        .APB2CLKDivider = RCC_HCLK_DIV1
    };

    if (HAL_RCC_OscConfig(&oscInitStruct) != HAL_OK) {
        while (1);
    }

    if (HAL_RCC_ClockConfig(&clkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
        while (1);
    }
}

void GPIO_Config(void) {
    GPIO_InitTypeDef gpioInitStruct = {
        .Pin = GPIO_PIN_13,
        .Mode = GPIO_MODE_OUTPUT_PP,
        .Pull = GPIO_NOPULL,
        .Speed = GPIO_SPEED_FREQ_LOW
    };

    __HAL_RCC_GPIOC_CLK_ENABLE();
    HAL_GPIO_Init(GPIOC, &gpioInitStruct);
}
