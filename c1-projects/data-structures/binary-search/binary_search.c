#include "binary_search.h"

bool binary_search(const int *values, size_t size, int target, size_t *index)
{
    /* Search the half-open interval [left, right). */
    size_t left = 0;
    size_t right = size;
    while (left < right) {
        size_t middle = left + (right - left) / 2;
        if (values[middle] < target) left = middle + 1;
        else right = middle;
    }
    if (left == size || values[left] != target) return false;
    *index = left;
    return true;
}
