cmake_minimum_required(VERSION 3.20)

project(toy-manipulator-firmware C ASM)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=nosys.specs -T ${CMAKE_SOURCE_DIR}/STM32F103XB_FLASH.ld")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m3")

include_directories(inc/)
include_directories(stm32f1xx_hal_driver/Inc)

set(HAL_SOURCES
    stm32f1xx_hal_driver/Src/stm32f1xx_hal.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_adc.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_adc_ex.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_can.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_cec.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_cortex.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_crc.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_dac.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_dac_ex.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_dma.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_dma.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_eth.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_exti.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_flash.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_flash_ex.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_gpio.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_gpio_ex.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_hcd.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_i2c.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_i2s.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_irda.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_iwdg.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_mmc.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_nand.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_nor.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_pccard.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_pcd.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_pcd_ex.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_pwr.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_rcc.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_rcc_ex.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_rtc.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_rtc_ex.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_sd.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_smartcard.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_spi.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_sram.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_tim.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_tim_ex.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_uart.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_usart.c
    stm32f1xx_hal_driver/Src/stm32f1xx_hal_wwdg.c
)


set(USER_SOURCES
    src/main.c
    src/startup_stm32f103xb.s
    src/stm32f1xx_it.c
    src/system_stm32f1xx.c
)

add_executable(firmware.elf ${USER_SOURCES} ${HAL_SOURCES})
