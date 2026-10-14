#include "stack.h"
#include <stdint.h>
#include <stdlib.h>

bool vertex_stack_init(VertexStack *stack, size_t capacity)
{
    *stack = (VertexStack){0};
    if (capacity == 0) return true;
    if (capacity > SIZE_MAX / sizeof(size_t)) return false;
    stack->data = malloc(capacity * sizeof(*stack->data));
    if (stack->data == NULL) return false;
    stack->capacity = capacity;
    return true;
}

void vertex_stack_destroy(VertexStack *stack)
{
    free(stack->data);
    *stack = (VertexStack){0};
}

bool vertex_stack_push(VertexStack *stack, size_t vertex)
{
    if (stack->size == stack->capacity) return false;
    stack->data[stack->size++] = vertex;
    return true;
}

bool vertex_stack_pop(VertexStack *stack, size_t *vertex)
{
    if (stack->size == 0) return false;
    *vertex = stack->data[--stack->size];
    return true;
}

bool vertex_stack_peek(const VertexStack *stack, size_t *vertex)
{
    if (stack->size == 0) return false;
    *vertex = stack->data[stack->size - 1];
    return true;
}
