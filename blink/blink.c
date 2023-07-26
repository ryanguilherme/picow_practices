#include <stdio.h>
#include "pico/stdlib.h"

void led_init(uint GPIO) {
    gpio_init(GPIO);
    gpio_set_dir(GPIO, GPIO_OUT);
}

void led_blink(uint GPIO, uint MS) {
    gpio_put(GPIO, 1);
    sleep_ms(MS);
    gpio_put(GPIO, 0);
    sleep_ms(MS);
}

/* GPIO VALUE DECLARATION */

const uint LED1 = 26;
const uint LED2 = 27;

int main() {
    stdio_init_all();

    led_init(LED1);
    led_init(LED2);

    while (1) {
        led_blink(LED1, 250);
        led_blink(LED2, 250);
    }

}
