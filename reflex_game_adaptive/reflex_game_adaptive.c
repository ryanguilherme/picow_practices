#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

const int BUTTON_PINS[4] = {12, 13, 14, 15};
const int LED_PINS[4] = {16, 17, 18, 19};

volatile bool timer_fired = false;
int delay_amount = 1500;
const int min_delay_amount = 500, max_delay_amount = 1500, delay_reduction_amount = 50;

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    printf("Alarm Fired\n");
    timer_fired = true;
    return delay_amount*1000; // uS
}

int main() {
    stdio_init_all();
    printf("Reflex Game!\n");

    add_alarm_in_ms(delay_amount, alarm_callback, NULL, false);

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
            delay_amount = delay_amount > min_delay_amount ? delay_amount - delay_reduction_amount : min_delay_amount;
            score++;
            sleep_ms(20); // so the LED don't appear to never being turned off when repeated
        }
        else {
            printf("Miss!\n");
            score = 0;
            delay_amount = max_delay_amount;
        }

        printf("Your score is: %d\nCurrent delay: %d\n", score, delay_amount);

        while(!timer_fired) tight_loop_contents();

        timer_fired = false;


    }

    return 0;
}
