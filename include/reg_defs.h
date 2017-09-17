/*
 *
 * This header file contains the base and offset addresses for the registers
 *
 */
 
 #ifndef _REGDEFS_H_
 #define _REGDEFS_H_
 
/*
 * INCLUDES
 */
#include "type_def.h"

/**
 * GENERAL INFO:
 * 1. GCLK = CPU clock
 * 2. HCLK = System clock
 * 3. VCLK & VCLK2 = Peripheral clock
 * 4. LPO = Low Power Oscillator
 * 5. GIO = Generial Input/Output
 */

/**
 *
 * Primary system module registers.
 * More info found on page 139 of the technical reference manual
 *
 */ 
typedef volatile struct sysRegDefs1 {
    uint32_t SYSPC1;            // SYS Pin Control Register 1
    uint32_t SYSPC2;            // SYS Pin Control Register 2
    uint32_t SYSPC3;            // SYS Pin Control Register 3
    uint32_t SYSPC4;            // SYS Pin Control Register 4
    uint32_t SYSPC5;            // SYS Pin Control Register 5
    uint32_t SYSPC6;            // SYS Pin Control Register 6
    uint32_t SYSPC7;            // SYS Pin Control Register 7
    uint32_t SYSPC8;            // SYS Pin Control Register 8
    uint32_t SYSPC9;            // SYS Pin Control Register 9
    uint32_t rsvd1;             // Reserved hardware space
    uint32_t rsvd2;             // Reserved hardware space
    uint32_t rsvd3;             // Reserved hardware space
    uint32_t CSDIS;         // Clock source disable register
    uint32_t CSDISSET;      // Clock source disable set register
    uint32_t CSDISCLR;      // Clock source disable clear register
    uint32_t CDDIS;         // CLock domain disable register
    uint32_t CDDISSET;      // Clock domain disable set register
    uint32_t CDDISCLR;      // Clock domain disable clear register
    uint32_t GHVSRC;            // GCLK, HCLK, VCLK, and VCLK2 source register
    uint32_t VCLKASRC;      // Peripheral asynchronous clock source register
    uint32_t RCLKSRC;       // RTI clock source register
    uint32_t CSVSTAT;       // Clock source valid status register
    uint32_t MSTGCR;            //  Memory self-test global control register
    uint32_t MINITGCR;      // Memory hardware initialization global control register
    uint32_t MSINEA;            // Memory self-test/initialization enable register
    uint32_t rsvd12;            // Reserved hardware space
    uint32_t MSTCGSTAT; // MSTC global status register
    uint32_t MINISTAT;      // Memory Hardware initialization status register
    uint32_t PLLCTL1;           // PLL control register 1
    uint32_t PLLCTL2;           // PLL control register 2
    uint32_t SYSPC10;           // SYS Pin Control Register 10
    uint32_t DIEIDL;            // Die identification register, lower word
    uint32_t DIEIDH;            // Die identification register, upper word
    uint32_t rsvd4;             // Reserved hardware space
    uint32_t LPOMONCTL;     // LPO/clock monitor control register
    uint32_t CLKTEST;           // Clock test register
    uint32_t DFTCTRLREG;    // DFT control register
    uint32_t DFTCTRLREG2;   // DFT control register 2
    uint32_t rsvd5;             // Reserved hardware space
    uint32_t rsvd6;             // Reserved hardware space
    uint32_t GPREG1;            // General purpose register
    uint32_t rsvd7;             // Reserved hardware space
    uint32_t rsvd8;             // Reserved hardware space
    uint32_t rsvd9;             // Reserved hardware space
    uint32_t SSIR1;             // System software interrupt request 1 register
    uint32_t SSIR2;             // System software interrupt request 2 register
    uint32_t SSIR3;             // System software interrupt request 3 register
    uint32_t SSIR4;             // System software interrupt request 4 register
    uint32_t RAMGCR;            // RAM control register
    uint32_t BMMCR1;            // Bus matrix module control register 1
    uint32_t rsvd10;            // Reserved hardware space
    uint32_t CPURSTCR;      // CPU reset control register
    uint32_t CLKCNTL;           // Clock control register
    uint32_t ECPCNTL;           // ECP control register
    uint32_t rsvd11;            // Reserved hardware space
    uint32_t DEVCR1;            // DEV parity control register 1
    uint32_t SYSECR;            // System exception control register
    uint32_t SYSESR;            // System exception status register
    uint32_t SYSTASR;           // System test abort status register
    uint32_t GBLSTAT;           // Global status register
    uint32_t DEVID;             // Device identification register
    uint32_t SSIVEC;            // Software interrupt vector register
    uint32_t SSIF;              // System software interrupt flag register
} sysRegDefs1_t;
// Set the base address for the primary system registers 
#define SYSREG1 ((sysRegDefs1_t *)0xFFFFFF00U)
 
