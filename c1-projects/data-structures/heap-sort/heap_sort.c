#include "heap_sort.h"

static void swap(int *left, int *right)
{
    int temporary = *left;
    *left = *right;
    *right = temporary;
}

static void sift_down(int *values, size_t size, size_t parent)
{
    while (parent < size / 2) {
        size_t child = parent * 2 + 1;
        if (child + 1 < size && values[child + 1] > values[child]) ++child;
        if (values[parent] >= values[child]) break;
        swap(&values[parent], &values[child]);
        parent = child;
    }
}

void heap_sort(int *values, size_t size)
{
    if (size < 2) return;
    /* Bottom-up heap construction takes O(n). */
    for (size_t i = size / 2; i > 0; --i) sift_down(values, size, i - 1);
    for (size_t end = size; end > 1; --end) {
        swap(&values[0], &values[end - 1]);
        sift_down(values, end - 1, 0);
    }
}
