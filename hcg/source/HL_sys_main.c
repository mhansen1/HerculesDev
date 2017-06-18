#include "HL_sys_common.h"
#include "HL_reg_system.h"
#include "HL_reg_pinmux.h"
#include "reg_defs.h"
#include "hercules_I2C.h"
#include "VIM.h"
#include "n2het_prgm_example.h"
#include "hercules_rti.h"

//#pragma CODE_STATE(toggleISR, 32)
//#pragma INTERRUPT(toggleISR, IRQ)
void toggleISR(void) {
    //RTIREG->INTFLAG = 3;
	GIOA->DOUT ^= 2;
	return;
}

int main(void) {
	
	GIOCNTL->GCR0 = 1;
	GIOA->DIR |= 0x00000007;
	GIOA->DCLR = 0x00000007;

	rti0_init(1000, 75);
	rti0_int_ena();
	rti0_int_func(&toggleISR);
	rti_cnt0_start();
	
	n2het_pwm_example();
	
    while(1) {

    }

    return 0;
}













