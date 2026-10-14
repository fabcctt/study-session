#include "union_find.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    UnionFind sets;
    if (!uf_init(&sets, 6)) {
        fputs("Could not initialize disjoint sets.\n", stderr);
        return EXIT_FAILURE;
    }
    if (!uf_union(&sets, 0, 1) || !uf_union(&sets, 1, 2) || !uf_union(&sets, 3, 4)) {
        fputs("Invalid element ID.\n", stderr);
        uf_destroy(&sets);
        return EXIT_FAILURE;
    }
    bool connected;
    uf_connected(&sets, 0, 2, &connected);
    printf("0 and 2 connected: %s\n", connected ? "yes" : "no");
    uf_connected(&sets, 0, 4, &connected);
    printf("0 and 4 connected: %s\n", connected ? "yes" : "no");
    printf("Components: %zu\n", sets.components);
    uf_destroy(&sets);
    return EXIT_SUCCESS;
}
