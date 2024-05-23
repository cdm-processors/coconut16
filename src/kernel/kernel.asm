asect 0
STATUS_DISP: ext
    kernel_main: ext
    ldi r0, 0xf000
    stsp r0

    jsr kernel_main

    halt

rsect run_dma
run_dma>
    int 0x10 # IVT_DMA_INTERRUPT
    rts

asect 0x1fe
ds 2

asect 0x3fe
ds 2

asect 0x5fe
ds 2

end.