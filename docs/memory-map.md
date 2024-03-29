# Memory map for Coconut-16

## Physical memory: 00000-FFFFF

+ **00000-000FF** - IVT
+ **00100-FDFFF** - Main memory
+ **FE000-FEFFF** - Startup ROM
+ **FF000-FFFFF** - Device area

### 0-th context mapping
+ 0000-0FFF -> FE000-FEFFF - ROM
+ 0000-0FFF -> FD000-FDFFF - RAM
+ E000-EFFF -> 00000-000FF - RAM to global IVT


## Device area: 000-FFF

### IO F00-F4F

#### Status display
+ **F40** - DR

### Terminals F50-F5F

#### UART (or multiple)
+ **F50** - Data register
+ **F51** - CR

### System devices 

#### Timer
+ **F58** - CR

#### RTC
+ **F66** - CR
  

### Memory control F70 - FFF

#### DMA
+ **F70** - RAM address
+ **F72** - Sector #
+ **F76** - Control register

#### MMU
+ **F7C** - Exception
+ **F7E** - Context
+ **F80-FFF** - Table

#### MMU Table 
+ **F80-FBF** - Flags
+ **Flags** - PWIR RRRR LLLL LLLL
    + **P** - Presence
    + **W** - Write protect
    + **I** - Inverse
    + **R** - Reserved
    + **L** - Length

+ **FC0-FFF** - Offsets
