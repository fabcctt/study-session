#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int fixed[] = {10, 20, 30};
    DynamicArray array;
    array_init(&array);
    printf("Fixed array (%zu elements):", sizeof(fixed) / sizeof(fixed[0]));
    for (size_t i = 0; i < sizeof(fixed) / sizeof(fixed[0]); ++i) {
        printf(" %d", fixed[i]);
        if (!array_push(&array, fixed[i])) goto failure;
    }
    puts("");
    if (!array_insert(&array, 1, 15) || !array_push(&array, 40)) goto failure;
    printf("Dynamic array (size=%zu, capacity=%zu):", array.size, array.capacity);
    for (size_t i = 0; i < array.size; ++i) printf(" %d", array.data[i]);
    puts("");
    int removed;
    if (!array_remove(&array, 0, &removed)) goto failure;
    printf("Removed: %d; remaining size: %zu\n", removed, array.size);
    array_destroy(&array);
    return EXIT_SUCCESS;

failure:
    fputs("Array operation failed.\n", stderr);
    array_destroy(&array);
    return EXIT_FAILURE;
}
