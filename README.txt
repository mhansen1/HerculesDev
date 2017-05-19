This project is to develope drivers and design methodology
for the Hercules safety based microcontroller. It is not aimed
at a specific project, but at a general development.

Modules:

I2C:
	Description:
		This is setup to work by sending the slave's source/destination
		register in one transmission, then immediatly sending the write
		data or starting to read all the data. Reading or writing data
		uses pointers, that way the user isn't restricted to the number
		of bytes that are transfered.
	Status:
		I2C1 is working with while loops and with interrupts. There
		is still a potential issue of the bus locking up if there
		isn't sufficient delay between two transmissions.
		Need to add in a buffer (will help with the delay).
		Need to add in DMA support