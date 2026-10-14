#include "dynamic_array.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    DynamicArray array;
    array_init(&array);
    int value = -99;
    assert(!array_get(&array, 0, &value));
    assert(!array_remove(&array, 0, &value));
    assert(!array_insert(&array, 1, 42));
    assert(value == -99);
    for (int i = 0; i < 1000; ++i) assert(array_push(&array, i));
    assert(array.size == 1000 && array.capacity >= array.size);
    for (size_t i = 0; i < array.size; ++i) {
        assert(array_get(&array, i, &value));
        assert(value == (int)i);
    }
    assert(array_insert(&array, 0, -1));
    assert(array_insert(&array, 501, 1234));
    assert(array_remove(&array, 501, &value) && value == 1234);
    assert(array_remove(&array, 0, &value) && value == -1);
    assert(array_set(&array, 999, -7));
    assert(array_get(&array, 999, &value) && value == -7);
    assert(!array_set(&array, 1000, 42));
    assert(!array_reserve(&array, SIZE_MAX));
    assert(array.size == 1000 && array.data[0] == 0);
    while (array.size != 0) assert(array_remove(&array, array.size - 1, &value));
    assert(array_push(&array, 12));
    array_destroy(&array);
    assert(array.data == NULL && array.size == 0 && array.capacity == 0);
    array_destroy(&array);
    puts("Arrays: all tests passed.");
    return 0;
}
