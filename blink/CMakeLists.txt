cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(blink)

pico_sdk_init()

add_executable(blink    
blink.c
)

pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

pico_add_extra_outputs(blink)

target_link_libraries(blink pico_stdlib)