#include "operations.h"
#include <stdio.h>

int main(void) {
    int a = 3;
    int b = 4;
    int result = 0;

    if (!calculate(a, b, add, &result)) {
        fprintf(stderr, "Failed to calculate the sum.\n");
        return 1;
    }

    printf("%d + %d = %d\n", a, b, result);

    if (!calculate(a, b, multiply, &result)) {
        fprintf(stderr, "Failed to calculate the product.\n");
        return 1;
    }

    printf("%d * %d = %d\n", a, b, result);

    return 0;
}
