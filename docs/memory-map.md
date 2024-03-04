# Memory map for Coconut-16

## Physical memory: 00000-FFFFF

+ **00000-000FF** - IVT
+ **00100-FDFFF** - Main memory
+ **FE000-FEFFF** - Startup ROM
+ **FF000-FFFFF** - Device area

### 0-th context mapping
+ FE000-FEFFF - ROM
+ FD000-FDFFF - RAM


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
+ **F60** - CR

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