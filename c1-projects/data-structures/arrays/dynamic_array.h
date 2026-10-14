#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

/* Owns data. Initialize before use, destroy once done, and do not shallow-copy.
 * Object/output pointers must be valid. A failed operation leaves data unchanged. */
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

void array_init(DynamicArray *array);
void array_destroy(DynamicArray *array);
bool array_reserve(DynamicArray *array, size_t capacity);
bool array_push(DynamicArray *array, int value);
bool array_insert(DynamicArray *array, size_t index, int value);
bool array_remove(DynamicArray *array, size_t index, int *removed);
bool array_get(const DynamicArray *array, size_t index, int *value);
bool array_set(DynamicArray *array, size_t index, int value);

#endif
