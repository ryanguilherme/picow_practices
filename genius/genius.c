#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"

/* SEQUENCE SIZE */
#define SIZE 10

/* LED GPIO DECLARATION */
#define RED_LED    2
#define GREEN_LED  3
#define BLUE_LED   4
#define YELLOW_LED 5

/* BUTTON GPIO DECLARATION */
#define RED_BUTTON    6
#define GREEN_BUTTON  7
#define BLUE_BUTTON   8
#define YELLOW_BUTTON 9


typedef enum{
    RED,
    GREEN,
    BLUE,
    YELLOW
}led_color;

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
 * Function:    generate_led_sequence
 * Description: Generate a random led sequence
 *              to be the genius main sequence
 * ===========================================
 */
void generate_led_sequence(led_color sequence[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        int random_number = rand() % 4;

        switch(random_number) {
            case 0:
                sequence[i] = RED;
                break;
            case 1:
                sequence[i] = GREEN;
                break;
            case 2:
                sequence[i] = BLUE;
                break;
            case 3:
                sequence[i] = YELLOW;
                break;
            default:
                sequence[i] = RED;
                break;
        }
    }

}

int main() {

}
