#ifndef DYNAMIC_MEMORY_H
#define DYNAMIC_MEMORY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} IntBuffer;

bool buffer_init(IntBuffer *buffer, size_t capacity);
bool buffer_push(IntBuffer *buffer, int value);
bool buffer_get(const IntBuffer *buffer, size_t index, int *out);
bool buffer_clone(const IntBuffer *source, IntBuffer *copy);

void buffer_print(const IntBuffer *buffer);
void buffer_free(IntBuffer *buffer);

#endif