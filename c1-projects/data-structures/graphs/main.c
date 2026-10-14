#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

static void print_order(const char *label, const size_t *order, size_t count)
{
    printf("%s:", label);
    for (size_t i = 0; i < count; ++i) printf(" %zu", order[i]);
    puts("");
}

int main(void)
{
    Graph graph;
    if (!graph_init(&graph, 7, false)) {
        fputs("Could not initialize the graph.\n", stderr);
        return EXIT_FAILURE;
    }
    const size_t edges[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {4, 5}};
    for (size_t i = 0; i < sizeof(edges) / sizeof(edges[0]); ++i)
        if (!graph_add_edge(&graph, edges[i][0], edges[i][1])) goto failure;
    puts("Adjacency lists:");
    for (size_t vertex = 0; vertex < graph.vertex_count; ++vertex) {
        printf("%zu:", vertex);
        for (const Edge *edge = graph.adjacency[vertex]; edge != NULL; edge = edge->next)
            printf(" %zu", edge->destination);
        puts("");
    }
    size_t order[7];
    size_t count;
    if (!graph_bfs(&graph, 0, order, 7, &count)) goto failure;
    print_order("BFS from 0", order, count);
    if (!graph_dfs(&graph, 0, order, 7, &count)) goto failure;
    print_order("DFS from 0", order, count);
    puts("Vertex 6 is disconnected from vertex 0.");
    graph_destroy(&graph);
    return EXIT_SUCCESS;

failure:
    fputs("Graph operation failed.\n", stderr);
    graph_destroy(&graph);
    return EXIT_FAILURE;
}
