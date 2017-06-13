#ifndef _N2HET_INST_H_
#define _N2HET_INST_H_

#include "type_def.h"

/*
 * Equality Compare (ECMP)
 *
 * Tests the value in a specified ALU register (A, B, R, S, or T) to the
 * value stored in the data field. If equal, a conditional branch is done.
 */ 
typedef struct ecmp_data {
	// Program field
	uint32_t   : 6;	/**	6 bit zeros	*/
	uint32_t req_num : 3;	/**	Defines the number of the request line to trigger the HTU or DMA	*/
	uint32_t brk : 1;	/**	Defines if a software breakpoint is used here for debugging	*/
	uint32_t next : 9;	/**	The relative address of the next N2HET address	*/
	uint32_t   : 4;	/**	4 bit zeros	*/
	uint32_t hr_lr : 1;	/**	Specifies whether high or low resolution data is used	*/
	uint32_t angle : 1;	/**	Determines if an angle compare is done or not	*/
	uint32_t rsvd1 : 7;	/** Reserved field	*/
	// Control field 
	uint32_t rsvd2 : 3;	/** Reserved field	*/
	uint32_t req_type : 2; /**	Selection between no request, general request, and quiet request	*/
	uint32_t control : 1;	/**	If set, a read of the data field will clear the data	*/
	uint32_t rsvd3 : 3;	/** Reserved field	*/
	uint32_t en_pin : 4;	/**	Enables the pin for output action if set	*/
	uint32_t cond_addr : 9;	/**	The address that will be branched to if the compare is true	*/
	uint32_t pin_sel : 5;	/**	Selects the pin that will be used if pin action is enabled	*/
	uint32_t ext_reg : 1;	/**	Says whether or not an extended register will be used	*/
	uint32_t cmp_type : 2;	/**	Says the type of comparison being done. Must be set to 00 if doing ECMP	*/
	uint32_t action : 2;	/** Either sets, clears, pulse high, or pulse low on the selected pin when compare is true	*/
	uint32_t reg : 2;	/**	The ALU register that will be used (A, B, R, S, T, or none)	*/
	uint32_t int_ena : 1;	/**	Enables or disables IRQ ability on a true compare	*/
	// Data field
	uint32_t lr_data : 25;	/**	The data used for low and high resolution data	*/
	uint32_t hr_data : 7;	/**	Data field used to extend data in high resolution	*/
}ecmp_data_t;
// Put the memory structure and data structure into an union
typedef union {
	ecmp_data_t ecmp;
	het_memory_t ecmp_data;
} ECMP;

/*
 * Magnitude Compare (MCMP)
 *
 * Compares the value stored in a specified ALU register (A, B, R, S, or T) to the
 * value in the data field.
 */
typedef struct mcmp_data {
	// Program field
	uint32_t   : 6;	/**	6 bit zeros	*/
	uint32_t req_num : 3;	/**	Defines the number of the request line to trigger the HTU or DMA	*/
	uint32_t brk : 1;	/**	Defines if a software breakpoint is used here for debugging	*/
	uint32_t next : 9;	/**	The relative address of the next N2HET address	*/
	uint32_t   : 4;	/**	4 bit zeros	*/
	uint32_t hr_lr : 1;	/**	Specifies whether high or low resolution data is used	*/
	uint32_t angle : 1;	/**	Determines if an angle compare is done or not	*/
	uint32_t rsvd1 : 1;	/** Reserved field	*/
	uint32_t save_sub : 1;	/**	When set the comparison result is saved into the T register	*/
	uint32_t rsvd2 : 5;	/**	Reserved field	*/
	// Control field
	uint32_t rsvd3 : 6;	/** Reserved field	*/
	uint32_t rsvd4 : 3;	/** Reserved field	*/
	uint32_t req_type : 2; /**	Selection between no request, general request, and quiet request	*/
	uint32_t control : 1;	/**	If set, a read of the data field will clear the data	*/
	uint32_t rsvd5 : 3;	/** Reserved field	*/
	uint32_t en_pin : 4;	/**	Enables the pin for output action if set	*/
	uint32_t cond_addr : 9;	/**	The address that will be branched to if the compare is true	*/
	uint32_t pin_sel : 5;	/**	Selects the pin that will be used if pin action is enabled	*/
	uint32_t ext_reg : 1;	/**	Says whether or not an extended register will be used	*/
	uint32_t   : 1;	/**	Default value of 1	*/
	uint32_t order : 1;	/**	Specifies the order of the operands for comparison. If cleared, tests to see if register is greater than or equal to the data field. If set, tests to see if data field is greater or equal than the register value	*/
	uint32_t action : 2;	/** Either sets, clears, pulse high, or pulse low on the selected pin when compare is true	*/
	uint32_t reg : 2;	/**	The ALU register that will be used (A, B, R, S, T, or none)	*/
	uint32_t int_ena : 1;	/**	Enables or disables IRQ ability on a true compare	*/
	// Data field
	uint32_t lr_data : 25;	/**	The data used for low and high resolution data	*/
	uint32_t hr_data : 7;	/**	Data field used to extend data in high resolution	*/
} mcmp_data_t;
// Put the memory structure and data structure into an union.
typedef union {
	mcmp_data_t mcmp;
	het_memory_t mcmp_memory;
} MCMP;

