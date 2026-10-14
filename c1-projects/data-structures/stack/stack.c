#include "stack.h"
#include <stdlib.h>

struct StackNode {
    int value;
    struct StackNode *next;
};

void stack_init(Stack *stack)
{
    *stack = (Stack){0};
}

void stack_destroy(Stack *stack)
{
    int value;
    while (stack_pop(stack, &value)) { }
}

bool stack_push(Stack *stack, int value)
{
    StackNode *node = malloc(sizeof(*node));
    if (node == NULL) return false;
    *node = (StackNode){value, stack->top};
    stack->top = node;
    ++stack->size;
    return true;
}

bool stack_pop(Stack *stack, int *value)
{
    if (stack->top == NULL) return false;
    StackNode *node = stack->top;
    *value = node->value;
    stack->top = node->next;
    free(node);
    --stack->size;
    return true;
}

bool stack_peek(const Stack *stack, int *value)
{
    if (stack->top == NULL) return false;
    *value = stack->top->value;
    return true;
}
