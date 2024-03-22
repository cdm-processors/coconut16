#ifndef _MACHINE_MMU_H_
#define _MACHINE_MMU_H_

#include <machine/types.h>

#define MMU_PRESENCE    (1 << (15))
#define MMU_WR_PROT     (1 << (14))
#define MMU_INVERSE     (1 << (13))

#define MMU_SEG_LEN(n)  (n & 0xff)

#define CTX_SEGMENT_COUNT 32

typedef u16 mmu_seginfo_t;
typedef u16 mmu_segoff_t;

typedef struct mmu_table_s {
    mmu_seginfo_t seg_info[CTX_SEGMENT_COUNT];
    mmu_segoff_t  seg_off[CTX_SEGMENT_COUNT];
} mmu_table_t;

#endif /* _MACHINE_MMU_H_ */
