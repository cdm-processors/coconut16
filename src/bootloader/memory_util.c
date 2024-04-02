#include <machine/devices.h>
#include <machine/ivt.h>
#include <machine/zero_context.h>

static volatile ivt_entry_t* GLOBAL_IVT = (ivt_entry_t*)GLOBAL_IVT_START;

void fill_global_ivt(isr_t handler, ps_flags_t flags) {
    for (u16 i = 0; i < IVT_ENTRIES; ++i) {
        GLOBAL_IVT[i].flags = flags;
        GLOBAL_IVT[i].handler = handler;
    }
}

void set_global_ivt(usize num, isr_t handler, ps_flags_t flags) {
    GLOBAL_IVT[num].flags = flags;
    GLOBAL_IVT[num].handler = handler;
}

void map_segment(usize ctx_num, usize seg_num, mmu_seginfo_t seg_info,
                 mmu_segoff_t seg_off) {
    // u16 last_ps = __ldps();
    // __di();

    MMU_CTX_REG = ctx_num;
    MMU_TABLE.seg_info[seg_num] = seg_info;
    MMU_TABLE.seg_off[seg_num] = seg_off;

    // if (last_ps & PS_INT_EN)
    //     __ei();
}

void dma_transfer(u16 ram_addr, u16 sect_num, u16 flags) {
    DMA_RAM_ADDR = ram_addr;
    DMA_SECT_NUM = sect_num;
    DMA_CNTR = flags;
}