#include "gpio.h"
#include "uart.h"

void uart_init() {
    GPIO0->PIN_CNF[__UART_RX_PIN__] = 0b0;
    GPIO1->PIN_CNF[__UART_TX_PIN__] = 0b1;

    UART->PSEL_RXD = 0b11 << 1;
    UART->PSEL_TXD = 0b1 << 5 | 0b1 << 3;
    UART->BAUDRATE = 0x00275000;
    UART->PSEL_RTS = 0b1 << 31;
    UART->PSEL_CTS = 0b1 << 31;
    UART->ENABLE = 0b1 << 2;
    UART->TASKS_STARTRX = 0b1;
}

void uart_send(char letter) {
    UART->TASKS_STARTTX = 0b1;
    UART->EVENTS_TXDRDY = 0b0;
    
    UART->TXD = letter;

    while (1) {
        if (UART->EVENTS_TXDRDY) {
            UART->TASKS_STOPTX = 0b1;
            break;
        }
    }
}

char uart_read() {
    UART->TASKS_STARTRX = 0b1;
    UART->EVENTS_RXDRDY = 0b0;

    char byte_read = '\0';

    //while (1) {
        if (UART->EVENTS_RXDRDY) {
            byte_read = UART->RXD;
            //break;
        }
    //}
    UART->TASKS_STOPRX = 0b1;
    return byte_read;
}