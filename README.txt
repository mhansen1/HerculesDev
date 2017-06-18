This project is to develope drivers and design methodology
for the Hercules safety based microcontroller. It is not aimed
at a specific project, but at a general development.

Peripherals:

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
		
N2HET
	Description:
		This can be setup in two ways. The first way is to use is just
		as GPIO pins. The second way is to use it as a co-processor.
		Each N2HET peripheral has an independent processor with its
		own instructions that runs independently of the main ARM processor.
		This means that with two N2HET modules, there is a total of three
		processors that can be running in parallel. These N2HET ones are
		meant for independently interfacing with outside components, 
		generating complex waveforms, and performing data acquisition.
	Status:
		Right now, the GIO functionality is implemented, as well as a
		basic N2HET example program. There are only three instructions
		implemented (CNT, MCMP, and SHFT), but only CNT and MCMP have been
		successfully tested. Still need to get the SHFT to work and figure
		it out to fully document it.
		
RTI:
	Description:
		This is the Real Time Interrupt (RTI) peripheral. It is just a set
		of timers that are interrupt capable. There are two different counters
		and up to four different comparison values, for a maximum of four
		different timers. The source for this can be an external clock or
		an internal clock (VCLK).
	Status:
		Have RTI working and functions written for it. Have implemented 
		interrupts for when the comparison of the counter and the value set
		by the user are the same. Still need to add in functions for the other
		compares and the other counter.