#include <stdio.h>
#include "pico/stdlib.h"

void led_init(uint GPIO) {
    gpio_init(GPIO);
    gpio_set_dir(GPIO, GPIO_OUT);
}

void button_init(uint GPIO) {
    gpio_init(GPIO);
    gpio_set_dir(GPIO, GPIO_IN);
}

/* GPIO VALUE DECLARATION */
const uint BUTTON1 = 22;
const uint LED1    = 27;
const uint LED2    = 26;

void delay(long long int MS) {
    for (int i = 0; i <= MS; i++) { }
}

int main() {
    button_init(BUTTON1);
    led_init(LED1);
    led_init(LED2);
    uint flag = 0;

    while (1) {
//        uint led1_flag = gpio_get(LED1);
//        uint led2_flag = gpio_get(LED2);
        if (gpio_get(BUTTON1)) {
            flag ^= 1;
        }
        if (flag) {
            gpio_set_dir(LED1, 1);
            gpio_set_dir(LED2, 1);
            delay(1500000000000000000);
        }else {
            gpio_set_dir(LED1, 0);
            gpio_set_dir(LED2, 0);
            delay(1500000000000000000);
        }
    }
}
