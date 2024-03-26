rsect ascii
num_to_ascii_hex_table: ext

# Converts least significabt 4 bits from r0
# to hex ascii representation.
# 
# Args:
#   r0 - number
#
# Rets:
#   r0 - ascii code of number
to_ascii_hex>
    ldi r1, 0xf
    and r0, r1, r0  # Leave only 4 lower bits

    ldi r1, num_to_ascii_hex_table
    lcb r1, r0, r0  # Translate to ascii code 
                    # using table
    
    rts

# TODO
from_ascii_hex>

rsect ascii_hex_tables

num_to_ascii_hex_table>
    db "0123456789abcdef"

end.
