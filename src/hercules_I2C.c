#include "hercules_I2C.h"
#include "type_def.h"
/**
 * TODO
 *  Replace the pin multiplexer definitions in the reg_defs file
 */
#include "HL_reg_pinmux.h"

/*
 * Struct to hold data and the state of the I2C modules
 */
typedef struct {
    uint8_t num_bytes; // Number of bytes to be sent or read
    uint8_t dest_reg; // Destination register during a write
    uint8_t source_reg; // The register being read from.
    uint8_t byte_count; // Current nubmer of bytes sent/received
    uint8_t rd_wrt; // Says whether a transmission is a read or a write
                    // If 0, reading, if 1, writing
    bool_t int_ena; // Boolean to say whether interrupt transfers are enabled
    uint8_t state; // Says the current state of the transmission when interrupts are enabled
    uint8_t *data; // Pointer to store data during an interrupt driven reception
    bool_t test;
} I2C_data;

/*
 * Initialize local variables
 */
I2C_data I2C1_struct; // Data struct for I2C1

/*
 * Interrupt function for I2C1. This handles sending and storing data since I2C is slow
 * compared to the processor clock speeds.
 *
 * No input parameters
 *
 * No output parameters
 */
/**
 * TODO
 *  Add FIQ for higher priority and faster interrupt handling
 */
/**
 * TODO
 *  Look into adding IRQ/FIQ priorities. This would apply to the res of interrupts on the microcontroller, as well.
 */
/**
 * TODO
 *  The states in the struct may not be needed. Can probably leverage the status register bits (was doing that originally, but it wasn't working too well)
 */
uint8_t sent;
#pragma CODE_STATE(I2C1_ISR,32)
#pragma INTERRUPT(I2C1_ISR,IRQ);
void I2C1_ISR(void) {
    // Store the interrupt flag for comparison
    uint16_t flags;
    flags = I2C1->IVR;
    if((I2C1_struct.state == I2C_slave_reg)) { // If the destination/source register was just sent...
        I2C1->STR |= (1 << 5) | (1 << 4); // Clear the stop flag
        // Set to master mode, set stop condition, set start condition
        //I2C1->MDR |= (1 << 10) | (1 << 11) | (1 << 13);
        if(I2C1_struct.rd_wrt) { // If writing set the state to say that a read is now occurring
            I2C1_struct.state = I2C_write;
            I2C1->MDR |= (1 << 9) | (1 << 5); // Set to reception mode
			I2C1->DXR = I2C1_struct.data[0]; // Send the first byte
			I2C1_struct.byte_count++; // Increments the byte count since one was sent
			//I2C1->MDR |= (1 << 10) | (1 << 11) | (1 << 13);
        }
        else { // If reading, set the state appropriately.
            uint32_t i; // Insert small delay between the stop and start events
            for(i=0;i<50;i++) { } // If no delay, then in testing with an MPU-9250 IMU, the bus locks up. A delay of 1 works fine, though. And this time will probably be negligable as it should only take a few cycles to exe
            I2C1->CNT = I2C1_struct.num_bytes; // Set the number of bytes being sent
            I2C1_struct.state = I2C_read;
            I2C1->MDR &= ~(1 << 9); // Make sure in transmit mode
            I2C1->MDR |= (1 << 10) | (1 << 11) | (1 << 13);
        }
    }
    else if((I2C1_struct.state == I2C_read)) { // If data was received
        I2C1->STR |= (1 << 3); // Clear the interrupt flag
        I2C1_struct.data[I2C1_struct.byte_count] = I2C1->DRR; // Read and store the data
        I2C1_struct.byte_count++; // Increment the byte count
        if(I2C1_struct.byte_count == I2C1_struct.num_bytes)
            I2C1_struct.state = I2C_idle;
    }
    else if((I2C1_struct.state == I2C_write)) { // If data is done writing, send more if needed
        I2C1->STR |= (1 << 4); // Clear the interrupt flag
		I2C1->DXR = I2C1_struct.data[I2C1_struct.byte_count]; // Send more data if needed
		I2C1_struct.byte_count++; // Increment the number of bytes sent so far
		if(I2C1_struct.byte_count == I2C1_struct.num_bytes)
            I2C1_struct.state = I2C_idle;
    }
    else {
    //    I2C1_struct.state = I2C_idle;
        I2C1->STR = 0xFF;
        I2C1->MDR |= (1 << 11); // Set the stop bit
    }
    return;
}

