macro pushall/0
    push r0
    push r1
    push r2
    push r3
    push r4
    push r5
    push r6
    push fp
mend

rsect panic_handler
__bootloader_panic_c: ext

panic_handler>
    ldi r0, 0x1000
	stsp r0
    pushall
    ldsp r0

    jsr __bootloader_panic_c

    halt

end.