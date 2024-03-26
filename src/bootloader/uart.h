#ifndef _BOOTLOADER_UART_H_
#define _BOOTLOADER_UART_H_

#include <machine/types.h>
#include <compiler.h>

/*
    Sends a zero-terminated string
    that is stored in program memory to UART
*/
void send_const_str_to_uart(__io u8* uart, __program char* str);

/*
    Sends some number of bytes
    that are stored in program memory to UART
*/
void send_const_bytes_to_uart(__io u8* uart, __program char* bytes, usize count);

#endif /* _BOOTLOADER_UART_H_ */
