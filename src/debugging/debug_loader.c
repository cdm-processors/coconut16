#include <machine/devices.h>
#include <machine/intrinsic.h>
#include <machine/status.h>
#include "../demo_program/uart.h"
#include "memory_util.h"

int main();
// __isr syscall_handler(u16, u16, u16, u16);
__isr void syscall_handler();

void debug_loader() {
    set_global_ivt(7, syscall_handler, PS_IO_HEADER | PS_CTX_NUM(1));
    __rti((u16) main, PS_IO_HEADER | PS_CTX_NUM(2));
}
