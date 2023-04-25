#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

int main() {
    gpio_init();
    gpiote_init();
    init_PPI();

    int sleep = 0;
    while (1) {
        sleep = 100;
        while(sleep--);
    }
    
    return 0;
}