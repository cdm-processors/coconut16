#ifndef COCONUT16_IVT_H
#define COCONUT16_IVT_H

#include "../machine/ivt.h"

/**
 * Fills global IVT with given values.
 *
 * @param handler default handler
 * @param flags default flags
 */
void fill_global_ivt(isr_t handler, ps_flags_t flags);

/**
 * Sets global IVT entry to given values.
 *
 * @param num entry number
 * @param handler interrupt handler
 * @param flags PS flags
 */
void set_global_ivt(usize num, isr_t handler, ps_flags_t flags);

/**
 * Gets handler of IVT entry.
 *
 * @param num entry number
 * @return handler
 */
isr_t get_global_ivt_handler(usize num);

/**
 * Gets flags of IVT entry.
 *
 * @param num entry number
 * @return flags
 */
ps_flags_t get_global_ivt_flags(usize num);

/**
 * Gets IVT entry
 *
 * @param num entry number
 * @param entry pointer to entry to write
 */
void get_global_ivt_entry(usize num, ivt_entry_t* entry);

#endif //COCONUT16_IVT_H
