#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "arrays.h"

static void test_sum(void) {
    int numbers[] = {10, 20, 30};

    assert(sum_numbers(numbers, 3) == 60);
    assert(sum_numbers(numbers, 0) == 0);
    assert(sum_numbers(NULL, 0) == 0);
}

static void test_max(void) {
    int numbers[] = {-10, 5, 30, 2};
    int result = 0;

    assert(find_max(numbers, 4, &result));
    assert(result == 30);

    assert(!find_max(numbers, 0, &result));
    assert(!find_max(NULL, 4, &result));
}

static void test_vowels(void) {
    assert(count_vowels("Gentoo") == 3);
    assert(count_vowels("sky") == 0);
    assert(count_vowels("") == 0);
    assert(count_vowels(NULL) == 0);
}

static void test_reverse(void) {
    char word[] = "Linux";
    char empty[] = "";

    reverse_string(word);
    assert(strcmp(word, "xuniL") == 0);

    reverse_string(empty);
    assert(strcmp(empty, "") == 0);

    reverse_string(NULL);
}

int main(void) {
    test_sum();
    test_max();
    test_vowels();
    test_reverse();

    puts("All array and string tests passed.");

    return 0;
}
