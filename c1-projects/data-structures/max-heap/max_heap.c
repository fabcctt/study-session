#include "max_heap.h"
#include <stdint.h>
#include <stdlib.h>

void heap_init(MaxHeap *heap)
{
    *heap = (MaxHeap){0};
}

void heap_destroy(MaxHeap *heap)
{
    free(heap->data);
    heap_init(heap);
}

bool heap_push(MaxHeap *heap, int value)
{
    if (heap->size == heap->capacity) {
        const size_t limit = SIZE_MAX / sizeof(int);
        if (heap->capacity >= limit) return false;
        size_t capacity = heap->capacity == 0 ? 8 : heap->capacity;
        capacity = capacity > limit / 2 ? limit : capacity * 2;
        int *data = realloc(heap->data, capacity * sizeof(*data));
        if (data == NULL) return false;
        heap->data = data;
        heap->capacity = capacity;
    }
    size_t child = heap->size++;
    while (child > 0) {
        size_t parent = (child - 1) / 2;
        if (heap->data[parent] >= value) break;
        heap->data[child] = heap->data[parent];
        child = parent;
    }
    heap->data[child] = value;
    return true;
}

bool heap_peek(const MaxHeap *heap, int *value)
{
    if (heap->size == 0) return false;
    *value = heap->data[0];
    return true;
}

bool heap_pop(MaxHeap *heap, int *value)
{
    if (heap->size == 0) return false;
    *value = heap->data[0];
    int last = heap->data[--heap->size];
    if (heap->size == 0) return true;
    size_t parent = 0;
    /* parent < size/2 identifies nodes with at least a left child. */
    while (parent < heap->size / 2) {
        size_t child = parent * 2 + 1;
        if (child + 1 < heap->size && heap->data[child + 1] > heap->data[child])
            ++child;
        if (heap->data[child] <= last) break;
        heap->data[parent] = heap->data[child];
        parent = child;
    }
    heap->data[parent] = last;
    return true;
}
