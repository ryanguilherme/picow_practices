#include <pico/printf.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/timer.h"

/* DEFINITIONS */
#define TRIGGER      19
#define ECHO         18

void setup() {
    gpio_init(TRIGGER);
    gpio_init(ECHO);
    gpio_set_dir(TRIGGER, GPIO_OUT);
    gpio_set_dir(ECHO, GPIO_IN);
}

int main() {

    setup();

    while (1) {
        gpio_put(TRIGGER, 1);
        sleep_us(10);
        gpio_put(TRIGGER, 0);

        uint32_t time = time_us_32();
        while (gpio_get(ECHO) == 0) {};

        time = time_us_32();

        uint32_t pulse_duration = time_us_32() - time;
        float distance = (float)pulse_duration / 58.0f;

        printf("Distance: %.2f cm\n", distance);
        sleep_ms(500);
    }
    return 0;

}
