#include <machine/intrinsic.h>
#include <machine/devices.h>
#include "uart.h"
#include "syscall.h"

__noreturn int main() {
    char text[10] = "Hello\r\n";
    send_bytes_to_uart_sc(text, 7);

    // text[9] = '\0';
    // while (UART0_CNTR & UART_CNTR_CON) {
    //     int read = read_from_uart(text, sizeof text);
    //     if (read) {
    //         send_bytes_to_uart(text, read);
    //     }
    // }
    __halt();
}