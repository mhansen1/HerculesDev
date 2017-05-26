/*
 * This file is the driver to control the Second Generation High End Timer (N2HET) on the Hercules microcontroller,
 * specifically the RM57Lx processor.
 *
 * NOTE: As of right now, all this does is control the N2HET registers as Generial Input/Outputs (GIOs).
 */

#ifndef _N2HET_H_
#define _N2HET_H_

#include "reg_defs.h"

/*
 * Enumeration to define if using the peripheral as a general purpose I/O or
 * using for 
 */ 
typedef enum {
	N2HET_GIO, // The N2HET peripheral is being used as a GIO 
	N2HET_TIMER // The N2HET perihperal is being used as a high end timer
} N2HET_type;

/*
 * N2HET1 initialization. This can be initialized as GIO or as the high end
 * timer functionality.
 *
 * Input parameters
 *		func - The type of functionality that the peripheral will have, N2HET or GIO
 *
 * No output parameters
 */
/**
 * TODO
 *	Setup the high end timer initializations
 */
void N2HET1_init(N2HET_type func);

/*
 * Sets the direction of the N2HET1 pins to output when it is configured as GIO.
 *
 * Input parameters
 *      dir - The pins to set to output. Each bit represents a pin. For example,
 *          a value of 0x00000101 will set pins 0 and 8 to outputs.
 *
 * No output parameters
 */
void N2HET1_dir_out(uint32_t dir);

/*
 * Sets the direction of the N2HET1 pins to inputs when it's configured as GIO.
 *
 * Input parameters
 *      dir - The pins that are being set to inputs. Each bit represents a pin. For example,
 *          a value of 0x00010006 will set pins 1, 2, and 16 to inputs
 */
void N2HET1_dir_in(uint32_t dir);

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
void N2HET1_dat_set(uint32_t dat);

/* Clears data output on the pins if they are configured as GIOs. If the pin is already
 * cleared, then it stays cleared.
 *
 * Input parameters
 *      dat - The pins to be cleared. Each bit represents a different pin.
 *
 * No output parameters
 */
void N2HET1_dat_clr(uint32_t dat);

/*
 * Toggles the data on the pins when they are configured as GIOs. If the pin is set to high, it will
 * go low. If it is low, it will go high
 *
 * Input parameters
 *      dat - The pins to be toggled. Each bit represents a different pin.
 *
 * No input parameters
 */
void N2HET1_dat_tgl(uint32_t dat);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
void N2HET2_init(N2HET_type func);

/*
 * Sets the direction of the N2HET1 pins to output when it is configured as GIO.
 *
 * Input parameters
 *      dir - The pins to set to output. Each bit represents a pin. For example,
 *          a value of 0x00000101 will set pins 0 and 8 to outputs.
 *
 * No output parameters
 */
void N2HET2_dir_out(uint32_t dir);

/*
 * Sets the direction of the N2HET1 pins to inputs when it's configured as GIO.
 *
 * Input parameters
 *      dir - The pins that are being set to inputs. Each bit represents a pin. For example,
 *          a value of 0x00010006 will set pins 1, 2, and 16 to inputs
 */
void N2HET2_dir_in(uint32_t dir);

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
void N2HET2_dat_set(uint32_t dat);

/* Clears data output on the pins if they are configured as GIOs. If the pin is already
 * cleared, then it stays cleared.
 *
 * Input parameters
 *      dat - The pins to be cleared. Each bit represents a different pin.
 *
 * No output parameters
 */
void N2HET2_dat_clr(uint32_t dat);

/*
 * Toggles the data on the pins when they are configured as GIOs. If the pin is set to high, it will
 * go low. If it is low, it will go high
 *
 * Input parameters
 *      dat - The pins to be toggled. Each bit represents a different pin.
 *
 * No input parameters
 */
void N2HET2_dat_tgl(uint32_t dat);


/**
 * TODO
 *  Setup the actual high end timers
 *  Try setting it up where the user passes which N2HET is being used to cut down on function count (I think I know how to do this, just need to look into it a bit...)
 *  Add other GIO functionality support (pull resistors, open-drain, etc...)
 */


#endif 
