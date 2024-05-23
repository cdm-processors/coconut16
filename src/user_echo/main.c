#include <machine/intrinsic.h>
#include <machine/devices.h>
#include "syscall.h"

int main() {
    char text[10];
    while (1) {
        int read = read_from_uart_sc(text, sizeof text);
        if (read == -1) {
            return 0;
        }
        if (read) {
            send_bytes_to_uart_sc(text, read);
        }
    }
}
