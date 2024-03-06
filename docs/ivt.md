# Coconut-16 IVT

| Vector no. (hex) | Offset (hex) |                  Name                   |
|:----------------:|:------------:|:---------------------------------------:|
|        00        |      00      |              Startup/Reset              |
|        01        |      04      |              Unaligned SP               |
|        02        |      08      |              Unaligned PC               |
|        03        |      0C      |           Invalid instruction           |
|        04        |      10      |              Double fault               |
|        05        |      14      |           Privilege violation           |
|        06        |      18      |                Reserved                 |
|        07        |      1С      |                 Syscall                 |
|        08        |      20      |              Write protect              |
|        09        |      24      |            Offset violation             |
|        0A        |      28      |           Presence violation            |
|        0B        |      2С      |             Bus protection              |
|        0C        |      30      |                Reserved                 |
|        0D        |      34      |                Reserved                 |
|        0E        |      38      |                Reserved                 |
|        0F        |      3С      |                Reserved                 |
|        10        |      40      |              DMA interrupt              |
|        11        |      44      |             Timer interrupt             |
|        12        |      48      |                Reserved                 |
|        13        |      4С      |                Reserved                 |
|        14        |      50      |          UART 0 data interrupt          |
|        15        |      54      |                Reserved                 |
|        16        |      58      |                Reserved                 |
|        17        |      5С      |                Reserved                 |
|   ... <br> 3F    | ... <br> FC  | External interrupts <br> and exceptions |
