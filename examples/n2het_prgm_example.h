#ifndef _N2HET_PRGM_EXAMPLE_H_
#define _N2HET_PRGM_EXAMPLE_H_

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
void n2het_pwm_example(void);



#endif

