#include "gpio.h"
#include "uart.h"
#include <stdio.h>
#include <newlib.h>


#define __BUTTON_A_PIN__ 14
#define __BUTTON_B_PIN__ 23


ssize_t _write(int fd, const void *buf, size_t count){
char * letter = (char *)(buf);
for(int i = 0; i < count; i++){
uart_send(*letter);
letter++;
}
return count;
}

int main() {
    gpio_init();
    uart_init();

    int sleep = 0;
    int light_bool = 0;

    while (1) {

        if (!(GPIO0->IN & (1 <<__BUTTON_B_PIN__))) {
            uart_send('B');
            iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235 \
    ,2019,2018,'C');
        }

        if (!(GPIO0->IN & (1 <<__BUTTON_A_PIN__))) {
            uart_send('A');
        }

        if (uart_read() != '\0') {
            if (light_bool) {
                gpio_lights_off();
                light_bool = 0;
                uart_send('B');
            }
            else {
                gpio_lights_on();
                light_bool = 1;
            }
        }

    sleep = 100000*5;
	while(--sleep);
    }

    return 0;
}