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
    Enabels interrupts.
*/
__privileged void __ei();

/*
    Disables interrupts.
*/
__privileged void __di();

/*
    Pushes values to stack and then 
    executes `rti` instruction. 
*/
__privileged __noreturn void __rti(u16 entry_point, u16 flags);

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

/*
    Loads word from program memory with offset.
*/
u16 __lcw_off(__program u16* addr, usize off);

/*
    Loads unsigned byte from program memory with offset.
*/
u8 __lcb_off(__program u8* addr, usize off);

/*
    Loads signed byte from program memory with offset.
*/
i8 __lcsb_off(__program i8* addr, usize off);

/*
    Returns contents of PS register.
*/
u16 __ldps();

/*
    Returns contents of active stack pointer.
*/
u16 __ldsp();

/*
    Returns contents of shadow stack pointer.
*/
__privileged u16 __ldssp();

/*
    Set shadow stack pointer to some value.
*/
__privileged void __stssp(u16 value);


void __syscall(int, ...);


#endif /* _MACHINE_INTRINSIC_H_ */
