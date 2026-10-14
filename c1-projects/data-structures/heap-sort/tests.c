#include "heap_sort.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare(const void *left, const void *right)
{
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b);
}

static void check(int *values, size_t size)
{
    int reference[257];
    memcpy(reference, values, size * sizeof(*values));
    qsort(reference, size, sizeof(*values), compare);
    heap_sort(values, size);
    for (size_t i = 0; i < size; ++i) assert(values[i] == reference[i]);
}

int main(void)
{
    heap_sort(NULL, 0);
    int values[257];
    for (size_t size = 0; size <= 257; ++size) {
        for (size_t i = 0; i < size; ++i) values[i] = (int)((i * 71) % 31) - 15;
        check(values, size);
        check(values, size); /* Already sorted. */
        for (size_t i = 0; i < size; ++i) values[i] = (int)(size - i);
        check(values, size);
        for (size_t i = 0; i < size; ++i) values[i] = 7;
        check(values, size);
    }
    int extremes[] = {INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN};
    check(extremes, 5);
    puts("Heap sort: all tests passed.");
    return 0;
}
