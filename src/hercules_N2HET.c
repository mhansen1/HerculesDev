#include "hercules_N2HET.h"
#include "n2het_prgm.h"

/*
 * N2HET1 initialization. This can be initialized as GIO or as the high end
 * timer functionality.
 *
 * Input parameters
 *      func - Says if the peripheral will use the program RAM or if it will just be used for GIO
 *
 * No output parameters
 */
void n2het1_init(N2HET_type func) {
	// If setting up as a timer/program
	if(func == N2HET_PRGM) {
		HET1REG->GCR |= ((1 << 24) | // Turn on the pins 
		                 (1 << 17) | // Ignore suspen (TODO: See if this is needed or not...)
						 (1 << 16)); // Set to master mode (TODO: See if the is needed or not...)
		// Put the program into memory
		memcpy((void *)&het1_program_load, (const void *)het1_instructions, sizeof(het1_instructions));
	}
	// If not using the program memory, nothing special needs to be done.
	
	HET1REG->GCR |= (1 << 0); // Enable the N2HET1 peripheral
	return;
}

/*
 * Sets the direction of the N2HET1 pins to output when it is configured as GIO.
 *
 * Input parameters
 *		dir - The pins to set to output. Each bit represents a pin. For example,
 *		    a value of 0x00000101 will set pins 0 and 8 to outputs.
 *
 * No output parameters
 */
void n2het1_dir_out(uint32_t dir) {
	HET1REG->DIR |= dir;
	return;	
}

/*
 * Sets the direction of the N2HET1 pins to inputs when it's configured as GIO.
 *
 * Input parameters
 *      dir - The pins that are being set to inputs. Each bit represents a pin. For example,
 *          a value of 0x00010006 will set pins 1, 2, and 16 to inputs
 */
void n2het1_dir_in(uint32_t dir) {
    HET1REG->DIR &= ~(dir);
    return;
}

/*
 * Sets the data output on the pins to high if they are configured as GIOs. If the pin is
 * already set, then it will remain set.
 *
 * Input parameters
 *      dat - The pins that are having their output set to high. Each bit represents a
 *          different pin.
 *
 * No output parameters
 */
void n2het1_dat_set(uint32_t dat) {
    HET1REG->DSET = dat;
    return;
}

/* Clears data output on the pins if they are configured as GIOs. If the pin is already
 * cleared, then it stays cleared.
 *
 * Input parameters
 *      dat - The pins to be cleared. Each bit represents a different pin.
 */
void n2het1_dat_clr(uint32_t dat) {
    HET1REG->DCLR = dat;
    return;
}

/*
 * Toggles the data on the pins when they are configured as GIOs. If the pin is set to high, it will
 * go low. If it is low, it will go high
 *
 * Input parameters
 *      dat - The pins to be toggled. Each bit represents a different pin.
 *
 * No input parameters
 */
void n2het1_dat_tgl(uint32_t dat) {
    HET1REG->DOUT ^= dat;
	return;
}

/*
 * Sets the high resolution clock of the N2HET1 module. This is the clock that drives the N2HET module
 * instruction execution. This is derived from VCLK2. See table 23-5 of the technical reference manual
 * for more info on the divisor
 *
 * Input parameters
 *		div - VCLK2 divisor
 *
 * No output parameters
 */
void n2het1_hr_set(uint8_t div) {
	HET1REG->PFR |= (div & 0x3F); // Mask out to make sure that no bits are accidently set in the LR settings
	return;
}

/*
 * Sets the low resolution prescalar. This is the loop resolution of the N2HET program. This determines the maximum
 * amount of time the program can run before restarting. This is derived from VCLK2. See table 23-5 of the technical
 * reference manual for more info on the divisor.
 *
 * Input parameters 
 *		div - VCLK2 divisor 
 *
 * No output parameters 
 */
