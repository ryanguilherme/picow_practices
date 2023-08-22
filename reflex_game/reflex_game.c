#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

const int BUTTON_PINS[4] = {12, 13, 14, 15};
const int LED_PINS[4] = {16, 17, 18, 19};

volatile bool timer_fired = false;

bool repeating_timer_callback(struct repeating_timer *t) {
    timer_fired = true;
    return true;
}

int main() {
    stdio_init_all();
    printf("Reflex Game!\n");

    struct repeating_timer timer;
    add_repeating_timer_ms(1000, repeating_timer_callback, NULL, &timer);

    int score = 0;
    int led_index = 0;

    // INITIALIZE LED AND BUTTONS GPIOS AND SET DIRECTIONS
    for (int i = 0; i < 4; i++) {
        gpio_init(LED_PINS[i]);
        gpio_set_dir(LED_PINS[i], GPIO_OUT);
        gpio_init(BUTTON_PINS[i]);
        gpio_set_dir(BUTTON_PINS[i], GPIO_IN);
        gpio_pull_up(BUTTON_PINS[i]);
    }

    srand(time(0));

    while (1)
    {
        bool button_pressed = false;
        gpio_put(LED_PINS[led_index], 0);    // turn off the LED from the last round
        led_index = rand() % 4;                         // generate new LED index
        printf("Firing LED %d\n", led_index);
        gpio_put(LED_PINS[led_index], 1);    // turn on the new LED

        while(!timer_fired)
        {
            if(!gpio_get(BUTTON_PINS[led_index])) {
                button_pressed = true;
                break;
            }
            sleep_ms(20);
        }

        if(button_pressed) {
            gpio_put(LED_PINS[led_index], 0);
            printf("Gotcha!\n");
            score++;
        }
        else {
            printf("Miss!\n");
            score = 0;
        }

        printf("Your score is: %d\n", score);

        while(!timer_fired) tight_loop_contents();

        timer_fired = false;


    }

    return 0;
}
