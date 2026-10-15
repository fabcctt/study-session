#include <assert.h>
#include <stdio.h>

#include "pointers.h"

static void test_add_value(void) {
    int number = 10;

    add_value(&number, 5);

    assert(number == 15);

    add_value(&number, -5);

    assert(number == 10);

    add_value(NULL, 5);
}

static void test_swap_values(void) {
    int first = 10;
    int second = 20;

    swap_values(&first, &second);

    assert(first == 20);
    assert(second == 10);

    swap_values(&first, &first);

    assert(first == 20);

    swap_values(NULL, &second);
}

static void test_add_to_array(void) {
    int numbers[] = {1, 2, 3};

    add_to_array(numbers, 3, 5);

    assert(numbers[0] == 6);
    assert(numbers[1] == 7);
    assert(numbers[2] == 8);

    add_to_array(NULL, 0, 5);
}

static void test_sum_array(void) {
    int numbers[] = {10, 20, 30};

    assert(sum_array(numbers, 3) == 60);
    assert(sum_array(numbers, 0) == 0);
    assert(sum_array(NULL, 0) == 0);
}

int main(void) {
    test_add_value();
    test_swap_values();
    test_add_to_array();
    test_sum_array();

    puts("All pointer tests passed.");

    return 0;
}
