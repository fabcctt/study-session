#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Queue queue;
    queue_init(&queue);
    for (int value = 10; value <= 30; value += 10) {
        if (!queue_enqueue(&queue, value)) {
            fputs("Could not enqueue a value.\n", stderr);
            queue_destroy(&queue);
            return EXIT_FAILURE;
        }
    }
    printf("FIFO order:");
    int value;
    while (queue_dequeue(&queue, &value)) printf(" %d", value);
    puts("");
    queue_destroy(&queue);
    return EXIT_SUCCESS;
}
