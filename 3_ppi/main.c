#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main() {
    gpio_init();
    gpiote_init();
    init_PPI();

    while (1) {
        int a = 2;
        a = a+2;

        a = a*a;
    }
}