#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"

/* ==========================================
 * Function:    led_init
 * Description: INIT A GPIO AND SET AS OUTPUT
 * ==========================================
 */
void led_init(uint GPIO) {
    gpio_init(GPIO);
    gpio_set_dir(GPIO, GPIO_OUT);
}

/* =============================================
 * Function:    led_blink
 * Description: SEND 1 TO A GPIO, AND 0 AFTER MS
 * =============================================
 */
void led_blink(uint GPIO, uint MS) {
    gpio_put(GPIO, 1);
    sleep_ms(MS);
    gpio_put(GPIO, 0);
    sleep_ms(MS);
}

/* =========================================
 * Function:    button_init
 * Description: INIT A GPIO AND SET AS INPUT
 * =========================================
 */
void button_init(uint GPIO) {
    gpio_init(GPIO);
    gpio_set_dir(GPIO, GPIO_IN);
}

/* ===========================================
 * Function:    generate_random_sequence
 * Description: Generate a random led sequence
 *              to be the genius main sequence
 * ===========================================
 */


int main() {

}
