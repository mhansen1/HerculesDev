#include "N2HET_GIO_example.h"

void N2HET_GIO_example(void) {
    // Initialize N2HET1 as a GIO
    N2HET1_init(N2HET_GIO);
    // Initialize N2HET2 as a GIO
    N2HET2_init(N2HET_GIO);

    // Want to demonstrate N2HET2 on the pre-soldered pins of the LaunchPad, so
    // change the functions on one of the pins to do that using the pin-mux control register
    // Enable changing of mux outputs
    PINMUXREG->KICKER0 = 0x83E70B13U;
    PINMUXREG->KICKER1 = 0x95A4F1E0U;
    PINMUXREG->PINMUXO[19] &= ~0x7; // Make sure that the selection on the mux is clear
    PINMUXREG->PINMUXO[19] |= (1 << 2); // Enable the N2HET2[0] on pin C1/J4[8]
    // Lock the pin mux again.
    PINMUXREG->KICKER0 = (uint32_t)0;
    PINMUXREG->KICKER1 = (uint32_t)0;
    // See the technical reference manual (Pin Mux section) on how to chance the function of a
    // ball on the Hercules chip.

    // Set N2HET1[13] (pin J1[4] on LaunchPad) to output
    N2HET1_dir_out((1 << 13));
    // Set N2HET2[0] (pin J4[8] on the LaunchPad) to output
    N2HET2_dir_out((1 << 0));

    // Just run a while loop to make sure that the pin is responding as a GIO
    while (1) {
        N2HET1_dat_tgl((1 << 13));
        N2HET2_dat_tgl((1 << 0));
    }
}