/*
 * Initializes the I2C1 module.
 *
 * Input parameters
 *		freq - The frequency of the clock. Also called the baud rate.
 *		addr_bits - Number of address bits. If this is greater than 8, it 
 *			defaults to 10 bits, otherwise it defaults to 8 bits.
 *		num_bits - Number of data bits sent or received
 *
 *	No output parameters
 */
/**
 * TODO
 *	Setup 10-bit addressing
 */
/**
 * TODO
 *  Try to fix the the frequency setting and make it more accurate.
 */
/*
 * TODO
 *  Might clamp the freqeuncy, in case the user sets it too high or too low
 */
void I2C1_init(uint32_t freq, uint8_t addr_bits, uint16_t num_bits) {
    sent = 0;
    // Enable changing of mux outputs
    PINMUXREG->KICKER0 = 0x83E70B13U;
    PINMUXREG->KICKER1 = 0x95A4F1E0U;
    // CHANGE PINS FOR I2C1 FUNCTIONALITY
    // Change the output on ball B2
    PINMUXREG->PINMUXO[23] &= ~(1 << 8); // Clear the default function of the pin
    PINMUXREG->PINMUXO[23] |= (1 << 9);  // Set the function to be I2C1_SDA
    // Change the output on ball C3
    PINMUXREG->PINMUXO[23] &= ~(1 << 16); // Clear the default function of the pin
    PINMUXREG->PINMUXO[23] |= (1 << 17); // Set the function to be I2C1_SCL
    // Lock the pin mux again.
    PINMUXREG->KICKER0 = (uint32_t)0;
    PINMUXREG->KICKER1 = (uint32_t)0;

	// Make sure the I2C is in reset so its settings can be changed
	I2C1->MDR &= ~(1 << 5);
	
	// Set to master mode
	I2C1->MDR |= (1 << 10);
	// Make sure that the stop conditions is set
	I2C1->MDR |= (1 << 11);
	// Set the number of bits to be sent
	if(num_bits > 1) // 0x0 means 8 bits, and 0x1 is reserved
		I2C1->MDR |= num_bits & 0x00000007; // Mask out everything but the three bits
	else // Else, default to 8 bits
		I2C1->MDR &= ~(0x00000007);
	
	// Turn off compatilibility mode 
	I2C1->EMDR = 3;
	
	// Disable DMA
	I2C1->DMACR = 0;
	
	// Set I2C data count
	I2C1->CNT = 1;
	
	// Setup the prescale for the module frequency (not the tranmission frequency)
	// Module clock = VCLK/(PSC+1)
	// Needs to be between 6.7MHz and 13.2MHz
	// Choose a middle ground of 12.5MHz for a middle ground
	// PSC = (VCLK/module clock)-1
	// A PSC of 5 gives 9.375MHz
	I2C1->PSC = 5;
	
	// Setup up the I2C data clock. This is dependent on the value used in the PSC register
	// Use float types for better accuracy
	// value = f_module/(2*f_i2c) - d
	float clk = 12500000 / (2 * freq) - 5;
	// Set the value 
	I2C1->CKH = (uint16_t)clk;
	I2C1->CKL = (uint16_t)clk;
	// Make sure the peripheral is in I2C mode
	I2C1->PFNC = 0;
	// Make sure that open drain is enabled
	//I2C1->PDR = 3;
	// Make sure that the pull up resistor is enabled
	I2C1->PDIS = 0;
	I2C1->PSEL = 3;
	// Bring out of reset
	I2C1->MDR |= (1 << 5);
	
	// Set the values of the struct
	I2C1_struct.num_bytes = 1;
	I2C1_struct.dest_reg = 0;
	I2C1_struct.source_reg = 0;
	I2C1_struct.rd_wrt = 0;
	I2C1_struct.int_ena = F;
	I2C1_struct.state = I2C_idle;
	I2C1_struct.test = F;

	return;
}

