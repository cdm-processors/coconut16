#ifndef _MACHINE_IVT_H_
#define _MACHINE_IVT_H_

#include <machine/status.h>

#define IVT_ENTRIES 64

typedef struct ivt_entry_s {
    void* handler_addr;
    ps_flags_t flags;
} ivt_entry_t;

extern volatile ivt_entry_t IVT[IVT_ENTRIES];

#endif /* _MACHINE_IVT_H_ */
