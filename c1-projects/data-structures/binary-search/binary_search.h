#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
#include <stdbool.h>
#include <stddef.h>

/* Input must be sorted in nondecreasing order. NULL is allowed only if size=0.
 * index must be valid. Returns the first match; leaves index unchanged if absent. */
bool binary_search(const int *values, size_t size, int target, size_t *index);
#endif
