asect 0
STATUS_DISP: ext
    kernel_start: ext
    ldi r0, 0xf000
    stsp r0

    jsr kernel_start

    halt
end.