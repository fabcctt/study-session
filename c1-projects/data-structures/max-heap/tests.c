#include "max_heap.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int compare(const void *left, const void *right)
{
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b);
}

static void check_invariant(const MaxHeap *heap)
{
    for (size_t i = 1; i < heap->size; ++i)
        assert(heap->data[(i - 1) / 2] >= heap->data[i]);
}

int main(void)
{
    MaxHeap heap;
    heap_init(&heap);
    int value = 99;
    assert(!heap_pop(&heap, &value) && value == 99);
    assert(!heap_peek(&heap, &value));
    int reference[1000];
    for (size_t i = 0; i < 1000; ++i) {
        reference[i] = (int)((i * 73) % 257) - 128;
        if (i == 0) reference[i] = INT_MIN;
        if (i == 1) reference[i] = INT_MAX;
        assert(heap_push(&heap, reference[i]));
        check_invariant(&heap);
    }
    qsort(reference, 1000, sizeof(reference[0]), compare);
    for (size_t i = 1000; i > 0; --i) {
        assert(heap_peek(&heap, &value) && value == reference[i - 1]);
        assert(heap_pop(&heap, &value) && value == reference[i - 1]);
        check_invariant(&heap);
    }
    assert(heap_push(&heap, 8));
    assert(heap_push(&heap, 3));
    assert(heap_pop(&heap, &value) && value == 8);
    assert(heap_push(&heap, 10));
    assert(heap_pop(&heap, &value) && value == 10);
    assert(heap_pop(&heap, &value) && value == 3);
    heap_destroy(&heap);
    heap_destroy(&heap);
    puts("Max-heap: all tests passed.");
    return 0;
}
