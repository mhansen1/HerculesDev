#include "HL_sys_common.h"
#include "HL_reg_system.h"
#include "HL_reg_pinmux.h"
#include "reg_defs.h"
#include "hercules_I2C.h"
#include "VIM.h"


int main(void) {

    I2C1_init(300000, 8, 8);
    I2C1_int_enable();

    uint8_t data[] = {0x18, 0x19, 0x20};
    uint8_t data2[5];
    uint16_t i;
    uint8_t delay = 125;

    I2C1_read(0x68, 0x75, 1, &data2);
    //for(i=0;i<delay;i++) { }
    //I2C1_write(0x68, 0x77, 3, &data);
    //for(i=0;i<delay;i++) { }
    //I2C1_read(0x68, 0x77, 3, &data2);

    while(1) {

    }

    return 0;
}






















