/**
 * This file is an I2C driver for the Hercules safety microcontroller. It is specifically written for the
 * RM57Lx processor.
 *
 * This module assumes that there are at least two data transmissions per call. The first sets the source/
 * destination register. The second (or more) bytes are the read or write data. For reads, there (usually)
 * needs to be a short delay between the stop and start events when sending the source register address
 * and reading the data in. To solve this, a short delay of an empty while loop is added in (a count up to
 * 10 or so). For writes, there doesn't need to be a delay between the destination register and the data.
 *
 * For now, there are two options that can be used. The first (default) option is to use "wait states" when
 * doing a transmission. This means that the processor will wait until a transfer is complete before moving
 * on. This takes much longer to execute, but it's more simple and more "linear" (the next instruction will
 * execute after the transmission).
 *
 * The second option is to use interrupts. This works by enabling the interrupts, then when a flag is received,
 * a the state is examined (read, send, slave register, idle, ect...) and then the next byte is sent/read in.
 * If interrupts have been enabled, then they will be used instead of using empty loops to wait for data
 * transmission.
 *
 * NOTE: If using the module, be sure there is sufficient time between transfers. When testing with an MPU 9250
 * IMU, there were issues if transmissions happened too quickly, especially when doing a read after a write. One
 * solution may be to use the Real Time Interrupt (RTI) peripheral to set up a delay between sends. Will try to
 * solve this later so it's handled by this module.
 */

#ifndef _I2C_H_
#define _I2C_H_
 
#include "reg_defs.h"
#include "VIM.h"
#include "type_def.h"

/*
 * Enumeration to define the current state of the I2C transfer when doing interrupt
 * enabled transfers
 */
typedef enum {
    I2C_idle, // I2C isn't doing anything
    I2C_slave_reg, // Sending the destination/source register
    I2C_read, // Reading from the device
    I2C_write // Writing to the device
} I2C_state;

/*
 * Initializes the I2C1 module.
 *
 * Note, on the frequency setup. The frequency doesn't seem to exaclty match up with
 * the desired frequency. This is partly because dividing down the frequencies (done
 * twice when creating the peripheral clock and when creating the actual serial bus).
 * gives a non-whole number, leading to some error. This is +/- a few kHz when running in
 * the >100kHz range. There also seems to be a bit of variation from one clock cycle to
 * the next. No idea why this is. May be due to the logic analyzet that was used for
 * debugging.
 *
 * Input parameters
 *		freq - The frequency of the clock. Also called the baudrate.
 *		addr_bits - Number of address bits. If this is greater than 8, it 
 *			defaults to 10 bits, otherwise it defaults to 8 bits.
 *		num_bits - Number of data bits sent or received
 *
 *	No output parameters
 *
 */
void I2C1_init(uint32_t freq, uint8_t addr_bits, uint16_t num_bits);

/*
 * Enables interrupt capability for the I2C1 module. This will perform an interrupt whenever
 * the I2C1 module needs to be serviced. Because I2C is (relatively) slow, the time waiting
 * to send or receive data can be slow. To allow the processor to do other functions in the
 * mean time, interrupts are used to indicate when data needs to be sent or read in.
 *
 * No input parameters
 *
 * No output parameters
 */
void I2C1_int_enable(void);

/*
 * Disables interrupts for the I2C1 module
 *
 * No input parameters
 *
 * No output parameters
 */
void I2C1_int_disable(void);

/*
 * Checks whether or not an I2C1 transfer is occuring. This is done so that if interrupts/DMA are
 * enabled, there are no conflicts between I2C1 transfers. If nothing (0) is returned, there is
 * no I2C1 transfer. If the return is not null (>1), then there is a transfer in progress.
 * Basically just returns whether or not the bus is busy. Nothing fancy and may not be terribly
 * accurate.
 *
 * No input parameters
 *
 * Output parameters
 *      Whether or not an I2C1 transfer is occurring.
 */
uint8_t I2C1_state(void);

/*
 * Reads data from a device.
 *
 * Input parameters
 *		slave_addr - The address of the slave that is being read from
 *		source_reg - The address of the register in the slave that is being read
 *		num_bytes - The number of bytes that are being read in
 *		data[] - The pointer to the data address
 *
 * Output parameters
 *		The data that gets read in from the slave device
 */
void I2C1_read(uint8_t slave_addr, uint16_t source_reg, uint16_t num_bytes, uint8_t data[]);

/*
 * Writes data to a device
 *
 * Input parameters
 *      slave_addr - The address of the slave that is being written to
 *      dest_reg - The initial register that is being written to. This assumes some sort of address increment support in the slave
 *      num_bytes - The number of bytes that are being written to the slave device
 *      *data - The pointer to the first byte of data's address
 *
 * No output parameters
 */
void I2C1_write(uint8_t slave_addr, uint16_t dest_reg, uint16_t num_bytes, uint8_t data[]);

/**
 * TODO
 *  Add DMA support
 *  Add a buffer for when interrupt/DMA is enabled
 */

#endif


