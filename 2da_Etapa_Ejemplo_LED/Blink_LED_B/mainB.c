#include <MKL25Z4.H>
#include "Delay.h"
/*----------------------------------------------------------------------------
MAIN function
*----------------------------------------------------------------------------*/
int main (void) {
	SystemCoreClockUpdate(); /* Get Core Clock Frequency */
	SysTick_Config(SystemCoreClock/1000); /* Generate interrupt each 1 ms */
	SIM_SCGC5 = 0x1000; /* enable clock to Port D*/
	PORTD_PCR1 = 0x100; /* make PTD1 pin as GPIO */
	GPIOD_PDDR |= 0x002; /* make PTD1 as output pin */
	while (1) {
		GPIOD_PDOR &= ~0x002; /* turn on blue LED */
		Delay(500);
		GPIOD_PDOR |= 0x002; /* turn off blue LED */
		Delay(500);
	}
}