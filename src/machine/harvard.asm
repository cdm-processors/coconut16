rsect harvard

# Copies bytes from program memory to data memory.
# 
# Args:
#   r0 - destination address in data memory
#   r1 - source address in program memory
#   r2 - count of bytes
copy_from_prog_mem>
    # push r0

    do
        lcb r1, r3
        stb r0, r3
        inc r0
        inc r1
        dec r2
    until z

    # pop r0
    rts

end.
