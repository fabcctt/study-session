#include "graph.h"
#include "queue.h"
#include "stack.h"
#include <stdint.h>
#include <stdlib.h>

bool graph_init(Graph *graph, size_t vertex_count, bool directed)
{
    *graph = (Graph){0};
    graph->directed = directed;
    if (vertex_count == 0) return true;
    if (vertex_count > SIZE_MAX / sizeof(*graph->adjacency)) return false;
    graph->adjacency = calloc(vertex_count, sizeof(*graph->adjacency));
    if (graph->adjacency == NULL) return false;
    graph->vertex_count = vertex_count;
    return true;
}

void graph_destroy(Graph *graph)
{
    for (size_t i = 0; i < graph->vertex_count; ++i) {
        Edge *edge = graph->adjacency[i];
        while (edge != NULL) {
            Edge *next = edge->next;
            free(edge);
            edge = next;
        }
    }
    free(graph->adjacency);
    *graph = (Graph){0};
}

bool graph_add_edge(Graph *graph, size_t source, size_t destination)
{
    if (source >= graph->vertex_count || destination >= graph->vertex_count) return false;
    Edge *forward = malloc(sizeof(*forward));
    if (forward == NULL) return false;
    Edge *reverse = NULL;
    if (!graph->directed && source != destination) {
        reverse = malloc(sizeof(*reverse));
        if (reverse == NULL) {
            free(forward);
            return false;
        }
        *reverse = (Edge){source, graph->adjacency[destination]};
    }
    *forward = (Edge){destination, graph->adjacency[source]};
    graph->adjacency[source] = forward;
    if (reverse != NULL) graph->adjacency[destination] = reverse;
    return true;
}

bool graph_bfs(const Graph *graph, size_t start, size_t *order, size_t capacity, size_t *count)
{
    *count = 0;
    if (start >= graph->vertex_count || capacity < graph->vertex_count) return false;
    bool *visited = calloc(graph->vertex_count, sizeof(*visited));
    if (visited == NULL) return false;
    VertexQueue queue;
    if (!vertex_queue_init(&queue, graph->vertex_count)) {
        free(visited);
        return false;
    }
    visited[start] = true;
    vertex_queue_push(&queue, start);
    size_t vertex;
    while (vertex_queue_pop(&queue, &vertex)) {
        order[(*count)++] = vertex;
        for (const Edge *edge = graph->adjacency[vertex]; edge != NULL; edge = edge->next) {
            size_t next = edge->destination;
            if (!visited[next]) {
                visited[next] = true; /* Mark on enqueue, so each vertex enters once. */
                vertex_queue_push(&queue, next);
            }
        }
    }
    vertex_queue_destroy(&queue);
    free(visited);
    return true;
}

bool graph_dfs(const Graph *graph, size_t start, size_t *order, size_t capacity, size_t *count)
{
    *count = 0;
    if (start >= graph->vertex_count || capacity < graph->vertex_count) return false;
    bool *visited = calloc(graph->vertex_count, sizeof(*visited));
    const Edge **cursor = malloc(graph->vertex_count * sizeof(*cursor));
    VertexStack stack;
    if (visited == NULL || cursor == NULL) {
        free(visited);
        free(cursor);
        return false;
    }
    if (!vertex_stack_init(&stack, graph->vertex_count)) {
        free(visited);
        free(cursor);
        return false;
    }
    for (size_t i = 0; i < graph->vertex_count; ++i) cursor[i] = graph->adjacency[i];
    visited[start] = true;
    order[(*count)++] = start;
    vertex_stack_push(&stack, start);
    size_t vertex;
    while (vertex_stack_peek(&stack, &vertex)) {
        const Edge *edge = cursor[vertex];
        if (edge == NULL) {
            vertex_stack_pop(&stack, &vertex);
            continue;
        }
        cursor[vertex] = edge->next;
        size_t next = edge->destination;
        if (!visited[next]) {
            visited[next] = true;
            order[(*count)++] = next;
            vertex_stack_push(&stack, next);
        }
    }
    vertex_stack_destroy(&stack);
    free(cursor);
    free(visited);
    return true;
}
