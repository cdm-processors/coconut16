// NOLINTBEGIN(bugprone-reserved-identifier)

#ifndef _COMPILER_H_
#define _COMPILER_H_

#define PROGRAM_MEMORY_ADDRESS_SPACE    1
#define DATA_MEMORY_ADDRESS_SPACE       0
#define IO_ADDRESS_SPACE                2

/**
 * Indicates that this pointer is in program memory address space.
 */
#define __program       const __attribute__((address_space(PROGRAM_MEMORY_ADDRESS_SPACE)))

/**
 * Indicates that this pointer is in data memory address space.
 */
#define __data          __attribute__((address_space(DATA_MEMORY_ADDRESS_SPACE)))

/**
 * Indicates that this pointer is in IO address space.
 */
#define __io            volatile __attribute__((address_space(IO_ADDRESS_SPACE)))


/**
 * Indicates that function can be run only in privileged mode.
 */
#define __privileged

/**
 * Indicates that function is called from assembly.
 */
#define __asm_call      __attribute__((unused))

// Definitions for Clang attributes

#define __deprecated    __attribute__((deprecated))
#define __noreturn      __attribute__((noreturn))
#define __minsize       __attribute__((minsize))
#define __overloadable  __attribute__((overloadable))
#define __no_builtin    __attribute__((no_builtin))
#define __optnone       __attribute__((optnone))
#define __noinline      __attribute__((noinline))
#define __always_inline __attribute__((always_inline)) inline

#define __no_caller_saved_registers    __attribute__((no_caller_saved_registers))

#endif /* _COMPILER_H_ */

// NOLINTEND(bugprone-reserved-identifier)
