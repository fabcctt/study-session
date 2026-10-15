#ifndef POINTERS_H
#define POINTERS_H

#include <stddef.h>

void add_value(int *number, int amount);

void swap_values(int *first, int *second);

void add_to_array(int *values, size_t size, int amount);

int sum_array(const int *values, size_t size);

#endif
