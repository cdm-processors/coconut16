#ifndef _COMPILER_H_
#define _COMPILER_H_

#define PROGRAM_MEMORY_ADDRESS_SPACE    1
#define DATA_MEMORY_ADDRESS_SPACE       0

#define __program   __attribute__((address_space(PROGRAM_MEMORY_ADDRESS_SPACE)))
#define __data      __attribute__((address_space(DATA_MEMORY_ADDRESS_SPACE)))

#define __noreturn __attribute__((noreturn))

#define __privileged

#endif /* _COMPILER_H_ */
