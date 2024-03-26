#include <machine/intrinsic.h>

#include <compiler.h>

extern __program u8 num_to_ascii_hex_table[];

u8 __to_ascii_hex(u8 value) {
    return __lcb(&num_to_ascii_hex_table[value & 0xf]);
}

void to_ascii_u16(int value, char* buffer) {
    for (int i = 3; i >= 0; --i) {
        buffer[i] = __to_ascii_hex(value);
        value = __ror_4(value);
    }
}
