#include "n2het_prgm_example.h"
#include "reg_defs.h"
#include "hercules_N2HET.h"

/*
 * This example has two PWM waves. N2HET1[0] has a PWM of just under 1.9kHz
 * at 25%. The second wave is one N2HET2[0] and has a duty cycle of 75%. It
 * is 180 degrees out of phase with the N2HET1 PWM (if N2HET1 pin is on,
 * N2HET2 is off, and if N2HET1 is off, N2HET2 is off).
 *
 * No input parameters
 *
 * No output parameters
 */
void n2het_pwm_example(void) {
	HET1REG->DIR |= (1 << 0); // Enable N2HET1[0] pin for output
	HET2REG->DIR |= (1 << 0); // Enable N2HET2[0] pin for output
	
	// Set the resolution pre-scalars
	n2het1_hr_set(0);
	n2het1_lr_set(6);
	n2het2_hr_set(0);
	n2het2_lr_set(6);

	n2het1_init(N2HET_PRGM);
	n2het2_init(N2HET_PRGM);
	
	return;
}
