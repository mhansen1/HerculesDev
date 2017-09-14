#include "HL_sys_common.h"
#include "reg_defs.h"
#include "n2het_prgm_example.h"
#include "hercules_N2HET.h"
#include "rti_example.h"

uint32_t data = (412 << 2);
uint32_t *data_addr = &data;

int main(void) {
	
	//rti0_toggle_example(75, 1000);
	
	/*
	 * Initialize the HTU
	 */
	//DCP1REG->DCPx[0].ITCOUNT = (1 << 16) | (1 << 0); // Do a single element transfer and a single frame transfer
	//DCP1REG->DCPx[0].IHADDRCT = (1 << 23) | // Main memory is read and NHET memroy is written.
	//                            (1 << 18) | // Set to circular buffer mode
	//                            (24 << 2); // Set the initial NHET address (the data field of ECMP is address 6)
	//DCP1REG->DCPx[0].IFADDRA =  (uint32_t)&data; // Set the initial address in main memory
	//HTU1REG->CPENA = 1; // Enable DCP[0] control packet A
	//HET1REG->GCR = (1 << 16); // Enable HTU1
	
	/*
	 * Initialize the N2HETs
	 * The HTU is attached to N2HET1
	 */

	HET1REG->DIR |= (1 << 0); // Enable N2HET1[0] pin for output
	HET2REG->DIR |= (1 << 0); // Enable N2HET2[0] pin for output
	
	// Set the resolution pre-scalars
	n2het1_hr_set(0);
	n2het1_lr_set(6);
	n2het2_hr_set(0);
	n2het2_lr_set(6);

    //HET1REG->REQENS |= (1 << 0); // Enable requests on line 0

    n2het1_init(N2HET_PRGM);
    n2het2_init(N2HET_PRGM);

    while(1) {

    }

    return 0;
}













