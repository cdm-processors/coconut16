#include "types.h"
#define UART_CNTR16_DT (1 << 15)
#define UART_CNTR16_CON (1 << 14)
#define UART_CNTR16_INT_EN (1 << 13)

#define UART_CNTR_DT (1 << 7)
#define UART_CNTR_CON (1 << 6)
#define UART_CNTR_INT_EN (1 << 6)

typedef struct uart_s {
    u8  cntr;
    u8  data;
} uart_t;