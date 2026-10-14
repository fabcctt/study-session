#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Stack stack;
    stack_init(&stack);
    for (int value = 10; value <= 30; value += 10) {
        if (!stack_push(&stack, value)) {
            fputs("Could not push onto the stack.\n", stderr);
            stack_destroy(&stack);
            return EXIT_FAILURE;
        }
    }
    printf("LIFO order:");
    int value;
    while (stack_pop(&stack, &value)) printf(" %d", value);
    puts("");
    stack_destroy(&stack);
    return EXIT_SUCCESS;
}
