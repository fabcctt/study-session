#include "queue.h"
#include <stdint.h>
#include <stdlib.h>

bool vertex_queue_init(VertexQueue *queue, size_t capacity)
{
    *queue = (VertexQueue){0};
    if (capacity == 0) return true;
    if (capacity > SIZE_MAX / sizeof(size_t)) return false;
    queue->data = malloc(capacity * sizeof(*queue->data));
    if (queue->data == NULL) return false;
    queue->capacity = capacity;
    return true;
}

void vertex_queue_destroy(VertexQueue *queue)
{
    free(queue->data);
    *queue = (VertexQueue){0};
}

bool vertex_queue_push(VertexQueue *queue, size_t vertex)
{
    if (queue->size == queue->capacity) return false;
    /* Avoid overflow in head + size. */
    size_t remaining = queue->capacity - queue->head;
    size_t tail = queue->size >= remaining ? queue->size - remaining : queue->head + queue->size;
    queue->data[tail] = vertex;
    ++queue->size;
    return true;
}

bool vertex_queue_pop(VertexQueue *queue, size_t *vertex)
{
    if (queue->size == 0) return false;
    *vertex = queue->data[queue->head];
    queue->head = queue->head + 1 == queue->capacity ? 0 : queue->head + 1;
    --queue->size;
    return true;
}
