#ifndef _MEMORY_UTIL_H_
#define _MEMORY_UTIL_H_

#include <machine/devices.h>
#include <machine/ivt.h>
#include <machine/zero_context.h>

void fill_global_ivt(isr_t handler, ps_flags_t flags);
void set_global_ivt(usize num, isr_t handler, ps_flags_t flags);
void map_segment(usize ctx_num, usize seg_num, mmu_seginfo_t seg_info,
                 mmu_segoff_t seg_off);
void dma_transfer(u16 ram_addr, u16 sect_num, u16 flags);

#endif // _MEMORY_UTIL_H_