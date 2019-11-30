#include <MKL25Z4.H>
#include "Delay.h"
/*----------------------------------------------------------------------------
MAIN function
*----------------------------------------------------------------------------*/
int main (void) {
	SystemCoreClockUpdate(); /* Get Core Clock Frequency */
	SysTick_Config(SystemCoreClock/1000); /* Generate interrupt each 1 ms */
	SIM_SCGC5 = 0x400; /* enable clock to Port B and D*/
	PORTB_PCR18 = 0x100; /* make PTB18 pin as GPIO */
	GPIOB_PDDR |= 0x40000; /* make PTB18 as output pin */
	
	while (1) {
		GPIOB_PDOR &= ~0x40000; /* turn on red LED */
		Delay(500);
		GPIOB_PDOR |= 0x40000; /* turn off red LED */
		Delay(500);
	}
}