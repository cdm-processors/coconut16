#ifndef _MACHINE_HARVARD_H_
#define _MACHINE_HARVARD_H_

#include <machine/types.h>

#include <compiler.h>

/*
    Copies bytes from program memory to data memory.

    @param dst destination address in data memory
    @param src source address in program memory
    @param count number of bytes
*/
void copy_from_prog_mem(void* dst, __program void* src, usize count);

#endif /* _MACHINE_HARVARD_H_ */