/**
 *
 * Secondary system module registers.
 * More info found on page 191 of the technical reference manual
 *
 */ 
typedef volatile struct sysRegDefs2 {
    uint32_t PLLCTL3;           // PLL control register 3
    uint32_t rsvd1;             // Reserved hardware space
    uint32_t STCCLKDIV;     // CPU logic BIST clock divider
    uint32_t rsvd2;             // Reserved hardware space
    uint32_t ECPCNTL;           // ECP control register. The ECPCNTL register has the mirrored location at this address
    uint32_t ECPCNTL1;      // ECP control register 1
    uint32_t rsvd3;             // Reserved hardware space
    uint32_t CLK2CNTRL;     // Clock 2 control register
    uint32_t VCLKACON1; // Peripheral asynchronous clock configuration 1 register
    uint32_t rsvd4;             // Reserved hardware space
    uint32_t HCLKCNTL;      // HCLK control register
    uint32_t rsvd5;             // Reserved hardware space
    uint32_t CLKCLIP;           // Clock slip control register
    uint32_t rsvd6;             // Reserved hardware space
    uint32_t IP1ECCERREN;   // IP ECC error enable register
    uint32_t rsvd7;             // Reserved hardware space
    uint32_t EFC_CTLREG;    // EFUSE controller control register
    uint32_t DIEDL_REG0;    // Die identification register, lower word
    uint32_t DIEDH_REG1;    // Die identification register, upper word
    uint32_t DIEDL_REG2;    // Die identification register, lower word
    uint32_t DIEDH_REG3;    // Die identification register, upper word
} sysRegDefs2_t;
// Set the base address for the secondary system registers 
#define SYSREG2 ((sysRegDefs2_t *)0xFFFFE100U)
 
 
/**
 *
 * Setup the Vector Interrupt Moduel (VIM) control registers 
 *
 */
typedef volatile struct vimCntlRegDefs {
	uint32_t IRQINDEX;	/** IRQ Index Offset Vector Register; Offset 0x00	*/
	uint32_t FIQINDEX;	/**	FIX Index Offset Vector Register; Offset 0x04	*/
	uint32_t rsvd1[2];		/** Reserved Space; Offset 0x08*/
	uint32_t FIRQPR[4];	/**	FIQ/IRQ Program Control Registers; Offset 0x10	*/
	uint32_t INTREQ[4];	/** Pending Interrupt Read Location Registers; Offset 0x20	*/
	uint32_t REQENASET[4];	/** Interrupt Enable Set Registers; Offset 0x30	*/
	uint32_t REQENACLR[4];	/** Interrupt Enable Clear Registers; Offset 0x40	*/
	uint32_t WAKEENASET[4];	/**	Wake-up Enable Set Registers; Offset 0x50	*/
	uint32_t WAKEENACLR[4];	/** Wake-up Enable Clear Registers; Offset 0x60	*/
	uint32_t IRQVECREG;	/**	IRQ Interrupt Vector Register; Offset 0x70	*/
	uint32_t FIXVECREG;	/** FIQ Interrupt Vector Register; Offset 0x74	*/
	uint32_t CAPEVT;	/** Capture Event Register; Offset 0x78	*/
	uint32_t rsvd2;	/** Reserved Space; Offset 0x7C	*/
	uint32_t CHANCTRL[32];	/** VIM Interrupt Control Registers; Offset 0x80	*/

} vimCntlRegDefs_t;
// Set the base address for the VIM control registers 
#define VIMCNTL ((vimCntlRegDefs_t *)0xFFFFFE00)

/**
 *
 * Setup the Vector Interrupt Module (VIM) ECC related registers
 *
 */
typedef volatile struct vimEccRegDefs {
	uint32_t rsvd[59];	/** Reserved Space; Offset 0x00	*/
	uint32_t ECCSTAT;	/** Interrupt Vector Table ECC Status Register; Offset 0xEC	*/
	uint32_t ECCCTL;	/**	Interrupt Vector Table ECC Control Register; Offset 0xF0	*/
	uint32_t UERRADR;	/**	Uncorrectable Error Address Register; Offset 0xF4	*/
	uint32_t FBVECADDR;	/**	Fallback Vector Address Register; Offset 0xF8	*/
	uint32_t SBERRADDR;	/**	Single Bit Error Address Register; Offset oxFC	*/
} vimEccRegDefs_t;
// Setup the base address for the ECC based control registers for the VIM
#define VIMECC ((vimEccRegDefs_t *)0xFFFFFD00)

