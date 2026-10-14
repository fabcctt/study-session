#include "union_find.h"
#include <stdint.h>
#include <stdlib.h>

bool uf_init(UnionFind *sets, size_t size)
{
    *sets = (UnionFind){0};
    if (size == 0) return true;
    if (size > SIZE_MAX / sizeof(size_t)) return false;
    sets->parent = malloc(size * sizeof(*sets->parent));
    sets->weight = malloc(size * sizeof(*sets->weight));
    if (sets->parent == NULL || sets->weight == NULL) {
        uf_destroy(sets);
        return false;
    }
    sets->size = size;
    sets->components = size;
    for (size_t i = 0; i < size; ++i) {
        sets->parent[i] = i;
        sets->weight[i] = 1;
    }
    return true;
}

void uf_destroy(UnionFind *sets)
{
    free(sets->parent);
    free(sets->weight);
    *sets = (UnionFind){0};
}

bool uf_find(UnionFind *sets, size_t element, size_t *root)
{
    if (element >= sets->size) return false;
    size_t representative = element;
    while (sets->parent[representative] != representative)
        representative = sets->parent[representative];
    /* Full path compression. */
    while (element != representative) {
        size_t next = sets->parent[element];
        sets->parent[element] = representative;
        element = next;
    }
    *root = representative;
    return true;
}

bool uf_union(UnionFind *sets, size_t left, size_t right)
{
    if (left >= sets->size || right >= sets->size) return false;
    size_t left_root;
    size_t right_root;
    uf_find(sets, left, &left_root);
    uf_find(sets, right, &right_root);
    if (left_root == right_root) return true;
    if (sets->weight[left_root] < sets->weight[right_root]) {
        size_t temporary = left_root;
        left_root = right_root;
        right_root = temporary;
    }
    sets->parent[right_root] = left_root;
    sets->weight[left_root] += sets->weight[right_root];
    --sets->components;
    return true;
}

bool uf_connected(UnionFind *sets, size_t left, size_t right, bool *connected)
{
    if (left >= sets->size || right >= sets->size) return false;
    size_t left_root;
    size_t right_root;
    uf_find(sets, left, &left_root);
    uf_find(sets, right, &right_root);
    *connected = left_root == right_root;
    return true;
}
