#ifndef _RTI_EXAMPLE_H_
#define _RTI_EXAMPLE_H_

//#include "hercules_rti.h"
#include "reg_defs.h"

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
void rti0_toggle_example(uint32_t vclk, uint32_t time);


#endif

