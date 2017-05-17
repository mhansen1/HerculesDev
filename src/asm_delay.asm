	.def _delay_asm
	.text
	.align 4
	.armfunc _delay_asm
	.arm
	
_delay_asm: .asmfunc
	sub		sp, sp, #8			;	Move the stack pointer down by 8 bytes
	str		r12, [sp]			;	Store the contents of R12 into the stack, just in case
	mov		r12, #0				;	Store a 0 into R12 
$dlylp								;	Delay loop label
	cmp		r12, r0				;	Compare the current value of i to argument register
	add		r12, r12, #1		;	Add one to i
	blo		$dlylp				;	Branch backwards to label 1 if i is lower than argument register
	mov		r12, #0				;	Clear R12 
	ldr		r12, [sp]			;	Restore R12
	add		sp, sp, #8			;	Restore the stack pointer
	bx		lr						;	Branch back up to main functionality

	.endasmfunc
