#include <machine/devices.h>
#include <machine/intrinsic.h>
#include <machine/status.h>
#include "../bootloader/uart.h"
#include "../demo_program/uart.h"

int main();

void debug_loader() {
    __rti((u16) main, PS_IO_HEADER | PS_CTX_NUM(2));
}
