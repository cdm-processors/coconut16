#ifndef _MACHINE_INTRINSIC_H_
#define _MACHINE_INTRINSIC_H_

#include <machine/types.h>

#include <compiler.h>

/*
    Halts the processor.
*/
__privileged __noreturn void __halt();

/*
    Executes `wait` instruction causing 
    processor to stop executing util 
    some interrupt comes.
*/
__privileged void __wait();

/*
    Rotates `value` 4 places right.
*/
u16 __ror_4(u16 value);

/*
    Loads word from program memory.
*/
u16 __lcw(__program u16* addr);

/*
    Loads unsigned byte from program memory.
*/
u8 __lcb(__program u8* addr);

/*
    Loads signed byte from program memory.
*/
i8 __lcsb(__program i8* addr);

#endif /* _MACHINE_INTRINSIC_H_ */
