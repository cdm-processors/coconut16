#include <hal/dma.h>

#include <machine/devices.h>

void dma_transfer(u16 ram_addr, u16 sect_num, u16 flags) {
    DMA_RAM_ADDR = ram_addr;
    DMA_SECT_NUM = sect_num;
    DMA_CNTR = flags;
}

u16 dma_get_flags() {
    return DMA_CNTR;
}
