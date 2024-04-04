#include <machine/devices.h>
#include "uart.h"

void send_string_to_uart(char* string) {
    char c;
    while ((c = *(string++)) != '\0')
        UART0_DATA = c;
}

void send_bytes_to_uart(char* bytes, int count) {
    for (int i = 0; i < count; i++) {
        UART0_DATA = bytes[i];
    }
}

int read_from_uart(char* buf, int max_count) {
    if (!(UART0_CNTR & UART_CNTR_CON)) {
        return -1;
    }
    int count;
    i16 t;
    for (count = 0; count < max_count; count++) {
        t = UART0;
        if (!(t & UART_CNTR16_DT)) {
            return count;
        }
        buf[count] = (char) t;
    }
    return count;
}