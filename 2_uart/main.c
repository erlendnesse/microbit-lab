#include "gpio.h"
#include "uart.h"

#define __BUTTON_A_PIN__ 14
#define __BUTTON_B_PIN__ 23

int main() {
    gpio_init();
    uart_init();

    int sleep = 0;
    while (1) {

        if (!(GPIO0->IN & (1 <<__BUTTON_B_PIN__))) {
            gpio_lights_on();
            uart_send('B');
        }

        if (!(GPIO0->IN & (1 <<__BUTTON_A_PIN__))) {
            gpio_lights_off();
            uart_send('A');
        }

        if (uart_read() != '\0') {
            gpio_lights_on();
        }

    sleep = 10000;
	while(--sleep);
    }

    return 0;
}