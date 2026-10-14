#ifndef GRAPH_STACK_H
#define GRAPH_STACK_H
#include <stdbool.h>
#include <stddef.h>

/* Fixed-capacity stack for vertex IDs. Owns data. */
typedef struct {
    size_t *data;
    size_t capacity;
    size_t size;
} VertexStack;

bool vertex_stack_init(VertexStack *stack, size_t capacity);
void vertex_stack_destroy(VertexStack *stack);
bool vertex_stack_push(VertexStack *stack, size_t vertex);
bool vertex_stack_pop(VertexStack *stack, size_t *vertex);
bool vertex_stack_peek(const VertexStack *stack, size_t *vertex);
#endif
