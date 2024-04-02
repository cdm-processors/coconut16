#include <machine/devices.h>
#include <machine/intrinsic.h>
#include <machine/ivt.h>
#include <machine/types.h>
#include <machine/zero_context.h>
#include "memory_util.h"

// + Setup stack (done in assembly)
// + Fill global IVT
// + Map memory for boot image
// + Load boot.img from flash drive to RAM
// 	(For now, just load first sector)
// + Jump to boot image code

void panic_handler();
void timer_handler();
void syscall_handler();
void dma_handler();

void __bootloader_start_c() {
    __ei();

    dma_transfer(0x0100, 0x0000, DMA_READ | DMA_RUNNING);

    fill_global_ivt(panic_handler, PS_IO_HEADER | PS_CTX_NUM(0));

    set_global_ivt(IVT_TIMER_INTERRUPT, timer_handler, 0);
    set_global_ivt(IVT_DMA_INTERRUPT, dma_handler, 0);
    set_global_ivt(IVT_SYSCALL, syscall_handler, PS_IO_HEADER | PS_CTX_NUM(0));

    map_segment(1, 0, MMU_PRESENCE | MMU_SEG_LEN(0x200), 0x0100);
    map_segment(1, 16, MMU_PRESENCE | MMU_SEG_LEN(0), 0x0200);

    if (DMA_CNTR & DMA_RUNNING) 
        __wait();

    __di();

    __rti(0x0000, PS_IO_HEADER | PS_CTX_NUM(1));
}
