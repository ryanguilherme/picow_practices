#include "pico/stdlib.h"

/* GPIO PORT DEFINITIONS */
#define PIR_IN     28
#define BUZZER_OUT 20

int main() {
    gpio_init(PIR_IN);
    gpio_init(BUZZER_OUT);
    gpio_set_dir(PIR_IN, GPIO_IN);
    gpio_set_dir(BUZZER_OUT, GPIO_OUT);
    while (1) {
        if (gpio_get(PIR_IN)) {
            if (!gpio_get(BUZZER_OUT))
                gpio_put(BUZZER_OUT, 1);
        }
        else {
            if (gpio_get(BUZZER_OUT))
                gpio_put(BUZZER_OUT, 0);
        }
    }
    return 0;
}