/*
 * Enables interrupt capability for the I2C1 module. This will perform an interrupt whenever
 * the I2C1 module needs to be serviced. Because I2C is (relatively) slow, the time waiting
 * to send or receive data can be slow. To allow the processor to do other functions in the
 * mean time, interrupts are used to indicate when data needs to be sent or read in.
 *
 * NOTE: Before calling this function, make sure there is no data already being transmitted.
 * This is done using the I2C1_in_prog() function
 *
 * No input parameters
 *
 * No output parameters
 */
void I2C1_int_enable(void) {
    vimRAM->ISR[67] = &I2C1_ISR; // Set the function to service during an interrupt
    VIMCNTL->REQENASET[2] |= (1 << 2); // Enable the interrupt in the VIM
    I2C1->IMR |= (1 << 6) | // Enable the interrupt for a stop being detected
                 (1 << 5) | // Enable the interrupt for a transmitter empty
                 (1 << 4) | // Register access ready
                 (1 << 3); // Enable the interrupt for a receive full
    I2C1_struct.int_ena = T; // Set enable flag in the struct
    _enable_IRQ(); // Enable IRQs in the CPU
    return;
}

/*
 * Disables interrupts for the I2C1 module
 *
 * No input parameters
 *
 * No output parameters
 */
void I2C1_int_disable(void){
    VIMCNTL->REQENACLR[2] |= (1 << 2); // Disable I2C in the VIM
    I2C1->IMR &= ~(1 << 5) | // Disable the stop interrupt
                 ~(1 << 4) | // Disable the transmitter empty interrupt
                 ~(1 << 3); // Disable the receive fule interrupt
    I2C1_struct.int_ena = F; // De-set the enable flag in the struct
    return;
}

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
 *      Whether or not an I2C1 transfer is occuring.
 */
uint8_t I2C1_state(void) {
    return (uint8_t)(I2C1_struct.state);
}
/*
 * Reads data from a device. Sends the slave address, the source register, then waits for a bit
 * before sending the slave address again and then reading the data. The delay is in place because
 * there will probably be a "dead time" between a start and stop required.
 *
 * Input parameters
 *		slave_addr - The address of the slave that is being read from
 *		source_reg - The address of the register in the slave that is being read
 *		num_bytes - The number of bytes that are being read in
 *      data - The pointer to the data address
 *
 * Output parameters
 *		The data that gets read in from the slave device
 */
/**
 * TODO
 *	Setup 10-bit addressing support
 */
/**
 * TODO
 *  See if the "for" loop can be eliminated. May be missing a piece of info that lets it not be used.
 */
void I2C1_read(uint8_t slave_addr, uint16_t source_reg, uint16_t num_bytes, uint8_t data[]) {

    I2C1->SAR = slave_addr; // Set the slave address
    I2C1->CNT = 1; // Set the bytes to be sent/read to one, since source register is being sent.
    I2C1->MDR |= (1 << 10) | // Make sure in master mode
                 (1 << 9)  | // Set the direction to transmit to send the register address
                 (1 << 11); // Set the stop condition
    if(I2C1_struct.int_ena) { // If interrupts are enabled, just start sending the source register
        // Don't wait until  the transmit register is empty. This will hopefully address potential issues
        // when the buffer is added.
        I2C1_struct.data = data; // Store the pointer to the data
        I2C1_struct.byte_count = 0; // Reset the byte counter
        I2C1->MDR |= (1 << 13); // Set start condition
        I2C1->DXR = source_reg; // Set the source register
        I2C1_struct.state = I2C_slave_reg; // Tell the state machine that the source register is being sent.
        I2C1_struct.rd_wrt = 0; // Tell the state machine that a read will be done
        I2C1_struct.num_bytes = num_bytes; // Set the number of bytes being read/written
    }
    else { // If interrupts aren't enabled
        while(!(I2C1->STR & (1 << 4))) { } // Wait to make sure that there's no data in the transmit register from a previously called transfer
        I2C1->MDR |= (1 << 13); // Set start condition
        I2C1->DXR = source_reg; // Put data into the data transmit register (source register and a write flag)
        // Doesn't seem to be needed. Removed for now.
        //while(I2C1->STR & (1 << 12)) { } // Wait until the bus isn't busy (BB bit in STR register)
        while(!(I2C1->STR & (1 << 5))) { } // Wait until a stop is detected
        uint16_t i;
        for(i=0;i<100;i++) { } // Needed as a delay between a stop and start condition. Needed for some peripheral devices
        I2C1->CNT = num_bytes; // Set the CNT register
        I2C1->MDR &= ~(1 << 9); // Set the direction as receiver
        I2C1->MDR |= (1 << 10) | // Set to master mode
                     (1 << 11) | // Set stop condition
                     (1 << 13); // Set start condition
        for(i = 0; i < num_bytes; i++) {
            while(!(I2C1->STR & (1 << 3))) { } // Wait until data has been received
            data[i] = (uint8_t)I2C1->DRR; // Store the data
        }
        // Doesn't seem to be needed. Removed for now
        //while(!(I2C1->STR & (1 << 12))) { }  // Wait until the bus busy bit is cleared
        while(!(I2C1->STR & (1 << 5))) { } // wait until the stop condition is detected
        I2C1->STR |= (1 << 5); // Clear the stop condition flag in SCD register. Used in case of an interrupt
    }
	return;
}

