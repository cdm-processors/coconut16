#include <machine/intrinsic.h>
#include <compiler.h>

void send_bytes_to_uart_sc(char* bytes, int count) {
    __syscall(0, bytes, count);
}
