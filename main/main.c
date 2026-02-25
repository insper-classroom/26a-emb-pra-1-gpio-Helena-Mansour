#include "hardware/gpio.h"
#include "pico/stdlib.h"

const int BTN = 15;
const int LED = 14;


const int IN1 = 13;
const int IN2 = 12;
const int IN3 = 11;
const int IN4 = 10;

void step_motor() {
    gpio_put(IN1, 1);
    gpio_put(IN2, 0);
    gpio_put(IN3, 0);
    gpio_put(IN4, 0);
    sleep_ms(2);

    gpio_put(IN1, 0);
    gpio_put(IN2, 1);
    gpio_put(IN3, 0);
    gpio_put(IN4, 0);
    sleep_ms(2);

    gpio_put(IN1, 0);
    gpio_put(IN2, 0);
    gpio_put(IN3, 1);
    gpio_put(IN4, 0);
    sleep_ms(2);

    gpio_put(IN1, 0);
    gpio_put(IN2, 0);
    gpio_put(IN3, 0);
    gpio_put(IN4, 1);
    sleep_ms(2);
}

int main() {
    stdio_init_all();

    gpio_init(BTN);
    gpio_set_dir(BTN, GPIO_IN);
    gpio_pull_up(BTN);


    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);


    gpio_init(IN1); gpio_set_dir(IN1, GPIO_OUT);
    gpio_init(IN2); gpio_set_dir(IN2, GPIO_OUT);
    gpio_init(IN3); gpio_set_dir(IN3, GPIO_OUT);
    gpio_init(IN4); gpio_set_dir(IN4, GPIO_OUT);

    while (true) {

        if (!gpio_get(BTN)) {

      
            gpio_put(LED, 1);

            for (int i = 0; i < 512; i++) {
                step_motor();
            }

            gpio_put(LED, 0);

            while (!gpio_get(BTN));
            sleep_ms(200);
        }
    }
}