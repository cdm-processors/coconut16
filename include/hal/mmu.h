#ifndef COCONUT16_MMU_H
#define COCONUT16_MMU_H

#include <machine/mmu.h>

/**
 * Populates segment descriptor in MMU with given values.
 *
 * @param ctx_num context number
 * @param seg_num segment number
 * @param seg_info segment flags and length
 * @param seg_off segment offset
 */
void mmu_map_segment(usize ctx_num, usize seg_num, mmu_seginfo_t seg_info,
                     mmu_segoff_t seg_off);

/**
 * Blocking version of mmu_map_segment
 *
 * @param ctx_num context number
 * @param seg_num segment number
 * @param seg_info segment flags and length
 * @param seg_off segment offset
 */
void mmu_map_segment_blocking(usize ctx_num, usize seg_num, mmu_seginfo_t seg_info,
                     mmu_segoff_t seg_off);

#endif //COCONUT16_MMU_H
