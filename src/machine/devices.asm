macro define_ext/2
    asect $2
    $1>
mend

define_ext STATUS_DISP,     0xff40

define_ext UART0_DATA,      0xff50
define_ext UART0_CNTR,      0xff51

define_ext TIMER_CNTR,      0xff58

define_ext DMA_RAM_ADDR,    0xff70
define_ext DMA_SECT_NUM,    0xff72
define_ext DMA_CNTR,        0xff76

define_ext MMU_EXC_REG,     0xff7c
define_ext MMU_CTX_REG,     0xff7e
define_ext MMU_TABLE,       0xff80
define_ext MMU_TB_FLAGS,    0xff80
define_ext MMU_TB_OFF,      0xffc0

end.
