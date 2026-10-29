#include "operations.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>

static void test_add(void) {
    assert(add(3, 4) == 7);
    assert(add(-3, 4) == 1);
    assert(add(0, 0) == 0);
}

static void test_multiply(void) {
    assert(multiply(3, 4) == 12);
    assert(multiply(-3, 4) == -12);
    assert(multiply(-3, -4) == 12);
    assert(multiply(5, 0) == 0);
}

static void test_calculate(void) {
    int result = 0;

    assert(calculate(3, 4, add, &result));
    assert(result == 7);

    assert(calculate(3, 4, multiply, &result));
    assert(result == 12);
}

static void test_invalid_pointers(void) {
    int result = 99;

    assert(!calculate(3, 4, NULL, &result));
    assert(result == 99);
    assert(!calculate(3, 4, add, NULL));
    assert(!calculate(3, 4, NULL, NULL));
}

int main(void) {
    test_add();
    test_multiply();
    test_calculate();
    test_invalid_pointers();

    printf("All operation tests passed.\n");
    return 0;
}
