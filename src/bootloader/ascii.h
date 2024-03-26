#ifndef _BOOTLOADER_ASCII_H_
#define _BOOTLOADER_ASCII_H_

#include <machine/types.h>

/*
    Converts least sinificabt 4 bits of value
    to hex ascii representation.
*/
char to_ascii_hex(u8 value);

/*
    Writes hex ascii representation of value
    to buffer.
*/
void to_ascii_u16(u16 value, char* buffer);

#endif /* _BOOTLOADER_ASCII_H_ */
