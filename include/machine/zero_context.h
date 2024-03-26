#ifndef _MACHINE_ZERO_CONTEXT_H_
#define _MACHINE_ZERO_CONTEXT_H_

#define ROM_START               0x0000
#define ROM_LENGTH              0x1000

#define RAM_START               0x0000
#define RAM_LENGTH              0x1000

#define DEVICES_START           0xf000
#define DEVICES_LENGTH          0x1000

#define ZERO_CONTEXT_IVT_START  0x0000
#define ZERO_CONTEXT_IVT_LENGTH 0x0100

#define GLOBAL_IVT_START        0xe000
#define GLOBAL_IVT_LEN          0x0100

#endif /* _MACHINE_ZERO_CONTEXT_H_ */
