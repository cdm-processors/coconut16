#include <machine/intrinsic.h>
#include "uart.h"

void panic_handler();

__isr void syscall_handler(u16 r0, u16 r1, u16 r2, u16 r3) {
    switch (r0) {
    case 0:
        send_bytes_to_uart((char *) r1, r2);
        break;
    case 1: {
        int *ptr = (int *)r3;
        *ptr = read_from_uart((char *) r1, r2);
    }
        break;
    default:
        panic_handler();
    }
}
