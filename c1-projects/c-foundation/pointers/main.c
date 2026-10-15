
#include <stdio.h>

#include "pointers.h"

int main(void) {
    int first = 10;
    int second = 20;

    int *ptr = &first;

    printf("=== Pointer Lab ===\n");

    printf("\nInitial values:\n");
    printf("First: %d\n", first);
    printf("Second: %d\n", second);

    add_value(ptr, 5);

    printf("\nAfter adding 5 through a pointer:\n");
    printf("First: %d\n", first);

    swap_values(&first, &second);

    printf("\nAfter swapping:\n");
    printf("First: %d\n", first);
    printf("Second: %d\n", second);

    int numbers[] = {10, 20, 30, 40, 50};

    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    add_to_array(numbers, size, 5);

    printf("\nModified array: ");

    for (size_t i = 0; i < size; i++) {
        printf("%d ", *(numbers + i));
    }

    printf("\nArray sum: %d\n",
           sum_array(numbers, size));

    return 0;
}
