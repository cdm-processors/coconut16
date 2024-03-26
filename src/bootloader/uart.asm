rsect uart

# Sends a zero-terminated string
# that is stored in program memory to UART
# 
# Args:
#   r0 - UART data register address
#   r1 - pointer to string
send_const_str_to_uart>
    do
        lcb r1, r2
        stb r0, r2
        inc r1
        tst r2
    until z

    rts

# Sends some number of bytes
# that are stored in program memory to UART
# 
# Args:
#   r0 - UART data register address
#   r1 - pointer to data
#   r2 - number of bytes
send_const_bytes_to_uart>
    do
        lcb r1, r3
        stb r0, r3
        inc r1
        dec r2
    until z

    rts

end.
