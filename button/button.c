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
const uint LED2    = 28;

int main() {
    button_init(BUTTON1);
    led_init(LED1);
    led_init(LED2);

    while (1) {
        uint led1_flag = gpio_get(LED1);
        uint led2_flag = gpio_get(LED2);
        if (gpio_get(BUTTON1)) {
            gpio_put(LED1, (led1_flag ^= 1));
            gpio_put(LED2, (led2_flag ^= 1));
        }
    }
}
