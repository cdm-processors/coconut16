#include <machine/intrinsic.h>
#include <machine/devices.h>
#include "syscall.h"

__noreturn int main() {
    char text[10];
    while (1) {
        int read = read_from_uart_sc(text, sizeof text);
        if (read) {
            send_bytes_to_uart_sc(text, read);
        }
    }
    __halt();
}
