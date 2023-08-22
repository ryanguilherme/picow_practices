#include <pico/printf.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/timer.h"

/* DEFINITIONS */
#define TRIGGER      19
#define ECHO         18
#define LED_PIN      16

void setup() {
    gpio_init(TRIGGER);
    gpio_init(ECHO);
    gpio_init(LED_PIN);
    gpio_set_dir(TRIGGER, GPIO_OUT);
    gpio_set_dir(ECHO, GPIO_IN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

int main() {

    setup();

    while (1) {
        gpio_put(LED_PIN, 0);
        gpio_put(TRIGGER, 1);
        sleep_us(10);
        gpio_put(TRIGGER, 0);

        while (gpio_get(ECHO) == 0);
        uint32_t time = time_us_32();

        while (gpio_get(ECHO) == 1);
        uint32_t final_time = time_us_32();

        uint32_t pulse_duration = final_time - time;
        double distance = ((double)pulse_duration * 0.000343) / 2;

        if (distance <= 1) {
            gpio_put(LED_PIN, 1);
            sleep_ms(500);
            gpio_put(LED_PIN, 0);
        }

        printf("Distance: %.2f cm\n", distance);
        sleep_ms(500);
    }
    return 0;

}
