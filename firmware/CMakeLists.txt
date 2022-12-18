cmake_minimum_required(VERSION 3.20)

project(toy-manipulator-firmware C ASM)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=nosys.specs -T ${CMAKE_SOURCE_DIR}/STM32F103XB_FLASH.ld")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m3")

include_directories(inc/)

add_executable(firmware.elf src/main.c src/startup_stm32f103xb.s src/system_stm32f1xx.c)
