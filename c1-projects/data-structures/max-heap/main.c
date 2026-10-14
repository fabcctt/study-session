#include "max_heap.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int values[] = {15, 4, 30, 8, 30, -2};
    MaxHeap heap;
    heap_init(&heap);
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        if (!heap_push(&heap, values[i])) {
            fputs("Could not grow the heap.\n", stderr);
            heap_destroy(&heap);
            return EXIT_FAILURE;
        }
    }
    printf("Maximum-first order:");
    int value;
    while (heap_pop(&heap, &value)) printf(" %d", value);
    puts("");
    heap_destroy(&heap);
    return EXIT_SUCCESS;
}
