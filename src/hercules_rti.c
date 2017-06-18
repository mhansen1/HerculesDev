#include "hercules_rti.h"
#include <stdio.h>

/**
 * TODO
 *  Add in other compare functions (Compare 1, 2, and 3)
 */

// Struct to hold the data about the RTI
typedef struct {
    uint32_t comp__time;   // Amount of time before the timer expires.
    callback rti0_int_func; // Interrupt function performed on a compare 0 interrupt.
}RTI_data;

volatile RTI_data rti0_data;

#pragma CODE_STATE(rti0_IRQ, 32)
#pragma INTERRUPT(rti0_IRQ, IRQ)
/**
 * Interrupt function for IRQ interrupts. 
 */
/**
 * TODO
 *	Accomadate other interrupt events
 */
void rti0_IRQ(void) {
	// Clear the interrupt flag for compare match
	RTIREG->INTFLAG = 1;
	// Call the interrupt 
	(*(rti0_data.rti0_int_func))();
}

/**
 * Dummy function for if the interrupt has not been set yet. This is to avoid possible issues
 * with calling a function that does not exist and accidently calling the abort interrupt.
 */
void dummy_func(void) {
	return;
}

/**
 * Initializes the RTI. By default this will disabled the interrupt by default.
 * This function takes in the counter time in microseconds. This function interacts
 * with compare 0. 
 *
 * Input parameters
 *		time - The amount of time before the timer expires, in microseconds.
 *		vclk - The speed of VCLK in MHz. Used for setting the up counter
 *
 * No output parameters
 */
/**
 * TODO
 *	Add in something to extend the timer length past 4.3ks (1us*2^32)
 */
void rti0_init(uint32_t time, uint32_t vclk) {
	RTIREG->TBCTRL = 0x00000000; // Default to the internal RTI clk (derived from VCLK).
	RTIREG->UC0 = 0x00000000; // Reset the counters to zero
	RTIREG->FRC0 = 0x00000000;
	RTIREG->CPUC0 = vclk; // Divide RTI clk (or VCLK) down to a 1us period.
	//RTIREG->CMP[0].COMP = 0; // Set COMP0. Doesn't seem to be needed. Doesn't seem to change the output
	RTIREG->CMP[0].UDCP = time; // Set the time in microseconds
	rti0_data.comp__time = time; // Store the set data.
	return;
}

/**
 * Start the timer associated with counter 0 (not the same as compare 0)
 *
 * No input parameters
 *
 * No output parameters
 */
void rti_cnt0_start(void) {
    RTIREG->GCTRL |= (1 << 0);
    return;
}

/**
 * Changes the time that the timer runs for on compare 0.
 *
 * Input parameters
 *		time - The amount of time befor the timer expires
 *
 * No output parameters
 */
void rti0_set_time(uint32_t time) {
	RTIREG->CMP[0].UDCP = time;
	return;
}

/**
 * Enables the interrupts for compare 0. See the technical reference manual to see what
 * interrupt flags (types) are available. Defaults to IRQ interrupts
 *
 * No input parameters
 *
 * No output parameters
 */
void rti0_int_ena(void) {
	RTIREG->INTFLAG |= 1; // Make sure that the interrupt flag is cleared
	RTIREG->SETINTENA |= 1; // Enable the compare interrupt in the peripheral.
	VIMCNTL->REQENASET[0] |= 1; // Enable the interrupt in the VIM.
	if(rti0_int_func == NULL) // If the interrupt function hasn't been set, set to dummy function
	    rti0_data.rti0_int_func = dummy_func;
	vimRAM->ISR[3] = &rti0_IRQ; // Attach the actual RTI0 to the interrupt vector.
	_enable_IRQ(); // Enable interrupts in the ARM processor
}

/**
 * Disables interrupts for compare 0.
 *
 * No input parameters
 *
 * No output parameters 
 */
void rti0_int_dis(void) {
	RTIREG->CLEARINTENA |= 1; // Clear the interrupt enable in the peripheral 
	VIMCNTL->REQENACLR[0] |= 1; // Clear the interrupt enable in the VIM
	return;
}

/**
 * Sets the user interrupt function for when an interrupt is triggered.
 *
 * Input parameters
 *		func - Pointer to the function to use for interrupts
 *
 * No output parameters
 */
void rti0_int_func(callback func) {
    rti0_data.rti0_int_func = func;
	return;
}

/**
 * Returns the timer length that has been set in microseconds for the compare
 * 0.
 *
 * No input parameters
 *
 * Output parameters
 *      uint32_t - Time that the timer will run to (compare value) before
 *          the timer expires and triggers and interrupt (if enabled)
 */
uint32_t rti0_comp_time(void) {
    return rti0_data.comp__time;
}