/*
 * Counter (CNT)
 *
 * This is a virtual timer that increments unconditionally on each resolution.
 * When the count reaches its maximum, it resets
 */
typedef struct cnt_data {
	// Program field
	uint32_t   : 6;	/**	6 bit zeros	*/
	uint32_t req_num : 3;	/**	Defines the number of the request line to trigger the HTU or DMA	*/
	uint32_t brk : 1;	/**	Defines if a software breakpoint is used here for debugging	*/
	uint32_t next : 9;	/**	The relative address of the next N2HET address	*/
	uint32_t   : 4;	/**	4 bit set value of 0110	*/
	uint32_t angle_cnt : 1;	/**	Specifies when the count is incremented. If set, incremented when angle flag is set, otherwise increments when isntruciton is executed.	*/
	uint32_t reg : 2;	/**	Specifies the register that the value for the increment is stored in.	*/
	uint32_t cmp_sel : 1;	/**	Determines when the counter is reset; if set to EQ reset occurs when equal to maximum count; if set to GE resets occurs when greater or equal to maximum count	*/
	uint32_t rsvd1 : 4;	/**	Reserved field	*/
	uint32_t int_ena : 1;	/** Interrupt request enable/disabled	*/
	// Control field 
	uint32_t rsvd2 : 3;	/** Reserved field	*/
	uint32_t req_type : 2;	/**	Selection between no request, general request, and quiet request	*/
	uint32_t control : 1;	/**	If set, when the data field is read, it clears it	*/
	uint32_t rsvd3 : 1;	/**	Reserved field	*/
	uint32_t max_cnt : 25;	/**	The maximum value the counter will go up to before resetting	*/
	// Data field
	uint32_t lr_data : 25;	/**	Low resolution data field	*/
	uint32_t hr_data : 7;	/**	Data extention slots when using high resolution data	*/
} cnt_data_t;
// Put the memory structure and data structure into a union
typedef union {
	cnt_data_t cnt;
	het_memory_t cnt_memory;
} CNT;

/*
 * SHFT (Shift)
 *
 * This shifts data in or out on a pin. Will fill this in more later after messing with it a bit
 */
typedef struct shft_data {
	// Program field
	uint32_t   : 6;	/**	6 bit zeros	*/
	uint32_t req_num : 3;	/**	Defines the number of the request line to trigger the HTU or DMA	*/
	uint32_t brk : 1;	/**	Defines if a software breakpoint is used here for debugging	*/
	uint32_t next : 9;	/**	The relative address of the next N2HET address	*/
	uint32_t   : 4;	/**	4 bit set value of 1111	*/
	uint32_t rsvd1 : 5;	/** Reserved field	*/
	uint32_t smode : 4;	/**	Sets the shift mode on the pin. See table 23-70 for the values available	*/
	// Control field 
	uint32_t rsvd2 : 3;	/**	Reserved field	*/
	uint32_t req_type : 2;	/** Selection between no request, general request, and quiet request	*/
	uint32_t control : 1;	/**	If set, when the data field is read, it clears it	*/
	uint32_t rsvd3 : 3;	/**	Reserved field	*/
	uint32_t cond_addr : 9;	/**	The address that is branched to if condition is met (need to look into what this means for this instruction...)	*/
	uint32_t pin_sel : 5;	/**	Selects the pin associated with the shifting action	*/
	uint32_t ext_reg : 1;	/**	Says whether or not an extended register will be used	*/
	uint32_t shft_cond : 2;	/**	Sets what controls the shifting (Always [VCLK, I think...], rising edge of HET[0], or falling edge of HET[0])	*/
	uint32_t rsvd4 : 1;	/**	Reserved field	*/
	uint32_t   : 1;	/**	1 bit zeros	*/
	uint32_t reg : 2;	/**	Selects the ALU register to use. Where data is stored when read in (I think...)	*/
	uint32_t int_ena : 1;	/**	Enables/disables IRQ requests	*/
	// Data field 
	uint32_t data : 25;	/**	Data field	*/
	uint32_t rsvd5 : 7;	/**	Reserved field	*/
} shft_data_t;
// Put the memory structure and data structure into a union
typedef union {
	shft_data_t shft;
	het_memory_t sft_memory;
} SHFT;

/*
 * Create a pointer to the N2HET RAM locations
 */
typedef volatile struct hetRamLoc {
	het_memory_t instruction[128];
} hetRamLoc_t;
// Actually point to the RAM locations
#define HET1RAM ((hetRamLoc_t *) 0xFF460000)
#define HET2RAM ((hetRamLoc_t *) 0xFF440000)






#endif

