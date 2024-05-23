#include <machine/intrinsic.h>
#include <compiler.h>

void send_bytes_to_uart_sc(char* bytes, int count) {
    __syscall(0, bytes, count);
}

int read_from_uart_sc(char* bytes, int max_count) {
    int ret;
    __syscall(1, bytes, max_count, &ret);
    return ret;
}
