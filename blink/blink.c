/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "hardware/timer.h"

// 简单延时函数，避免硬件定时器干扰调试
static void simple_delay(volatile uint32_t loops) {
    while (loops--) {
        __asm volatile ("nop");
    }
}

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    volatile int count = 0;  // 用于调试观察
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        count++;  // 在此设置断点
        gpio_put(LED_PIN, 1);
        simple_delay(500000);
        gpio_put(LED_PIN, 0);
        simple_delay(500000);
    }
#endif
}
