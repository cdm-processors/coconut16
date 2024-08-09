#ifndef _ARENA_ARENA_H_
#define _ARENA_ARENA_H_

#include <machine/types.h>

/**
 * Minimal arena allocator.
 *
 * @see <a href="https://en.wikipedia.org/wiki/Region-based_memory_management">Arena allocator</a>
 */
struct arena {
    void* ptr;
    void* end;
};

/**
 * Initializes new arena allocator.
 *
 * @param self pointer to allocator
 * @param base_ptr pointer to start address of new arena
 * @param capacity size of new arena
 */
void arena_init(struct arena* self, void* base_ptr, usize capacity);

/**
 * Allocates bytes with given allocator.
 *
 * @param self pointer to allocator
 * @param count number of bytes to allocate
 * @return pointer to allocated memory
 *         or 0 if allocation wasn't successful
 */
void* arena_alloc(struct arena* self, usize count);


#endif /* _ARENA_ARENA_H_ */