void n2het1_lr_set(uint8_t div) {
	HET1REG->PFR |= (div << 8);
	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * N2HET2 initialization. This can be initialized as GIO or as the high end
 * timer functionality.
 *
 * Input parameters
 *      func - The type of functionality that the peripheral will have, N2HET or GIO
 *
 * No output parameters
 */
/**
 * TODO
 *  Setup the high end timer initializations
 */
void n2het2_init(N2HET_type func) {
    // If setting up as a timer/program
    if(func == N2HET_PRGM) {
		HET2REG->GCR |= ((1 << 24) | // Turn on the pins 
		                 (1 << 17) | // Ignore suspen (TODO: See if this is needed or not...)
						 (1 << 16)); // Set to master mode (TODO: See if the is needed or not...)
        // Put the program into memory
        memcpy((void *)&het2_program_load, (const void *)het2_instructions, sizeof(het2_instructions));
    }
    // If not using the program memory, nothing special needs to be done.

    HET2REG->GCR |= (1 << 0); // Enable the N2HET1 peripheral
    return;
}

/*
 * Sets the direction of the N2HET1 pins to output when it is configured as GIO.
 *
 * Input parameters
 *      dir - The pins to set to output. Each bit represents a pin. For example,
 *          a value of 0x00000101 will set pins 0 and 8 to outputs.
 *
 * No output parameters
 */
void n2het2_dir_out(uint32_t dir) {
    HET2REG->DIR |= dir;
    return;
}

/*
 * Sets the direction of the N2HET1 pins to inputs when it's configured as GIO.
 *
 * Input parameters
 *      dir - The pins that are being set to inputs. Each bit represents a pin. For example,
 *          a value of 0x00010006 will set pins 1, 2, and 16 to inputs
 */
void n2het2_dir_in(uint32_t dir) {
    HET2REG->DIR &= ~(dir);
    return;
}

/*
 * Sets the data output on the pins to high if they are configured as GIOs. If the pin is
 * already set, then it will remain set.
 *
 * Input parameters
 *      dat - The pins that are having their output set to high. Each bit represents a
 *          different pin.
 *
 * No output parameters
 */
void n2het2_dat_set(uint32_t dat) {
    HET2REG->DSET = dat;
    return;
}

/* Clears data output on the pins if they are configured as GIOs. If the pin is already
 * cleared, then it stays cleared.
 *
 * Input parameters
 *      dat - The pins to be cleared. Each bit represents a different pin.
 */
void n2het2_dat_clr(uint32_t dat) {
    HET2REG->DCLR = dat;
    return;
}

/*
 * Toggles the data on the pins when they are configured as GIOs. If the pin is set to high, it will
 * go low. If it is low, it will go high
 *
 * Input parameters
 *      dat - The pins to be toggled. Each bit represents a different pin.
 *
 * No input parameters
 */
void n2het2_dat_tgl(uint32_t dat) {
    HET2REG->DOUT ^= dat;
}

/*
 * Sets the high resolution clock of the N2HET2 module. This is the clock that drives the N2HET module
 * instruction execution. This is derived from VCLK2. See table 23-5 of the technical reference manual
 * for more info on the divisor
 *
 * Input parameters
 *		div - VCLK2 divisor
 *
 * No output parameters
 */
void n2het2_hr_set(uint8_t div) {
	HET2REG->PFR = (div & 0x3F) | (HET2REG->PFR & 0xFFFFFFC0); // Mask out to make sure that no bits are accidently set in the LR settings
	return;
}

/*
 * Sets the low resolution prescalar. This is the loop resolution of the N2HET program. This determines the maximum
 * amount of time the program can run before restarting. This is derived from VCLK2. See table 23-5 of the technical
 * reference manual for more info on the divisor.
 *
 * Input parameters 
 *		div - VCLK2 divisor 
 *
 * No output parameters 
 */
void n2het2_lr_set(uint8_t div) {
	HET2REG->PFR = (div << 8) | (HET2REG->PFR & 0xFFFFF8FF);
	return;
}



