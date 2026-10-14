#include "graph.h"
#include "queue.h"
#include "stack.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

static void check_order(const size_t *actual, const size_t *expected, size_t count)
{
    for (size_t i = 0; i < count; ++i) assert(actual[i] == expected[i]);
}

static void test_helpers(void)
{
    VertexQueue queue;
    size_t value = 99;
    assert(vertex_queue_init(&queue, 3));
    assert(!vertex_queue_pop(&queue, &value) && value == 99);
    for (size_t i = 0; i < 3; ++i) assert(vertex_queue_push(&queue, i));
    assert(!vertex_queue_push(&queue, 3));
    assert(vertex_queue_pop(&queue, &value) && value == 0);
    assert(vertex_queue_push(&queue, 3)); /* Circular wraparound. */
    for (size_t i = 1; i <= 3; ++i) assert(vertex_queue_pop(&queue, &value) && value == i);
    vertex_queue_destroy(&queue);
    assert(vertex_queue_init(&queue, 0) && !vertex_queue_push(&queue, 1));
    vertex_queue_destroy(&queue);
    assert(!vertex_queue_init(&queue, SIZE_MAX));
    vertex_queue_destroy(&queue);
    VertexStack stack;
    assert(vertex_stack_init(&stack, 2));
    assert(!vertex_stack_pop(&stack, &value));
    assert(vertex_stack_push(&stack, 10) && vertex_stack_push(&stack, 20));
    assert(!vertex_stack_push(&stack, 30));
    assert(vertex_stack_peek(&stack, &value) && value == 20 && stack.size == 2);
    assert(vertex_stack_pop(&stack, &value) && value == 20);
    assert(vertex_stack_pop(&stack, &value) && value == 10);
    vertex_stack_destroy(&stack);
    assert(vertex_stack_init(&stack, 0) && !vertex_stack_push(&stack, 1));
    vertex_stack_destroy(&stack);
    assert(!vertex_stack_init(&stack, SIZE_MAX));
    vertex_stack_destroy(&stack);
}

int main(void)
{
    test_helpers();
    Graph graph;
    size_t order[256];
    size_t count = 99;
    assert(graph_init(&graph, 0, false));
    assert(!graph_bfs(&graph, 0, order, 256, &count) && count == 0);
    assert(!graph_dfs(&graph, 0, order, 256, &count));
    graph_destroy(&graph);
    assert(!graph_init(&graph, SIZE_MAX, false));
    graph_destroy(&graph);
    assert(graph_init(&graph, 7, false));
    const size_t edges[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {4, 5}};
    for (size_t i = 0; i < 6; ++i) assert(graph_add_edge(&graph, edges[i][0], edges[i][1]));
    const size_t bfs[] = {0, 2, 1, 5, 4, 3};
    const size_t dfs[] = {0, 2, 5, 4, 1, 3};
    assert(graph_bfs(&graph, 0, order, 256, &count) && count == 6);
    check_order(order, bfs, count);
    assert(graph_dfs(&graph, 0, order, 256, &count) && count == 6);
    check_order(order, dfs, count);
    assert(graph_bfs(&graph, 6, order, 256, &count) && count == 1 && order[0] == 6);
    assert(graph_dfs(&graph, 6, order, 256, &count) && count == 1 && order[0] == 6);
    assert(!graph_add_edge(&graph, 0, 7));
    assert(!graph_bfs(&graph, 7, order, 256, &count) && count == 0);
    assert(!graph_dfs(&graph, 0, order, 1, &count) && count == 0);
    assert(!graph_bfs(&graph, 0, order, 1, &count) && count == 0);
    assert(graph_add_edge(&graph, 0, 0) && graph_add_edge(&graph, 0, 2));
    assert(graph_bfs(&graph, 0, order, 256, &count) && count == 6);
    check_order(order, bfs, count);
    assert(graph_dfs(&graph, 0, order, 256, &count) && count == 6);
    check_order(order, dfs, count);
    graph_destroy(&graph);
    assert(graph_init(&graph, 256, true));
    for (size_t i = 1; i < 256; ++i) assert(graph_add_edge(&graph, i - 1, i));
    assert(graph_bfs(&graph, 255, order, 256, &count) && count == 1);
    assert(graph_dfs(&graph, 255, order, 256, &count) && count == 1);
    assert(graph_bfs(&graph, 0, order, 256, &count) && count == 256);
    for (size_t i = 0; i < count; ++i) assert(order[i] == i);
    assert(graph_dfs(&graph, 0, order, 256, &count) && count == 256);
    for (size_t i = 0; i < count; ++i) assert(order[i] == i);
    graph_destroy(&graph);
    graph_destroy(&graph);
    puts("Graphs: all tests passed.");
    return 0;
}
