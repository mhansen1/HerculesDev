#ifndef _N2HET_PRGM_H_
#define _N2HET_PRGM_H_

#include "n2het_inst.h"

/*
 * This file holds the N2HET programs (for N2HET1 and N2HET2). To change the program,
 * you'll need to manually change the data field. There is also an assembler for the
 * N2HET assembly instructions on TI's website for the Hercules.
 *
 * Some things that need to be done in order to load the program.
 * 1. Check how many instructions are in each HET program and update the length define.
 *    This needs to be done for loading into memory and defining the memory array. The
 *    value should be the same as the number of instructions in the het instruction array.
 * 2. Put the actual instructions into the constant values. These are the binary values of 
 *    The instructions and what will be loaded in at initialization time.
 * 3. In the HET's union (below) put the instructions in the order that they are in in memory
 *    (for example, instruction 5 will be the fifth entry, instruction 2 will be the second
 *    entry, and so on). 
 * 4. May want to go into the linker file (default name is sys_link.cmd) and shorten the size
 *    of memory that the particular HET takes up. Defaulted to the maximum size of 0x1FFFF
 *    bytes. Just be sure that your program and stored data can fit into the allocated space.
 *    Failure to provide enough memory may throw an illegal memory access interrupt.
 *
 * As a note, when setting this up, it seems that only the evenly number pins (0, 2, 4, etc...)
 * can be used for output. When testing, when N2HET2[1] was tried, the pin wasn't giving an output,
 * but pins N2HET2[0] and N2HET[2] did. This needs to be looked at farther...
 */
 
#define HET1_LENGTH 2

#define HET2_LENGTH 2

// Program for the N2HET1 peripheral
const het_memory_t het1_instructions[] = {
	{
		// Program
		0x00002C20,
		// Control
		0x00000270,
		// Data
		0x00000000,
		// Reserved
		0x00000000
	},
	
	{
		// Program
		0x00000000,
		// Control
		0x00404058,
		// Data
		0x0000EA60,
		// Reserved
		0x00000000
	}
};
// Put the instruction memory and the instruction type defaults into a union
// This is more for convinience and ease of use. The instruction memory and
// program struct will take up the same memory space.
typedef union {
	het_memory_t instr_memory[HET1_LENGTH];
	struct {
		CNT L00;
		MCMP L01;
	} program_struct;
} het1_program;
// Actually instantiate the program
volatile het1_program het1_program_load;

// Program  for the N2HET2 peripheral
const het_memory_t het2_instructions[] = {
	{
		// Program
		0x00002C20,
		// Control
		0x00000270,
		// Data
		0x00000000,
		// Reserved
		0x00000000
	},
	
	{
		// Program
		0x00000000,
		// Control
		0x00404048,
		// Data
		0x0000EA60,
		// Reserved
		0x00000000
	}
};
// Put the instruction memory and the instruction type defaults into a union
// This is more for convinience and ease of use. The instruction memory and
// program struct will take up the same memory space.
typedef union {
	het_memory_t instr_memory[HET2_LENGTH];
	struct {
		CNT L00;
		MCMP L01;
	} program_struct;
} het2_program;
// Actually instantiate the program
volatile het2_program het2_program_load;





#endif

