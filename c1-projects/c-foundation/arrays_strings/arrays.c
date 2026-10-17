#include "arrays.h"
#include <string.h>

long long sum_numbers(const int *numbers, size_t size) {
    long long total = 0;

    if (numbers == NULL)
        return 0;

    for (size_t i = 0; i < size; i++) {
        total += numbers[i];
    }

    return total;
}

bool find_max(
    const int *numbers,
    size_t size,
    int *result
) {
    if (numbers == NULL || result == NULL || size == 0)
        return false;

    int maximum = numbers[0];

    for (size_t i = 1; i < size; i++) {
        if (numbers[i] > maximum)
            maximum = numbers[i];
    }

    *result = maximum;
    return true;
}

size_t count_vowels(const char *text) {
    if (text == NULL)
        return 0;

    size_t count = 0;

    for (size_t i = 0; text[i] != '\0'; i++) {
        switch (text[i]) {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o': case 'O':
            case 'u': case 'U':
                count++;
                break;
        }
    }

    return count;
}

void reverse_string(char *text) {
    if (text == NULL)
        return;

    size_t length = strlen(text);

    for (size_t i = 0; i < length / 2; i++) {
        char temp = text[i];

        text[i] = text[length - 1 - i];
        text[length - 1 - i] = temp;
    }
}
