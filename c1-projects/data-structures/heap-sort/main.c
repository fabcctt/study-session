#include "heap_sort.h"
#include <stdio.h>

int main(void)
{
    int values[] = {15, 4, 30, 8, 30, -2};
    size_t size = sizeof(values) / sizeof(values[0]);
    printf("Before:");
    for (size_t i = 0; i < size; ++i) printf(" %d", values[i]);
    heap_sort(values, size);
    printf("\nAfter:");
    for (size_t i = 0; i < size; ++i) printf(" %d", values[i]);
    puts("");
    return 0;
}
