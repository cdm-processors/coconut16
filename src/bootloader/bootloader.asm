rsect bootloader_start
__bootloader_start_c: ext

start>

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
