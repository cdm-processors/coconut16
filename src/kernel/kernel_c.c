#include <compiler.h>
#include <machine/devices.h>
#include <machine/ivt.h>

#include "machine/intrinsic.h"
#include "machine/status.h"
#include "memory_util.h"

void run_dma();

volatile int dma_current_task;

__isr void dma_handler() {
    switch (dma_current_task) {
        case 0:
            dma_transfer(0x2000, 0x0080, DMA_READ | DMA_RUNNING);
            dma_current_task++;
            return;
        default:
            dma_current_task = -1;
            return;
    }
}

void kernel_main() {
    STATUS_DISP = 0xbeef;
    set_global_ivt(IVT_DMA_INTERRUPT, dma_handler,
                   PS_IO_HEADER | PS_CTX_NUM(1));
    dma_current_task = 0;  // Compiler doesn't init global variables
    run_dma();

    map_segment(2, 0, MMU_PRESENCE | MMU_SEG_LEN(0), 0x2000);
    map_segment(2, 03, MMU_PRESENCE | MMU_SEG_LEN(0) | MMU_INVERSE, 0xaf00);

    while (dma_current_task != -1) {
        __wait();      
    }


    __di();

    __stssp(0);
    __rti(0x0000, PS_IO_HEADER | PS_CTX_NUM(2) | PS_INT_EN);
    

    // __stssp(0xf000);
    // __rti(0x0000, PS_CTX_NUM(2) | PS_INT_EN | PS_IO_HEADER);
}