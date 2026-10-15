#include "pointers.h"

void add_value(int *number, int amount) {
    if (number == NULL)
        return;

    *number += amount;
}

void swap_values(int *first, int *second) {
    if (first == NULL || second == NULL)
        return;

    int temp = *first;

    *first = *second;
    *second = temp;
}

void add_to_array(int *values, size_t size, int amount) {
    if (values == NULL)
        return;

    for (size_t i = 0; i < size; i++) {
        *(values + i) += amount;
    }
}

int sum_array(const int *values, size_t size) {
    if (values == NULL)
        return 0;

    int total = 0;

    for (size_t i = 0; i < size; i++) {
        total += *(values + i);
    }

    return total;
}
