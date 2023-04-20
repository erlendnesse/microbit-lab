#ifndef GPIOTE_H
#define GPIOTE_H
#include <stdint.h>

#define GPIOTE ((NRF_GPIOTE_REG*)0x40006000)

#define __BUTTON_A_PIN__ 14
#define __LED_ROW_1__ 21
#define __LED_ROW_2__ 22
#define __LED_ROW_3__ 15
#define __LED_ROW_4__ 24
#define __LED_ROW_5__ 19

typedef struct {
	// Tasks
	volatile uint32_t TASKS_OUT[8];
	volatile uint32_t RESERVED0[4];
	volatile uint32_t TASKS_SET[8];
	volatile uint32_t RESERVED1[4];
	volatile uint32_t TASKS_CLR[8];
	// Events
	volatile uint32_t RESERVED2[32];
	volatile uint32_t EVENTS_IN[8];
	volatile uint32_t RESERVED3[23];
	volatile uint32_t EVENTS_PORT;
	// Registers
	volatile uint32_t RESERVED4[97];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED5[129];
	volatile uint32_t CONFIG[8];
} NRF_GPIOTE_REG;

void gpiote_init();

#endif
