#include "dynamic_memory.h"

#include <stdio.h>

int main(void) {
    IntBuffer numbers = {0};
    IntBuffer copy = {0};

    if (!buffer_init(&numbers, 2)) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 1; i <= 5; i++) {
        if (!buffer_push(&numbers, i * 10)) {
            fprintf(stderr, "Failed to add element.\n");
            buffer_free(&numbers);
            return 1;
        }
    }

    printf("Original ");
    buffer_print(&numbers);

    if (!buffer_clone(&numbers, &copy)) {
        fprintf(stderr, "Failed to clone buffer.\n");
        buffer_free(&numbers);
        return 1;
    }

    printf("Copy ");
    buffer_print(&copy);

    int value = 0;

    if (buffer_get(&numbers, 2, &value)) {
        printf("Element at index 2: %d\n", value);
    }

    buffer_free(&copy);
    buffer_free(&numbers);

    printf("Memory released successfully.\n");

    return 0;
}