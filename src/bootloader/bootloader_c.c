#include <machine/devices.h>
#include <machine/intrinsic.h>
#include <machine/ivt.h>
#include <machine/types.h>
#include <machine/zero_context.h>

// + Setup stack (done in assembly)
// + Fill global IVT
// + Map memory for boot image
// + Load boot.img from flash drive to RAM
// 	(For now, just load first sector)
// + Jump to boot image code

void panic_handler();
void timer_handler();
void syscall_handler();
void dma_handler();

static volatile ivt_entry_t* GLOBAL_IVT = (ivt_entry_t*)GLOBAL_IVT_START;

static void fill_global_ivt(isr_t handler, ps_flags_t flags) {
    for (u16 i = 0; i < IVT_ENTRIES; ++i) {
        GLOBAL_IVT[i].flags = flags;
        GLOBAL_IVT[i].handler = handler;
    }
}

static void set_global_ivt(usize num, isr_t handler, ps_flags_t flags) {
    GLOBAL_IVT[num].flags = flags;
    GLOBAL_IVT[num].handler = handler;
}

static void map_segment(usize ctx_num, usize seg_num, mmu_seginfo_t seg_info,
                 mmu_segoff_t seg_off) {
    // u16 last_ps = __ldps();
    // __di();

    MMU_CTX_REG = ctx_num;
    MMU_TABLE.seg_info[seg_num] = seg_info;
    MMU_TABLE.seg_off[seg_num] = seg_off;

    // if (last_ps & PS_INT_EN)
    //     __ei();
}

static void dma_transfer(u16 ram_addr, u16 sect_num, u16 flags) {
    DMA_RAM_ADDR = ram_addr;
    DMA_SECT_NUM = sect_num;
    DMA_CNTR = flags;
}

void __bootloader_start_c() {
    __ei();

    dma_transfer(0x0100, 0x0000, DMA_READ | DMA_RUNNING);

    fill_global_ivt(panic_handler, PS_IO_HEADER | PS_CTX_NUM(0));

    set_global_ivt(IVT_TIMER_INTERRUPT, timer_handler, 0);
    set_global_ivt(IVT_DMA_INTERRUPT, dma_handler, 0);
    set_global_ivt(IVT_SYSCALL, syscall_handler, PS_IO_HEADER | PS_CTX_NUM(0));

    map_segment(1, 0, MMU_PRESENCE | MMU_SEG_LEN(0x200), 0x0100);
    map_segment(1, 16, MMU_PRESENCE | MMU_SEG_LEN(0), 0x0200);

    if (DMA_CNTR & DMA_RUNNING) 
        __wait();

    __di();

    __rti(0x0000, PS_IO_HEADER | PS_CTX_NUM(1));
}
