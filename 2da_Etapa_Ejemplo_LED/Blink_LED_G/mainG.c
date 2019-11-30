#include <MKL25Z4.H>
#include "Delay.h"
/*----------------------------------------------------------------------------
MAIN function
*----------------------------------------------------------------------------*/
int main (void) {
	SystemCoreClockUpdate(); /* Get Core Clock Frequency */
	SysTick_Config(SystemCoreClock/1000); /* Generate interrupt each 1 ms */
	SIM_SCGC5 = 0x400; /* enable clock to Port B and D*/
	PORTB_PCR19 = 0x100; /* make PTB19 pin as GPIO */
	GPIOB_PDDR |= 0x80000; /* make PTB19 and PTB18 as output pin */
	
	while (1) {
		GPIOB_PDOR &= ~0x80000; /* turn on green LED */
		Delay(500);
		GPIOB_PDOR |= 0x80000; /* turn off green LED */
		Delay(500);
	}
}