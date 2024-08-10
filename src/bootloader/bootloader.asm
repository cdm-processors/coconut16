rsect bootloader_start
__bootloader_start_c: ext

MMU_CTX_REG: ext
MMU_TABLE: ext

start>

	ldi	r0, MMU_CTX_REG
	ldi	r1, 0
	stw	r0, r1

	ldi	r0, MMU_TABLE+32
	ldi	r1, 0x8000
	stw	r0, r1
	ldi	r0, MMU_TABLE+96
	ldi r1, 0xfd00
	stw r0, r1

	ldi r0, 0x1000
	stsp r0

	jsr __bootloader_start_c
	
	halt

rsect timer_handler

timer_handler>
	rti

rsect syscall_handler

syscall_handler>
	rti

rsect dma_handler
dma_transfer_done: ext

dma_handler>
	rti

end.