/**
 *
 * Setup the GIO configuration control registers 
 *
 */
 typedef volatile struct gioCntlRegDefs {
    uint32_t GCR0;      // GIO global control register
    uint32_t rsvd1;             // Reserved hardware space
    uint32_t INTDET;        // GIO interrupt detect register
    uint32_t POL;           // GIO interrupt polarity register
    uint32_t ENASET;        // GIO interrupt enable set register
    uint32_t ENACLR;        // GIO interrupt enable clear register
    uint32_t LVLSET;        // GIO interrupt priority set register
    uint32_t LVLCLR;        // GIO interrupt priority clear register
    uint32_t FLG;           // GIO interrupt flag register
    uint32_t OFF1;          // GIO offset 1 register
    uint32_t OFF2;          // GIO offset 2 register
    uint32_t EMU1;          // GIO emulation 1 register
    uint32_t EMU2;          // GIO emulation 2 register
} gioCntlRegDefs_t;
// Set base address for the GIO control registers 
#define GIOCNTL ((gioCntlRegDefs_t *)0xFFF7BC00U)
 
/*
 *
 * Setup the GIO port control registers
 *
 */
 typedef volatile struct gioPortRegDefs {
    uint32_t DIR;                   // GIO data direction register
    uint32_t DIN;                   // GIO data input register
    uint32_t DOUT;              // GIO data output register
    uint32_t DSET;              // GIO data set register
    uint32_t DCLR;          // GIO data clear registers
    uint32_t PDR;               // GIO open drain register
    uint32_t PULDIS;            // GIO pull disable register
    uint32_t PSL;                   // GIO pull select register
} gioPortRegDefs_t;
// Set base address for GIO port A
#define GIOA ((gioPortRegDefs_t *)0xFFF7BC34U)
// Set base address for GIO port A
#define GIOB ((gioPortRegDefs_t *)0xFFF7BC54U)
 
/**
 *
 * Peripheral Central Recource (PCR) Control Registers
 * More info on these can be found on page 203 of the technical manual
 *
 */
 
/** TODO
 *    This is still in the format of TI's given register file. May need to redo because of copywrite stuffs.
 *    Mainly need to look some more at the PCR section and figure out exaclt how things with a 'x' function
 *    (such as PSxMSTID[32]). To just write out all the registers would be a monsterous task.
 */
 typedef volatile struct pcrRegDefs
{
    uint32_t PMPROTSET0;    /* 0x0000 */
    uint32_t PMPROTSET1;    /* 0x0004 */
    uint32_t rsvd1[2U];     /* 0x0008 */
    uint32_t PMPROTCLR0;    /* 0x0010 */
    uint32_t PMPROTCLR1;    /* 0x0014 */
    uint32_t rsvd2[2U];     /* 0x0018 */
    uint32_t PPROTSET0;     /* 0x0020 */
    uint32_t PPROTSET1;     /* 0x0024 */
    uint32_t PPROTSET2;     /* 0x0028 */
    uint32_t PPROTSET3;     /* 0x002C */
    uint32_t rsvd3[4U];     /* 0x0030 */
    uint32_t PPROTCLR0;     /* 0x0040 */
    uint32_t PPROTCLR1;     /* 0x0044 */
    uint32_t PPROTCLR2;     /* 0x0048 */
    uint32_t PPROTCLR3;     /* 0x004C */
    uint32_t rsvd4[4U];     /* 0x0050 */
    uint32_t PCSPWRDWNSET0; /* 0x0060 */
    uint32_t PCSPWRDWNSET1; /* 0x0064 */
    uint32_t rsvd5[2U];     /* 0x0068 */
    uint32_t PCSPWRDWNCLR0; /* 0x0070 */
    uint32_t PCSPWRDWNCLR1; /* 0x0074 */
    uint32_t rsvd6[2U];     /* 0x0078 */
    uint32_t PSPWRDWNSET0;  /* 0x0080 */
    uint32_t PSPWRDWNSET1;  /* 0x0084 */
    uint32_t PSPWRDWNSET2;  /* 0x0088 */
    uint32_t PSPWRDWNSET3;  /* 0x008C */
    uint32_t rsvd7[4U];     /* 0x0090 */
    uint32_t PSPWRDWNCLR0;  /* 0x00A0 */
    uint32_t PSPWRDWNCLR1;  /* 0x00A4 */
    uint32_t PSPWRDWNCLR2;  /* 0x00A8 */
    uint32_t PSPWRDWNCLR3;  /* 0x00AC */
    uint32_t rsvd8[4U];     /* 0x00B0 */
    uint32_t PDPWRDWNSET;   /* 0x00C0 */
    uint32_t PDPWRDWNCLR;   /* 0x00C4 */
    uint32_t rsvd9[78U];    /* 0x00C8 */
    uint32_t MSTIDWRENA;    /* 0x0200 */
    uint32_t MSTIDENA;      /* 0x0204 */
    uint32_t MSTIDDIAGCTRL; /* 0x0208 */
    uint32_t rsvd10[61U];   /* 0x020C */
    struct
    {
        uint32_t PSxMSTID_L;
        uint32_t PSxMSTID_H;
    }PSxMSTID[32];            /* 0x0300 */
    struct
    {
        uint32_t PPSxMSTID_L;
        uint32_t PPSxMSTID_H;
    }PPSxMSTID[8];            /* 0x0400 */
    struct
    {
        uint32_t PPSExMSTID_L;
        uint32_t PPSExMSTID_H;
    }PPSExMSTID[32];            /* 0x0440 */
    uint32_t PCSxMSTID[32];    /* 0x0540 */
    uint32_t PPCSxMSTID[8];    /* 0x05C0 */
} pcrRegDefs_t;
// Set base address of PCR register 1
#define PCRREG1 ((pcrRegDefs_t *)0xFFFF1000U)
// Set base address of PCR register 2
#define PCRREG2 ((pcrRegDefs_t *)0xFCFF1000U)
// Set base address of PCR register 3
#define PCRREG3 ((pcrRegDefs_t *)0xFFF78000U)


