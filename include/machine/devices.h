#ifndef _MACHINE_DEVICES_H_
#define _MACHINE_DEVICES_H_

#include <machine/types.h>

#include <machine/mmu.h>
#include <machine/dma.h>

extern volatile u16 STATUS_DISP;

extern volatile u8  UART0_DATA;
extern volatile u8  UART0_CNTR;

extern volatile u16 TIMER_CNTR;

extern volatile u16 DMA_RAM_ADDR;
extern volatile u16 DMA_SECT_NUM;
extern volatile u16 DMA_CNTR;

extern volatile u16 MMU_EXC_REG;
extern volatile u16 MMU_CTX_REG;

extern volatile mmu_table_t MMU_TABLE;


#endif /* _MACHINE_DEVICES_H_ */
