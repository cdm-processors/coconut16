#ifndef _MACHINE_STATUS_H_
#define _MACHINE_STATUS_H_

#include <machine/types.h>

#define PS_INT_EN       (1 << (15))
#define PS_USER_MODE    (1 << (14))
#define PS_IO_HEADER    (1 << (13))

#define PS_CTX_NUM(n)   ((n & 0xff) << (4))

typedef u16 ps_flags_t;

#endif /* _MACHINE_STATUS_H_ */
