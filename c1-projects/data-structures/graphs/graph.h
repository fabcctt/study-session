#ifndef GRAPH_H
#define GRAPH_H
#include <stdbool.h>
#include <stddef.h>

typedef struct Edge {
    size_t destination;
    struct Edge *next;
} Edge;

typedef struct {
    Edge **adjacency;
    size_t vertex_count;
    bool directed;
} Graph;

/* Graph owns all adjacency lists. IDs are [0, vertex_count). */
bool graph_init(Graph *graph, size_t vertex_count, bool directed);
void graph_destroy(Graph *graph);
/* New edges are prepended. Duplicate edges and self-loops are accepted. */
bool graph_add_edge(Graph *graph, size_t source, size_t destination);
/* Visit only vertices reachable from start, once each. order needs room for
 * vertex_count entries. count is zero on failure. Pointers must be valid. */
bool graph_bfs(const Graph *graph, size_t start, size_t *order, size_t capacity, size_t *count);
bool graph_dfs(const Graph *graph, size_t start, size_t *order, size_t capacity, size_t *count);
#endif
