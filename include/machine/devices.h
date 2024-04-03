#ifndef _MACHINE_DEVICES_H_
#define _MACHINE_DEVICES_H_

#include <machine/types.h>

#include <machine/mmu.h>
#include <machine/dma.h>
#include <machine/uart.h>

#include <compiler.h>

extern __io u16 STATUS_DISP;

extern __io u16 UART0;
extern __io u8  UART0_DATA;
extern __io u8  UART0_CNTR;

extern __io u16 TIMER_CNTR;

extern __io u16 DMA_RAM_ADDR;
extern __io u16 DMA_SECT_NUM;
extern __io u16 DMA_CNTR;

extern __io u16 MMU_EXC_REG;
extern __io u16 MMU_CTX_REG;

extern __io mmu_table_t MMU_TABLE;


#endif /* _MACHINE_DEVICES_H_ */
