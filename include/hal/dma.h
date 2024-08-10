#ifndef COCONUT16_DMA_H
#define COCONUT16_DMA_H

#include <machine/types.h>
#include <machine/dma.h>

/**
 * Initiates a DMA transfer operation.
 *
 * @param ram_addr address in RAM
 * @param sect_num sector number
 * @param flags DMA flags
 */
void dma_transfer(u16 ram_addr, u16 sect_num, u16 flags);

/**
 * Reads status of DMA.
 *
 * @return flags of DMA
 */
u16 dma_get_flags();

#endif //COCONUT16_DMA_H
