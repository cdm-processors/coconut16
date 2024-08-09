#include "arena.h"

void arena_init(struct arena* self, void* base_ptr, usize capacity) {
    self->ptr = base_ptr;
    self->end = base_ptr + capacity;
}

void* arena_alloc(struct arena* self, usize count) {
    if (self->ptr + count >= self->end) {
        return (void*) 0;
    }

    void* ptr = self->ptr;

    self->ptr += count;

    return ptr;
}
