#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
#include <stddef.h>

typedef struct QueueNode QueueNode;
typedef struct {
    QueueNode *front;
    QueueNode *back;
    size_t size;
} Queue;

/* Owns its nodes. Initialize before use; pointers must be valid. */
void queue_init(Queue *queue);
void queue_destroy(Queue *queue);
bool queue_enqueue(Queue *queue, int value);
bool queue_dequeue(Queue *queue, int *value);
bool queue_peek(const Queue *queue, int *value);
#endif
