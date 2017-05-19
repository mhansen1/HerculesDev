#include "I2C_example.h"

void I2C1_examp(void) {
	// Initialize the I2C1 module with a clock of ~300kHz, 8 address bits, and 8 bits per transfer
	I2C1_init(300000, 8, 8);
	// Enable interrupts
    I2C1_int_enable();

	// Data to send
    uint8_t data[] = {0x18, 0x10, 0x09};
    // Data to be read in 
	uint8_t data2[3];
	
	// Delay variables to go between transfers.
	// As of right now, sometimes if a transfer occurs too fast after the
	// previous one, the bus locks up.
    uint16_t i;
    uint32_t delay = 5000;

	// Read the WHO AM I register of the MPU 9250
    I2C1_read(0x68, 0x75, 1, &data2);
	// Wait until the transfer is done, then wait a bit more
    while(I2C1_state() != I2C_idle) { }
    for(i=0;i<delay;i++) { }
	// Read some accelerometer offset registers.
	// Should have a value of 0 after reset
    I2C1_read(0x68, 0x1B, 3, &data2);
	// Delays
    while(I2C1_state() != I2C_idle) { }
    for(i=0;i<delay;i++) { }
	// Write offsets to the accelerometer registers 
    I2C1_write(0x68, 0x1B, 3, &data);
    // Delays
	while(I2C1_state() != I2C_idle) { }
    for(i=0;i<delay;i++) { }
	// Read from the offset again. Should no longer be zero.
    I2C1_read(0x68, 0x1B, 3, &data2);
}