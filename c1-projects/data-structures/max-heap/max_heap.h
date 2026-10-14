#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} MaxHeap;

/* Owns data; initialize before use. All object/output pointers must be valid. */
void heap_init(MaxHeap *heap);
void heap_destroy(MaxHeap *heap);
bool heap_push(MaxHeap *heap, int value);
bool heap_peek(const MaxHeap *heap, int *value);
bool heap_pop(MaxHeap *heap, int *value);
#endif