/*
 * Writes data to a device. This will send the slave address, the initial destination register,
 * then the data bytes on after another.
 *
 * Input parameters
 *      slave_addr - The address of the slave that is being written to
 *      dest_reg - The initial register that is being written to. This assumes some sort of address increment support in the slave
 *      num_bytes - The number of bytes that are being written to the slave device
 *      *data - The pointer to the first byte of data's address
 *
 * No output parameters
 */
void I2C1_write(uint8_t slave_addr, uint16_t dest_reg, uint16_t num_bytes, uint8_t data[]) {
    I2C1->SAR = slave_addr; // Set the slave address
    I2C1->CNT = num_bytes+1; // Set the bytes to be sent/read to one, since destination register is being sent.
    I2C1->MDR |= (1 << 10) | // Make sure in master mode
                 (1 << 9)  | // Set the direction to transmit to send the register address
                 (1 << 11); // Set the stop condition
	if(I2C1_struct.int_ena) { // If I2C1 interrupts are enabled, use them
		 // Don't wait until  the transmit register is empty. This will hopefully address potential issues
        // when the buffer is added.
        I2C1_struct.data = data; // Store the pointer to the data
		I2C1_struct.byte_count = 0; // Reset the byte counter
		I2C1_struct.state = I2C_slave_reg; // Test the state machine that it's in the destination register send state
        I2C1->MDR |= (1 << 13); // Set start condition
        I2C1->DXR = dest_reg; // Set the destination register
        I2C1_struct.rd_wrt = 1; // Tell the state machine that a write will be done
        //I2C1_struct.num_bytes = num_bytes; // Set the number of bytes being read/written
    }
    else { // Else, use wait states
        while(!(I2C1->STR & (1 << 4))) { } // Wait to make sure that there's no data in the transmit register from a previously called transfer
        I2C1->SAR = slave_addr; // Set the slave address
        //I2C1->CNT = num_bytes+1; // Set the number of bytes being sent (CNT register)
        I2C1->MDR |= (1 << 10) | // Make sure in master mode
                     (1 << 9)  | // Set the direction to transmit to send the address
                     (1 << 11) | // Set stop condition to make sure that the start is valid
                     (1 << 13); // Set start condition
        I2C1->DXR = dest_reg; // Put data into the data transmit register (destination register)
        uint8_t i;
        for(i=0;i<num_bytes;i++) {
            while(!(I2C1->STR & (1 << 4))) { } // Wait to make sure that there's no data in the transmit register from a sending the destination register or another sent
            I2C1->DXR = data[i];
        }
        while(!(I2C1->STR & (1 << 4))) { } // Wait until the last byte has been sent
        while(!(I2C1->STR & (1 << 12))) { }  // Wait until the bus busy bit is cleared
        while(!(I2C1->STR & (1 << 5))) { } // wait until the stop condition is detected
        I2C1->STR |= (1 << 5); // Clear the stop condition flag in SCD register. Used in case of an interrupt
    }
    return;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