/**
 *
 * Pin multiplexing register (I/O Multiplexing and Control Module (IOMM))
 * For more info see page 313 of the technical manual
 * For a table on the pin functions see tables 6-1 (page 289), 6-2 (page 294)
 * and 6-3 (page 297) of the technical manual
 * Register info found on page 313 of the technical manual
 * 
 */
typedef volatile struct muxRegDefs {
    uint32_t REGISION_REG;      // Revision register
    uint32_t rsvd1[7];          // Reserved hardware space
    uint32_t BOOT_REG;          // Boot mode register
    uint32_t rsvd2[5];          // Reserved hardware space
    uint32_t KICK_REG0;         // Kicker register 0. Write 0x83E70B13 to unlock CPU write acess to PINMMRnn registers
    uint32_t KICK_REG1;         // Kicker register 1. Write 0x95A4F1E0 to unlock CPU write acess to PINMMRnn registers
    uint32_t rsvd3[40];         // Reserved hardware space
    uint32_t ERR_RAW_STATUS_REG;// Error raw status/set register
    uint32_t ERR_ENABLED_STATUS_REG;// Error enabled status/clear register
    uint32_t ERR_ENABLE_REG;    // Error signalling enable register
    uint32_t ERR_ENABLE_CLR_REG;// Error signalling enable clear register
    uint32_t rsvd4;             // Reseverd hardware space
    uint32_t FAULT_ADDRESS_REG; // Fault address register
    uint32_t FAULT_STATUS_REG;  // Fault status register
    uint32_t FAULT_CLEAR_REG;   // Fault clear register
    uint32_t rsvd5[4];          // Reserved hardware space
    uint32_t PINMUXOUT[38];     // Output pin multiplexing control registers
    uint32_t rsvd6[42];         // Reserved hardware space
    uint32_t PINMUXIN[20];      // Input pin multiplexing control registers
    uint32_t rsvd[60];          // Reserved hardware space
    uint32_t PINMUXSPCL[20];    // Special functionality control registers
} muxRegDefs_t;
// Set base address for the I/O pin multiplexer
#define IOMMREG ((muxRegDefs_t *)0xFFFF1C00)
 
 /**
 *
 * High End Timer (HET) register definitions
 * For more info see page 968 of the technical manual.
 * 
 */
typedef volatile struct hetRegDefs {
    uint32_t GCR;           /** Global configuration register   */
    uint32_t PFR;           /** Prescale factor register        */
    uint32_t ADDR;          /** NHET current address register   */
    uint32_t OFF1;          /** Offset index priority level 1 register  */
    uint32_t OFF2;          /** Offset index priority level 2 register  */
    uint32_t INTENAS;   /** Interrupt enable set register   */
    uint32_t INTENAC;   /** Interrupt enable clear register */
    uint32_t EXC1;          /** Exception control register 1    */
    uint32_t EXC2;          /** Exception control register 2    */
    uint32_t PRY;           /** Interrupt priority register */
    uint32_t FLG;           /** Interrupt flag register */
    uint32_t AND;           /** AND share control register  */
    uint32_t rsvd1;         /** Reseverd hardware space */
    uint32_t HRSH;          /** HR share control regsiter   */
    uint32_t XOR;           /** HR XOR share control register   */
    uint32_t REQENS;        /** Request enable set register */
    uint32_t REQENC;        /** Request enable clear register   */
    uint32_t REQDS;     /** Request destination select register */
    uint32_t rsvd2;         /** Reserved hardware space */
    uint32_t DIR;           /** NHET direction register */
    uint32_t DIN;           /** NHET data input register    */
    uint32_t DOUT;          /** NHET data output register   */
    uint32_t DSET;          /** NHET set output register    */
    uint32_t DCLR;          /** NHET clear output register  */
    uint32_t PDR;           /** NHET open drain register    */
    uint32_t PULDIS;        /** NHET pull disable register  */
    uint32_t PSL;           /** NHET pull select register   */
    uint32_t rsvd3;         /** Reserved hardware space */
    uint32_t rsvd4;         /** Reserved hardware space */
    uint32_t PCR;           /** Parity control register */
    uint32_t PAR;           /** Parity address register */
    uint32_t PPR;           /** Parity pin register */
    uint32_t SFPRLD;        /** Suppression filter preload register */
    uint32_t SFENA;     /** Suppression filter enable register  */
    uint32_t rsvd5;         /** Reserved hardware space */
    uint32_t LBPSEL;        /** Loop back pair select register  */
    uint32_t LBPDIR;        /** Loop back pair direction register   */
    uint32_t PINDIS;        /** NHET pin disable registe    */
} hetRegDefs_t;
// Set the base for the HET modules (HET1 and HET2)
#define HET1REG ((hetRegDefs_t *)0xFFF7B800U)
#define HET2REG ((hetRegDefs_t *)0xFFF7B900U)

