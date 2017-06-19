#include "rti_example.h"

void toggleISR(void);

/**
 * Creates a timer that will toggle GIOA[0] pin high and
 * low whenever compare 0 timer interrupt is triggered. User
 * passes the peripheral clock (VCLK) frequency and the 
 * desired compare time.
 *
 * Input parameters
 *		vclk - The peripheral clock frequency in megaherz
 *		time - Time until the interrupt is triggered, in microseconds
 */
void rti0_toggle_example(uint32_t vclk, uint32_t time) {
	GIOCNTL->GCR0 = 1; // Make sure the GIO peripheral is brought out of reset
	GIOA->DIR |= 0x00000001; // Set the direction on pin 0 to out
	GIOA->DCLR = 0x00000001; // Make sure the output is cleared.
	
	rti0_init(time, vclk); // Initialize the timer. Note that the timer will not start yet
	rti0_int_ena(); // Enable the interrupts
	rti0_int_func(&toggleISR); // Set the interrupt function.
	rti_cnt0_start(); // Start the counter (starts the timer
	
	return;
}

/**
 * Interrupt function that is executed whenever the time compare
 * triggers an interrupt.
 */
void toggleISR(void) {
	GIOA->DOUT ^= 0x00000001;
	return;
}

