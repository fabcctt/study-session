#include "binary_search.h"
#include <stdio.h>

int main(void)
{
    const int values[] = {-10, 0, 5, 5, 12, 30};
    const int targets[] = {5, 7};
    for (size_t i = 0; i < sizeof(targets) / sizeof(targets[0]); ++i) {
        size_t index;
        if (binary_search(values, sizeof(values) / sizeof(values[0]), targets[i], &index))
            printf("Found %d at index %zu.\n", targets[i], index);
        else printf("Value %d was not found.\n", targets[i]);
    }
    return 0;
}