/**
 * The control for the mux of the pins
 */
/**
 * TODO
 *  Make sure the PINMUXI/PINMUXS have the correct number of reserved spaces between them.
 */
typedef volatile struct pinMuxRegDefs
{
    uint32_t REVISION_REG; /**  Revision Register; Offset 0x00  */
    uint32_t rsvd1[7];   /**    Reserved memory space   */
    uint32_t BOOT_REG;  /* Boot Mode Register; Offset 0x20 */
    uint32_t rsvd2[5];  /** Reserved memory space   */
    uint32_t KICKER0;       /** Unlock pin mux register 0; Offset 0x38  */
    uint32_t KICKER1;       /** Unlock pin mux register 1; Offset 0x3C  */
    uint32_t rsvd3[40]; /** Reserved memory space   */
    uint32_t ERR_RAW_STATUS_REG;    /** Error raw status/set register; Offset 0xE0   */
    uint32_t ERR_ENABLED_STATUS_REG;    /** Error enabled/clear register; Offset 0xE4   */
    uint32_t ERR_ENABLE_REG;        /** Error signaling enable register; Offset 0xE8    */
    uint32_t ERR_ENABLE_CLR_REG;    /** Error signaling enable clear register; Offset 0xEC  */
    uint32_t rsvd4;             /** Reserved memory space   */
    uint32_t FAULT_ADDRESS_REG; /** Fault address register; Offset 0xF4 */
    uint32_t FAULT_STATUS_REG;  /** Fault status register; Offset 0xF8  */
    uint32_t FAULT_CLEAR_REG;       /** Fault clear register; Offset 0xFC   */
    uint32_t rsvd5[4];          /** Reserved memory space   */
    uint32_t PINMUXO[38];           /** Output pin multiplexer; Offset 0x110    */
    uint32_t rsvd6[41]; /** Reserved memory space   */
    uint32_t PINMUXI[20];   /** Input pin multiplexer; Offset 0x250 */
    uint32_t rsvd7[59]; /** Reserved memory space   */
    uint32_t PINMUXS[20];   /** Specialty function pin multiplexer; Offset 0x390    */


}pinMuxRegDefs_t;
// Set the base address for the pin mux
#define PINMUXREG ((pinMuxRegDefs_t *) 0xFFFF1C00U)

/**
 * High End Timer Transfer Unit (HTU) register definitions
 * For more info see page 1082 of the technical reference manual.
 */
typedef volatile struct htuRegDefs {
	uint32_t GC;	/**	Global control register; Offset 0x00	*/
	uint32_t CPENA;	/**	Control Packet Enable Register; Offset 0x04	*/
	uint32_t BUSY[4];	/**	Control Packet busy register; Offset 0x08	*/
	uint32_t ACPE;	/**	Active control packet and error register; Offset 0x18	*/
	uint32_t rsvd1;	/**	Reserved memory space; Offset 0x1C	*/
	uint32_t RLBECTRL;	/**	Request lost and bus error control register; Offset 0x20	*/
	uint32_t BFINTS;	/**	Buffer full interrupt enable set register; Offset 0x24	*/
	uint32_t BFINTC;	/**	Buffer full interrupt enable clear register; Offset 0x28	*/
	uint32_t INTMAP;	/**	Interrupt mapping register; Offset 0x2C	*/
	uint32_t rsvd2;	/**	Reserved memory space; Offset 0x30	*/
	uint32_t INTOFF0;	/**	Interrupt offset register 0; Offset 0x34	*/
	uint32_t INTOFF1;	/**	Interrupt offset register 1; Offset 0x38	*/
	uint32_t BIM;	/**	Buffer initialization mode register; Offset 0x3C	*/
	uint32_t RLOSTFL;	/**	Request lost flag register; Offset 0x40	*/
	uint32_t BFINTFL;	/**	Buffer full interrupt flag register; Offset 0x44	*/
	uint32_t BERINTFL;	/**	BER itnerrupt flag register; Offset 0x48	*/
	uint32_t MP1S;	/**	Memory protection 1 start address register; Offset 0x4C	*/
	uint32_t MP1E;	/**	Memory protection 1 end address register; Offset 0x50	*/
	uint32_t DCTRL;	/**	Debug control register; Offset 0x54	*/
	uint32_t WPR;	/**	Watch point register; Offset 0x58	*/
	uint32_t WMR;	/**	Watch mask register; Offset 0x5C	*/
	uint32_t ID;	/**	Module identification register; Offset 0x60	*/
	uint32_t PCR;	/**	Parity control register; Offset 0x64	*/
	uint32_t PAR;	/**	Parity address register; Offset 0x68	*/
	uint32_t rsvd3;	/**	Reserved memory space; Offset 0x6C	*/
	uint32_t MPCS;	/**	Memory protection control and status register; Offset 0x70	*/
	uint32_t MP0S;	/**	Memory protection 0 start address register; Offset 0x74	*/
	uint32_t MP0E;	/**	Memory protection 0 end address register; Offset 0x78	*/
} htuRegDefs_t;
// Set the base address for the HTU registers for HTU1 and HTU2
#define HTU1REG ((htuRegDefs_t *) 0xFFF7A400)
#define HTU2REG ((htuRegDefs_t *) 0xFFF7A500)

