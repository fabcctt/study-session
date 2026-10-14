#ifndef UNION_FIND_H
#define UNION_FIND_H
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    size_t *parent;
    size_t *weight;
    size_t size;
    size_t components;
} UnionFind;

/* Owns arrays. Valid IDs are [0, size). Pointers must be valid.
 * Initialize once before use; failed initialization leaves an empty object. */
bool uf_init(UnionFind *sets, size_t size);
void uf_destroy(UnionFind *sets);
bool uf_find(UnionFind *sets, size_t element, size_t *root);
/* Returns success even if both elements already belong to the same set. */
bool uf_union(UnionFind *sets, size_t left, size_t right);
bool uf_connected(UnionFind *sets, size_t left, size_t right, bool *connected);
#endif
