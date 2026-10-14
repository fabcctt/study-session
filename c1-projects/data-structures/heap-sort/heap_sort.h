#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <stddef.h>

/* Sorts in ascending order in place. NULL is allowed only when size=0. */
void heap_sort(int *values, size_t size);
#endif
