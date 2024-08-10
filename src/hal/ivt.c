#include <hal/ivt.h>
#include <machine/types.h>
#include <machine/zero_context.h>

static volatile ivt_entry_t* GLOBAL_IVT = (ivt_entry_t*)GLOBAL_IVT_START;

void fill_global_ivt(isr_t handler, ps_flags_t flags) {
    for (u16 i = 0; i < IVT_ENTRIES; ++i) {
        set_global_ivt(i, handler, flags);
    }
}

void set_global_ivt(usize num, isr_t handler, ps_flags_t flags) {
    GLOBAL_IVT[num].flags = flags;
    GLOBAL_IVT[num].handler = handler;
}

isr_t get_global_ivt_handler(usize num) {
    return GLOBAL_IVT[num].handler;
}

ps_flags_t get_global_ivt_flags(usize num) {
    return GLOBAL_IVT[num].flags;
}

void get_global_ivt_entry(usize num, ivt_entry_t* entry) {
    entry->flags = GLOBAL_IVT[num].flags;
    entry->handler = GLOBAL_IVT[num].handler;
}
