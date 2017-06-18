#ifndef _HERCULES_RTI_H_
#define _HERCULES_RTI_H_

#include "type_def.h"
#include "reg_defs.h"
#include "VIM.h"

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
void rti0_init(uint32_t time, uint32_t vclk);

/**
 * Start the timer associated with counter 0 (not the same as compare 0)
 *
 * No input parameters
 *
 * No output parameters
 */
void rti_cnt0_start(void);

/**
 * Changes the time that the timer runs for on compare 0.
 *
 * Input parameters
 *		time - The amount of time befor the timer expires
 *
 * No output parameters
 */
void rti0_set_time(uint32_t time);

/**
 * Enables the interrupts for compare 0. See the technical reference manual to see what
 * interrupt flags (types) are available.
 *
 * No input parameters
 *
 * No output parameters
 */
void rti0_int_ena(void);

/**
 * Disables interrupts for compare 0.
 *
 * No input parameters
 *
 * No output parameters 
 */
void rti0_int_dis(void);

/**
 * Sets the user interrupt function for when an interrupt is triggered.
 *
 * Input parameters
 *		func - Pointer to the function to use for interrupts
 */
void rti0_int_func(callback func);

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
uint32_t rti0_comp_time(void);
 
 
#endif

