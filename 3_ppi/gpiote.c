#include "gpiote.h"

#define POLARITY 16
#define PSEL 8
#define OUTINIT 20

void gpiote_init() {
    int channel_btnA = 0;
    int channel_row1 = 1;
    int channel_row2 = 2;
    int channel_row3 = 3;
    int channel_row4 = 4;
    int channel_row5 = 5;

    GPIOTE->CONFIG[channel_btnA] = __BUTTON_A_PIN__ << PSEL \
    | 0b1 | 0b10 << POLARITY;

    GPIOTE->CONFIG[channel_row1] = __LED_ROW_1__ << PSEL \
    | 0b11 | 0b11 << POLARITY;

    GPIOTE->CONFIG[channel_row2] = __LED_ROW_2__ << PSEL \
    | 0b11 | 0b11 << POLARITY | 0b1 << OUTINIT;

    GPIOTE->CONFIG[channel_row3] = __LED_ROW_3__ << PSEL \
    | 0b11 | 0b11 << POLARITY;

    GPIOTE->CONFIG[channel_row4] = __LED_ROW_4__ << PSEL \
    | 0b11 | 0b11 << POLARITY | 0b1 << OUTINIT;

    GPIOTE->CONFIG[channel_row5] = __LED_ROW_5__ << PSEL \
    | 0b11 | 0b11 << POLARITY;
}