/**
 * Double Control Packet (DCP) Conficturation Memory Registers
 * For more info see page 1108 of the technical reference manual
 */
typedef volatile struct dcpRegDefs {
	/**	Initial HTU buffer registers	*/
	struct {	
		uint32_t IFADDRA;	/**	Initial full address A register	*/
		uint32_t IFADDRB;	/**	Initial full address B register	*/
		uint32_t IHADDRCT;	/**	Initial NHET address and control register	*/
		uint32_t ITCOUNT;	/**	Initial transfer count register	*/
	}DCPx[8];
	/**	Current HTU buffer registers	*/
	struct {
		uint32_t CFADDRA;	/**	Current full address A register	*/
		uint32_t CFADDRB;	/**	Current full address B register	*/
		uint32_t CFCOUNT;	/**	Current frame count address register	*/
	}CDCPx[8];
}dcpRegDefs_t;
// Set the base address for the DCP configuration
#define DCP1REG ((dcpRegDefs_t *) 0xFF4E0000)
#define DCP2REG ((dcpRegDefs_t *) 0xFF4C0000)

/**
 * The control registers for the MibSPI
 */
typedef volatile struct mibspiRegDefs
{
    uint32_t  GCR[2];                 /** Global Control Registers */
    uint32_t  INT0;                 /** Interrupt Register */
    uint32_t  LVL;                  /** Interrupt Level Register */
    uint32_t  FLG;                  /** Interrupt flags Register*/
    uint32_t  PC[9];                /** Pin Control Registers 0 through 8 */
    uint32_t  DAT[2];                 /** Transmit Data Registers */
    uint32_t  BUF;                  /** Receive Buffer */
    uint32_t  EMU;                  /** Emulation Receive Buffer */
    uint32_t  DELAY;                /** Delays */
    uint32_t  DEF;                /** Default Chip Select */
    uint32_t  FMT[4];                 /** Data Format Registers 0 through 3 */
    uint32_t  INTVECT[2];             /** Interrupt Vector Registers */
    uint32_t  rsvd1[2];                /** Slew Rate Select */
    uint32_t  PMCTRL;               /** Parallel Mode Control */
    uint32_t  MIBSPIE;              /** Multi-buffer Mode Enable  */
    uint32_t  TGITENST;             /** TG Interrupt Enable Set */
    uint32_t  TGITENCR;             /** TG Interrupt Enable Clear */
    uint32_t  TGITLVST;             /** Transfer Group Interrupt Level Set */
    uint32_t  TGITLVCR;             /** Transfer Group Interrupt Level Clear */
    uint32_t  TGINTFLG;             /** Transfer Group Interrupt Flag */
    uint32_t  rsvd2[2];           /** Reserved hardware space */
    uint32_t  TICKCNT;              /** Tick Counter */
    uint32_t  LTGPEND;              /** Last TG End Pointer */
    uint32_t  TGCTRL[16];          /** 0x00D4: Transfer Group Control */
    uint32_t  DMACTRL[8];          /** 0x00F4: DMA Control */
    uint32_t  DMACOUNT[8];         /** 0x0114: DMA Count */
    uint32_t  DMACNTLEN;            /** 0x0114: DMA Control length */
    uint32_t  rsvd3;              /** Reserved hardware space */
    uint32_t  PAR_ECC_CTRL;             /** Multi-buffer RAM Uncorrectable Parity Error Control */
    uint32_t  UERRSTAT;             /** Multi-buffer RAM Uncorrectable Parity Error Status */
    uint32_t  UERRADDRRX;           /** RXRAM Uncorrectable Parity Error Address */
    uint32_t  UERRADDRTX;           /** TXRAM Uncorrectable Parity Error Address */
    uint32_t  RXOVRN_BUF_ADDR;      /** RXRAM Overrun Buffer Address */
    uint32_t  IOLPKTSTCR;           /** IO loopback */
    uint32_t  EXT_PRESCALE[2];        /** SPI Extended Prescale Register 1*/
    uint32_t  ECCDIAG_CTRL;         /** ECC Diagnostic Control register*/
    uint32_t  ECCDIAG_STAT;         /** ECC Diagnostic Status register*/
    uint32_t  SBERRADDR1;           /** Single Bit Error Address Register - RXRAM */
    uint8_t   rsvd4[6];             /** Reserved hardware space */
    uint32_t  SBERRADDR0;           /** Single Bit Error Address Register - TXRAM*/

} mibspiRegDefs_t;
// Set up the base address for the control registers for MibSPI1 through MibSPI5
#define MIBSPI1 ((mibspiRegDefs_t *)0xFFF7F400U)
#define MIBSPI2 ((mibspiRegDefs_t *)0xFFF7F600U)
#define MIBSPI3 ((mibspiRegDefs_t *)0xFFF7F800U)
#define MIBSPI4 ((mibspiRegDefs_t *)0xFFF7FA00U)
#define MIBSPI5 ((mibspiRegDefs_t *)0xFFF7FC00U)

