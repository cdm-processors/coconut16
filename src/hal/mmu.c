#include <hal/mmu.h>

#include <machine/devices.h>
#include <machine/intrinsic.h>
#include <machine/status.h>

void mmu_map_segment(usize ctx_num, usize seg_num, mmu_seginfo_t seg_info,
                     mmu_segoff_t seg_off) {
    MMU_CTX_REG = ctx_num;
    MMU_TABLE.seg_info[seg_num] = seg_info;
    MMU_TABLE.seg_off[seg_num] = seg_off;
}

void mmu_map_segment_blocking(usize ctx_num, usize seg_num, mmu_seginfo_t seg_info,
                              mmu_segoff_t seg_off) {
    u16 last_ps = __ldps();
    __di();

    mmu_map_segment(ctx_num, seg_num, seg_info, seg_off);

    if (last_ps & PS_INT_EN)
        __ei();
}
