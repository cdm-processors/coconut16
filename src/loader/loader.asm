asect 0
STATUS_DISP: ext

loader_start>

    ldi r0, STATUS_DISP
    ldi r1, 0xbeef
    stw r0, r1

    halt

end.