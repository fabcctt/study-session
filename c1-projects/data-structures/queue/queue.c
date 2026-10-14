#include "queue.h"
#include <stdlib.h>

struct QueueNode {
    int value;
    struct QueueNode *next;
};

void queue_init(Queue *queue)
{
    *queue = (Queue){0};
}

void queue_destroy(Queue *queue)
{
    int value;
    while (queue_dequeue(queue, &value)) { }
}

bool queue_enqueue(Queue *queue, int value)
{
    QueueNode *node = malloc(sizeof(*node));
    if (node == NULL) return false;
    *node = (QueueNode){value, NULL};
    if (queue->back != NULL) queue->back->next = node;
    else queue->front = node;
    queue->back = node;
    ++queue->size;
    return true;
}

bool queue_dequeue(Queue *queue, int *value)
{
    if (queue->front == NULL) return false;
    QueueNode *node = queue->front;
    *value = node->value;
    queue->front = node->next;
    if (queue->front == NULL) queue->back = NULL;
    free(node);
    --queue->size;
    return true;
}

bool queue_peek(const Queue *queue, int *value)
{
    if (queue->front == NULL) return false;
    *value = queue->front->value;
    return true;
}
