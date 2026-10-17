#ifndef ARRAYS_H
#define ARRAYS_H

#include <stddef.h>
#include <stdbool.h>

long long sum_numbers(const int *numbers, size_t size);

bool find_max(
    const int *numbers,
    size_t size,
    int *result
);

size_t count_vowels(const char *text);

void reverse_string(char *text);

#endif
