#include "dynamic_array.h"

#include <stdint.h>
#include <stdlib.h>

void array_init(DynamicArray *array)
{
    *array = (DynamicArray){0};
}

void array_destroy(DynamicArray *array)
{
    free(array->data);
    array_init(array);
}

bool array_reserve(DynamicArray *array, size_t capacity)
{
    if (capacity <= array->capacity) return true;
    if (capacity > SIZE_MAX / sizeof(int)) return false;
    int *data = realloc(array->data, capacity * sizeof(*data));
    if (data == NULL) return false;
    array->data = data;
    array->capacity = capacity;
    return true;
}

static bool grow(DynamicArray *array)
{
    if (array->size < array->capacity) return true;
    const size_t limit = SIZE_MAX / sizeof(int);
    if (array->capacity >= limit) return false;
    size_t capacity = array->capacity == 0 ? 4 : array->capacity;
    capacity = capacity > limit / 2 ? limit : capacity * 2;
    return array_reserve(array, capacity);
}

bool array_insert(DynamicArray *array, size_t index, int value)
{
    if (index > array->size || !grow(array)) return false;
    for (size_t i = array->size; i > index; --i)
        array->data[i] = array->data[i - 1];
    array->data[index] = value;
    ++array->size;
    return true;
}

bool array_push(DynamicArray *array, int value)
{
    return array_insert(array, array->size, value);
}

bool array_remove(DynamicArray *array, size_t index, int *removed)
{
    if (index >= array->size) return false;
    *removed = array->data[index];
    for (size_t i = index; i + 1 < array->size; ++i)
        array->data[i] = array->data[i + 1];
    --array->size;
    return true;
}

bool array_get(const DynamicArray *array, size_t index, int *value)
{
    if (index >= array->size) return false;
    *value = array->data[index];
    return true;
}

bool array_set(DynamicArray *array, size_t index, int value)
{
    if (index >= array->size) return false;
    array->data[index] = value;
    return true;
}