/**
 * Real Time Interrupt (RTI) peripheral registers
 * For more info see page 575 of the technical reference manual
 */
typedef volatile struct rtiRegDefs {
	uint32_t GCTRL;	/**	Global control register; Offset 0x00	*/
	uint32_t TBCTRL;	/**	Timebase control register; Offset 0x04	*/
	uint32_t CAPCTRL;	/**	Capture control register; Offset 0x08	*/
	uint32_t COMPCTRL;	/**	Compare control register; Offset 0x0C	*/
	uint32_t FRC0;	/**	Free running counter 0 register; Offset 0x10	*/
	uint32_t UC0;	/**	Up counter 0 register; Offset 0x14	*/
	uint32_t CPUC0;	/**	Compare up counter 0 register; Offset 0x18	*/
	uint32_t rsvd1;	/**	Reserved memory space; Offset 0x1C	*/
	uint32_t CAFRC0;	/**	Capture free running counter 0 register; Offset 0x20	*/
	uint32_t CAUC0;	/**	Capture up counter 0 register; Offset 0x24	*/
	uint32_t rsvd2[2];	/**	Reserved memory space; Offset 0x28	*/
	uint32_t FRC1;	/**	Free running counter 1; Offset 0x30	*/
	uint32_t UC1;	/**	Up counter 1 register; Offset 0x34	*/
	uint32_t CPUC1;	/**	Compare up counter 0 register; Offset 0x38	*/
	uint32_t rsvd3;	/**	Reserved memory space; Offset 0x3C	*/
	uint32_t CAFRC1;	/**	Capture free running counter 1 register; Offset 0x40	*/
	uint32_t CAUC1;	/**	Capture up counter 1 register; Offset 0x44	*/
	uint32_t rsvd4[2];	/**	Resverved memory space; Offset 0x48	*/
	struct {	/**	Offset 0x50	*/
		uint32_t COMP;	/**	Compare register	*/
		uint32_t UDCP;	/**	Update compare register	*/
	} CMP[4];
	uint32_t TBLCOMP;	/**	Timebase low compare register; Offset 0x70	*/
	uint32_t TBHCOMP;	/**	Timebase high compare register; Offset 0x74	*/
	uint32_t rsvd5[2];	/**	Reserved memory space; Offset 0x78	*/
	uint32_t SETINTENA;	/**	Set interrupt enable register; Offset 0x80	*/
	uint32_t CLEARINTENA;	/**	Clear interrupt enable register; Offset 0x84	*/
	uint32_t INTFLAG;	/**	Interrupt flag register; Offset 0x88	*/
	uint32_t rsvd6;	/**	Reserved memory space; Offset 0x8C	*/
	uint32_t DWDCTRL;	/**	Digital watchdog control register; Offset 0x90	*/
	uint32_t DWDPRLD;	/**	Digital watchdog preload register; Offset 0x94	*/
	uint32_t WDSTATUS;	/**	Watchdog status register; Offset 0x98	*/
	uint32_t WDKEY;	/**	Watchdog key register; Offset 0x9C	*/
	uint32_t DWDCNTR;	/**	Digital watchdog down counter register; Offset 0xA0	*/
	uint32_t WWDRXNCTRL;	/**	Digital windowed watchdog reaction control register; Offset 0xA4	*/
	uint32_t WWDSIZECTRL;	/**	Digital windowed watchdog window size control register; Offset 0xA8	*/
	uint32_t INTCLRENABLE;	/**	Compare interrupt clear enable register; Offset 0xAC	*/
	uint32_t COMPCLR[4];	/**	Compare clear register for compare0 to compare3; Offset 0xB0	*/
} rtiRegDefs_t;
// Setup the base address in memory for the control registers
#define RTIREG ((rtiRegDefs_t *) 0xFFFFFC00)

