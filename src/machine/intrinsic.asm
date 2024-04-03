rsect intrinsic

# Processor control
__halt>
    halt

__wait>
    wait
    rts

__ei>
    ei
    rts

__di>
    di
    rts

__rti>
    push r1
    push r0
    rti

# Arithmetic
__ror_4>
	ror r0, 4
	rts

# Memory
__lcw>
    lcw r0, r0
    rts

__lcb>
    lcb r0, r0
    rts

__lcsb>
    lcsb r0, r0
    rts

__lcw_off>
    lcw r0, r1, r0
    rts

__lcb_off>
    lcb r0, r1, r0
    rts

__lcsb_off>
    lcsb r0, r1, r0
    rts

# Specical registers
__ldps>
    ldps r0
    rts

__ldsp>
    ldsp r0
    add r0, 2
    rts

__stssp>
    stssp r0
    rts

__ldssp>
    ldssp r0
    rts

__syscall>
    syscall
    rts

end.
