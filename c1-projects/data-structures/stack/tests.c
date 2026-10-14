#include "stack.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
    Stack stack;
    stack_init(&stack);
    int value = -1;
    assert(!stack_pop(&stack, &value) && value == -1);
    assert(!stack_peek(&stack, &value));
    for (int i = 0; i < 1000; ++i) assert(stack_push(&stack, i));
    assert(stack_peek(&stack, &value) && value == 999 && stack.size == 1000);
    for (int i = 999; i >= 0; --i) assert(stack_pop(&stack, &value) && value == i);
    assert(stack.size == 0 && stack.top == NULL);
    assert(stack_push(&stack, -42));
    assert(stack_push(&stack, -42));
    assert(stack_pop(&stack, &value) && value == -42);
    stack_destroy(&stack);
    stack_destroy(&stack);
    assert(stack.size == 0 && stack.top == NULL);
    puts("Stack: all tests passed.");
    return 0;
}