/**
 * Control register for I2C
 */
typedef volatile struct i2CRegDefs {
	uint32_t OAR;	/** Own Address Register; Offset 0x00	*/
	uint32_t IMR;	/**	Interrupt Mask Register; Offset 0x04	*/
	uint32_t STR;	/**	Status Register; Offset 0x08	*/
	uint32_t CKL;	/**	Clock Divider Low Register; Offset 0x0C	*/
	uint32_t CKH;	/**	Clock Divider High Register; Offset 0x10	*/
	uint32_t CNT;	/**	Data Count Register; Offset 0x14	*/
	uint32_t DRR;	/**	Data Receive Register; Offset 0x18	*/
	uint32_t SAR;	/**	Slave Address Register; Offset 0x1C	*/
	uint32_t DXR;	/**	Data Transmit Register; Offset 0x20	*/
	uint32_t MDR;	/** Mode Register; Offset 0x24	*/
	uint32_t IVR;	/**	Interrupt Vector Register; Offset 0x28	*/
	uint32_t EMDR;	/**	Extended Mode Register; Offset 0x2C	*/
	uint32_t PSC;	/** Prescale Register; Offset 0x30	*/
	uint32_t PID[2];	/** Peripheral ID Registers; Offset 0x34	*/
	uint32_t DMACR;	/**	DMA Control Register; Offset 0x3C	*/
	uint32_t rsvd1[2];	/** Reserved Address; Offset 0x40	*/
	uint32_t PFNC;	/**	Pin Function Register; Offset 0x48	*/
	uint32_t DIR;	/** Pin Direction Register; Offset 0x4C	*/
	uint32_t DIN;	/**	Data Input Register; Offset 0x50	*/
	uint32_t DOUT;	/** Data Output Register; Offset 0x54	*/
	uint32_t DSET;	/** Data Set Register; Offset 0x58	*/
	uint32_t DCLR;	/** Data Clear Register; Offset 0x5C	*/
	uint32_t PDR;	/** Pin Open Drain Register; Offset 0x60	*/
	uint32_t PDIS;	/** Pull Disable Register; Offset 0x64	*/
	uint32_t PSEL;	/**	Pull Select Register; Offset 0x68	*/
	uint32_t SRS;	/** Pins Slew Rate Select Register; 0x6C	*/
} i2cRegDefs_t;
// Define the base address for the control registers for I2C1 and I2C2
#define I2C1 ((i2cRegDefs_t *) 0xFFF7D400)
#define I2C2 ((i2cRegDefs_t *) 0xFFF7D500)

/**
 * Memory Protection Unit (MPU)
 */
typedef volatile struct nmpuRegDefs {
	uint32_t REV;	/**	MPU revision ID; Offset 0x00	*/
	uint32_t LOCK;	/**	Lock register; Offset 0x04	*/
	uint32_t DIAGCTRL;	/**	Diagnostics control; Offset 0x08	*/
	uint32_t DIAGADDR;	/**	Diagnostic address register; Offset 0x0C	*/
	uint32_t ERRSTAT;	/**	Error status; Offset 0x10	*/
	uint32_t ERRADDR;	/**	Error address; Offset 0x14	*/
	uint32_t IAM;	/**	Input address mask;	Offset 0x18	*/
	uint32_t rsvd1;	/**	Reserved address space; Offset 0x1C	*/
	uint32_t CTRL[2];	/**	Control registers 1 and 2; Offset 0x20	*/
	uint32_t rsvd2;	/**	Reserved address space; Offset 0x28	*/
	uint32_t TYPE;	/**	Type register; Offset 0x2C	*/
	uint32_t REGBASE;	/** Region base address; Offset 0x30	*/
	uint32_t REGSENA;	/**	Region size and enable; Offset 0x34	*/
	uint32_t REGACR;	/**	Region access control; Offset 0x38	*/
	uint32_t REGNUM;	/**	Region number; Offset 0x3C	*/
	
} nmpuRegDefs_t;
// Define the base address for the control registers
#define NMPUDMA ((nmpuRegDefs_t *) 0xFFFF1A00)
#define NMPUSSCR ((nmpuRegDefs_t *) 0xFFFF1800)
#define NMPUCPGMAC ((nmpuRegDefs_t *) 0xFCFF1800)




#endif
 
 /**
  *
  * USEFUL STUFFS!
  *
  * Declaring register names and addresses: http://www.embedded.com/electronics-blogs/programming-pointers/4025002/Mapping-memory
  * Helps to make structs a bit more clear: http://stackoverflow.com/questions/1675351/typedef-struct-vs-struct-definitions
  * 
  */
