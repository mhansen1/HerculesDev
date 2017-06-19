#include "HL_sys_common.h"
#include "HL_reg_system.h"
#include "HL_reg_pinmux.h"
#include "reg_defs.h"
#include "hercules_I2C.h"
#include "VIM.h"
#include "n2het_prgm_example.h"
#include "rti_example.h"

int main(void) {
	
	rti0_toggle_example(75, 1000);
	
	n2het_pwm_example();
	
    while(1) {

    }

    return 0;
}













