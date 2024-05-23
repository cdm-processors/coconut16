#include <machine/devices.h>
#include <machine/intrinsic.h>
#include <machine/ivt.h>
#include <machine/types.h>
#include <machine/zero_context.h>

#include "machine/mmu.h"
#include "machine/status.h"
#include "memory_util.h"

// + Setup stack (done in assembly)
// + Fill global IVT
// + Map memory for boot image
// + Load boot.img from flash drive to RAM
// 	(For now, just load first sector)
// + Jump to boot image code

__isr void panic_handler();
__isr void timer_handler();
__isr void syscall_handler();
__isr void dma_handler();

void __bootloader_start_c() {
    __ei();

    dma_transfer(0x1000, 0x0000, DMA_READ | DMA_RUNNING);
    fill_global_ivt(panic_handler, PS_IO_HEADER | PS_CTX_NUM(0));

    set_global_ivt(IVT_TIMER_INTERRUPT, timer_handler, 0);
    set_global_ivt(IVT_DMA_INTERRUPT, dma_handler, 0);
    set_global_ivt(IVT_SYSCALL, syscall_handler, PS_IO_HEADER | PS_CTX_NUM(0));

    map_segment(1, 0, MMU_PRESENCE | MMU_SEG_LEN(0), 0x1000);
    map_segment(1, 30, MMU_PRESENCE | MMU_SEG_LEN(0) | MMU_INVERSE, 0x9f00);

    map_segment(1, 16, MMU_PRESENCE | MMU_SEG_LEN(0), 0);  // IVT

    if (DMA_CNTR & DMA_RUNNING) __wait();

    dma_transfer(0x1020, 0x0001, DMA_READ | DMA_RUNNING);
    map_segment(1, 1, MMU_PRESENCE | MMU_SEG_LEN(0), 0x1020);
    
    if (DMA_CNTR & DMA_RUNNING) __wait();

    __di();

    __stssp(0);
    __rti(0x0000, PS_IO_HEADER | PS_CTX_NUM(1) | PS_INT_EN);
}
