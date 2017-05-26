#include "hercules_N2HET.h"
/*
 * Struct to store the states and variables of the N2HET
 */
typedef struct {
	N2HET_type func;
}N2HET_data;

// Struct for N2HET1 
N2HET_data N2HET1_struct;
// Struct for N2HET2
N2HET_data N2HET2_struct;

/*
 * N2HET1 initialization. This can be initialized as GIO or as the high end
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
void N2HET1_init(N2HET_type func) {
	// If setting up as a timer
	if(func == N2HET_TIMER) {
		
	}
	// Other wise default to setting up as GIOs
	else {
		N2HET1_struct.func = N2HET_GIO; // Tell the struct that this peripheral is being used for GIO functionality
		HET1REG->GCR |= (1 << 0); // Enable the N2HET1 peripheral
	}
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
void N2HET1_dir_out(uint32_t dir) {
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
void N2HET1_dir_in(uint32_t dir) {
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
void N2HET1_dat_set(uint32_t dat) {
    HET1REG->DSET = dat;
    return;
}

/* Clears data output on the pins if they are configured as GIOs. If the pin is already
 * cleared, then it stays cleared.
 *
 * Input parameters
 *      dat - The pins to be cleared. Each bit represents a different pin.
 */
void N2HET1_dat_clr(uint32_t dat) {
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
void N2HET1_dat_tgl(uint32_t dat) {
    HET1REG->DOUT ^= dat;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
void N2HET2_init(N2HET_type func) {
    // If setting up as a timer
    if(func == N2HET_TIMER) {

    }
    // Other wise default to setting up as GIOs
    else {
        N2HET2_struct.func = N2HET_GIO; // Tell the struct that this peripheral is being used for GIO functionality
        HET2REG->GCR |= (1 << 0); // Enable the N2HET1 peripheral
    }
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
void N2HET2_dir_out(uint32_t dir) {
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
void N2HET2_dir_in(uint32_t dir) {
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
void N2HET2_dat_set(uint32_t dat) {
    HET2REG->DSET = dat;
    return;
}

/* Clears data output on the pins if they are configured as GIOs. If the pin is already
 * cleared, then it stays cleared.
 *
 * Input parameters
 *      dat - The pins to be cleared. Each bit represents a different pin.
 */
void N2HET2_dat_clr(uint32_t dat) {
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
void N2HET2_dat_tgl(uint32_t dat) {
    HET2REG->DOUT ^= dat;
}
