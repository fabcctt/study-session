#include "dynamic_memory.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool buffer_init(IntBuffer *buffer, size_t capacity) {
    if (buffer == NULL) {
        return false;
    }

    // Requires a new or previously freed buffer.
    *buffer = (IntBuffer){0};

    if (capacity == 0) {
        return true;
    }

    if (capacity > SIZE_MAX / sizeof(int)) {
        return false;
    }

    buffer->data = calloc(capacity, sizeof(int));

    if (buffer->data == NULL) {
        return false;
    }

    buffer->capacity = capacity;
    return true;
}

bool buffer_push(IntBuffer *buffer, int value) {
    if (buffer == NULL) {
        return false;
    }

    if (buffer->size == buffer->capacity) {
        size_t limit = SIZE_MAX / sizeof(int);

        if (buffer->capacity >= limit) {
            return false;
        }

        size_t new_capacity;

        if (buffer->capacity == 0) {
            new_capacity = 2;
        } else if (buffer->capacity > limit / 2) {
            new_capacity = limit;
        } else {
            new_capacity = buffer->capacity * 2;
        }

        int *temp = realloc(
            buffer->data,
            new_capacity * sizeof(int)
        );

        if (temp == NULL) {
            return false;
        }

        buffer->data = temp;
        buffer->capacity = new_capacity;
    }

    buffer->data[buffer->size] = value;
    buffer->size++;

    return true;
}

bool buffer_get(
    const IntBuffer *buffer,
    size_t index,
    int *out
) {
    if (buffer == NULL || out == NULL) {
        return false;
    }

    if (index >= buffer->size) {
        return false;
    }

    *out = buffer->data[index];
    return true;
}

bool buffer_clone(
    const IntBuffer *source,
    IntBuffer *copy
) {
    if (source == NULL || copy == NULL || source == copy) {
        return false;
    }

    // Requires a new or previously freed destination.
    *copy = (IntBuffer){0};

    if (source->size == 0) {
        return true;
    }

    if (source->size > SIZE_MAX / sizeof(int)) {
        return false;
    }

    size_t bytes = source->size * sizeof(int);

    copy->data = malloc(bytes);

    if (copy->data == NULL) {
        return false;
    }

    memcpy(copy->data, source->data, bytes);

    copy->size = source->size;
    copy->capacity = source->size;

    return true;
}

void buffer_print(const IntBuffer *buffer) {
    if (buffer == NULL) {
        return;
    }

    printf("Buffer: [");

    for (size_t i = 0; i < buffer->size; i++) {
        if (i > 0) {
            printf(", ");
        }

        printf("%d", buffer->data[i]);
    }

    printf("] (size=%zu, capacity=%zu)\n",
           buffer->size, buffer->capacity);
}

void buffer_free(IntBuffer *buffer) {
    if (buffer == NULL) {
        return;
    }

    free(buffer->data);

    buffer->data = NULL;
    buffer->size = 0;
    buffer->capacity = 0;
}