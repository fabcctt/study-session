#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stddef.h>

typedef struct StackNode StackNode;
typedef struct {
    StackNode *top;
    size_t size;
} Stack;

/* Owns its nodes. Initialize before use; pointers must be valid. */
void stack_init(Stack *stack);
void stack_destroy(Stack *stack);
bool stack_push(Stack *stack, int value);
bool stack_pop(Stack *stack, int *value);
bool stack_peek(const Stack *stack, int *value);
#endif
