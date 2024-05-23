#include <compiler.h>
#include <machine/devices.h>
#include <machine/ivt.h>

#include "machine/intrinsic.h"
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

    while (dma_current_task != -1) {
        __wait();      
    }
    // TIMER_CNTR = 0x2;
    STATUS_DISP = 0xb33f;
    STATUS_DISP = 0xb331;
    STATUS_DISP = 0xb332;
    STATUS_DISP = 0xd0Ae;
}