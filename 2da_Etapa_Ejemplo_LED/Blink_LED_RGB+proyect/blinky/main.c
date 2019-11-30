#include <MKL25Z4.H>
#include "Delay.h"
/*----------------------------------------------------------------------------
MAIN function
*----------------------------------------------------------------------------*/
int main (void) {
	SystemCoreClockUpdate(); /* Get Core Clock Frequency */
	SysTick_Config(SystemCoreClock/1000); /* Generate interrupt each 1 ms */
	SIM_SCGC5 = 0x1400; /* enable clock to Port B and D*/
	PORTB_PCR18 = 0x100; /* make PTB18 pin as GPIO */
	PORTB_PCR19 = 0x100; /* make PTB19 pin as GPIO */
	PORTD_PCR1 = 0x100; /* make PTD1 pin as GPIO */
	GPIOB_PDDR |= 0xC0000; /* make PTB19 and PTB18 as output pin */
	GPIOD_PDDR |= 0x002; /* make PTD1 as output pin */
	
	while (1) {
		GPIOB_PDOR &= ~0x40000; /* turn on red LED */
		Delay(500);
		GPIOB_PDOR |= 0x40000; /* turn off red LED */
		Delay(500);
		GPIOB_PDOR &= ~0x80000; /* turn on green LED */
		Delay(500);
		GPIOB_PDOR |= 0x80000; /* turn off green LED */
		Delay(500);
		GPIOD_PDOR &= ~0x002; /* turn on blue LED */
		Delay(500);
		GPIOD_PDOR |= 0x002; /* turn off blue LED */
		Delay(500);
	}
}