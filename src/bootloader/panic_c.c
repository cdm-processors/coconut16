#include <machine/types.h>
#include <machine/devices.h>
#include <machine/intrinsic.h>

#include "ascii.h"
#include "uart.h"

__program char panic_string[] = "Bootloader panic :-(\n";
__program char system_halted_string[] = "System halted\n";

static void write_buffer_to_uart0(u8* buf, usize len) {
    for (int i = 0; i < len; ++i) {
        UART0_DATA = buf[i];
    }
}

void __bootloader_panic_c(u16* registers) {
    STATUS_DISP = 0xdead;

    UART0_DATA = '\n';
    send_const_str_to_uart(&UART0_DATA, panic_string);

    char buffer[] = "r$: $$$$ ";

    for (int i = 0; i < 8; ++i) {
        buffer[1] = to_ascii_hex(7 - i);
        to_ascii_u16(registers[i], &buffer[4]);
        write_buffer_to_uart0((u8*)buffer, sizeof(buffer));
    }
    UART0_DATA = '\n';

    buffer[0] = 'p';
    buffer[1] = 'c';
    to_ascii_u16(registers[8], &buffer[4]);
    write_buffer_to_uart0((u8*)buffer, sizeof(buffer));

    buffer[0] = 'p';
    buffer[1] = 's';
    to_ascii_u16(registers[9], &buffer[4]);
    write_buffer_to_uart0((u8*)buffer, sizeof(buffer));

    buffer[0] = 'p';
    buffer[1] = 's';
    to_ascii_u16(__ldps(), &buffer[4]);
    write_buffer_to_uart0((u8*)buffer, sizeof(buffer));

    buffer[0] = 's';
    buffer[1] = 'p';
    to_ascii_u16(__ldsp(), &buffer[4]);
    write_buffer_to_uart0((u8*)buffer, sizeof(buffer));

    
    buffer[0] = 's';
    buffer[1] = 'p';
    to_ascii_u16(__ldssp(), &buffer[4]);
    write_buffer_to_uart0((u8*)buffer, sizeof(buffer));

    UART0_DATA = '\n';
    send_const_str_to_uart(&UART0_DATA, system_halted_string);
}