#include "queue.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
    Queue queue;
    queue_init(&queue);
    int value = -1;
    assert(!queue_dequeue(&queue, &value) && value == -1);
    assert(!queue_peek(&queue, &value));
    for (int i = 0; i < 500; ++i) assert(queue_enqueue(&queue, i));
    for (int i = 0; i < 250; ++i) assert(queue_dequeue(&queue, &value) && value == i);
    for (int i = 500; i < 1000; ++i) assert(queue_enqueue(&queue, i));
    assert(queue_peek(&queue, &value) && value == 250 && queue.size == 750);
    for (int i = 250; i < 1000; ++i) assert(queue_dequeue(&queue, &value) && value == i);
    assert(queue.size == 0 && queue.front == NULL && queue.back == NULL);
    assert(queue_enqueue(&queue, -42));
    assert(queue_dequeue(&queue, &value) && value == -42);
    assert(queue_enqueue(&queue, 10));
    queue_destroy(&queue);
    queue_destroy(&queue);
    assert(queue.front == NULL && queue.back == NULL && queue.size == 0);
    puts("Queue: all tests passed.");
    return 0;
}
