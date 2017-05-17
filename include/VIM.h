/**
 * SETUP INTERRUPT CAPABILITY
 */

#ifndef _VIM_H_
#define _VIM_H_

#include "type_def.h"

// Define the struct for the VIM ISR functions in RAM.
typedef volatile struct vimRam {
	callback ISR[128U];
} vimRAM_t;
// Set up the starting address of the VIM RAM
#define vimRAM ((vimRAM_t *)0xFFF82000U)

#endif
