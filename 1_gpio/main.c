#include <stdint.h>

#define GPIO0 ((NRF_GPIO_REGS0*)0x50000000) //gpio 0 base adress
#define GPIO1 ((NRF_GPIO_REGS1*)0x50000300) //gpio 1 base adress
#define __BUTTON_A_PIN__ 14
#define __BUTTON_B_PIN__ 23
#define __RESERVED1_0_SIZE__ 118
#define __RESERVED1_1_SIZE__ 118


typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_0[__RESERVED1_0_SIZE__];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS0;

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_1[__RESERVED1_1_SIZE__];
	volatile uint32_t PIN_CNF[10];
} NRF_GPIO_REGS1;

int main(){

	GPIO0->PIN_CNF[21] = 0b1;
	GPIO0->PIN_CNF[22] = 0b1;
	GPIO0->PIN_CNF[15] = 0b1;
	GPIO0->PIN_CNF[24] = 0b1;
	GPIO0->PIN_CNF[19] = 0b1;

	GPIO0->PIN_CNF[28] = 0b1;
	GPIO0->PIN_CNF[11] = 0b1;
	GPIO0->PIN_CNF[31] = 0b1;
	GPIO1->PIN_CNF[5] = 0b1;
	GPIO0->PIN_CNF[30] = 0b1;

	GPIO0->PIN_CNF[__BUTTON_A_PIN__] = 0b1100;
	GPIO0->PIN_CNF[__BUTTON_B_PIN__] = 0b1100;


	int sleep = 0;
	while(1){


		if (!(GPIO0->IN & (1 <<__BUTTON_B_PIN__))) {
			GPIO0->OUTCLR = 1 <<28 | 1<<11 | 1<<31 | 1<<30;
			GPIO1->OUTCLR = 1 <<5;
			GPIO0->OUTSET = 1 << 21 | 1 << 22 | 1 << 15 | 1 << 24 | 1 << 19;
		}

		if (!(GPIO0->IN & (1 <<__BUTTON_A_PIN__))) {
			GPIO0->OUTSET = 1 <<28 | 1<<11 | 1<<31 | 1<<30;
			GPIO1->OUTSET = 1 <<5;
		}

		sleep = 10000;
		while(--sleep);
	}
	return 0;
}