#include <stdio.h>
#include "arrays.h"

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    int maximum;

    printf("=== Array & String Lab ===\n");

    printf("\nArray sum: %lld\n",
           sum_numbers(numbers, size));

    if (find_max(numbers, size, &maximum)) {
        printf("Maximum: %d\n", maximum);
    }

    char word[] = "Gentoo";

    printf("\nOriginal word: %s\n", word);
    printf("Vowels: %zu\n", count_vowels(word));

    reverse_string(word);

    printf("Reversed word: %s\n", word);

    return 0;
}
