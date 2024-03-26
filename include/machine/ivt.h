#ifndef _MACHINE_IVT_H_
#define _MACHINE_IVT_H_

#include <machine/status.h>

#define IVT_ENTRIES 64

#define IVT_STARTUP                 0x00
#define IVT_UNALIGNED_SP            0x01
#define IVT_UNALIGNED_PC            0x02
#define IVT_INVALID_INST            0x03
#define IVT_DOUBLE_FALUT            0x04
#define IVT_PRIVELEGE_VIOLATION     0x05
#define IVT_SYSCALL                 0x07
#define IVT_MMU_WRITE_PROT          0x08
#define IVT_MMU_LENGTH_VIOLATION    0x09
#define IVT_MMU_PRESENCE_VILOATION  0x0A
#define IVT_BUS_PROT                0x0B
#define IVT_DMA_INTERRUPT           0x10
#define IVT_TIMER_INTERRUPT         0x11
#define IVT_UART0_INTERRUPT         0x14

typedef void (*isr_t)();

typedef struct ivt_entry_s {
    isr_t handler;
    ps_flags_t flags;
} ivt_entry_t;

#endif /* _MACHINE_IVT_H_ */
