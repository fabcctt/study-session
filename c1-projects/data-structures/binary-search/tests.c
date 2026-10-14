#include "binary_search.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>

int main(void)
{
    size_t index = 99;
    assert(!binary_search(NULL, 0, 1, &index) && index == 99);
    const int one[] = {7};
    assert(binary_search(one, 1, 7, &index) && index == 0);
    assert(!binary_search(one, 1, 6, &index));
    const int edges[] = {INT_MIN, -1, 0, INT_MAX};
    assert(binary_search(edges, 4, INT_MIN, &index) && index == 0);
    assert(binary_search(edges, 4, INT_MAX, &index) && index == 3);
    int values[1000];
    for (size_t i = 0; i < 1000; ++i) values[i] = (int)(i / 3) - 100;
    for (int target = -110; target <= 240; ++target) {
        size_t expected = 0;
        while (expected < 1000 && values[expected] != target) ++expected;
        bool found = binary_search(values, 1000, target, &index);
        assert(found == (expected < 1000));
        if (found) assert(index == expected);
    }
    puts("Binary search: all tests passed.");
    return 0;
}
