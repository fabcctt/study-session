#ifndef GRAPH_QUEUE_H
#define GRAPH_QUEUE_H
#include <stdbool.h>
#include <stddef.h>

/* Fixed-capacity circular queue for vertex IDs. Owns data. */
typedef struct {
    size_t *data;
    size_t capacity;
    size_t head;
    size_t size;
} VertexQueue;

bool vertex_queue_init(VertexQueue *queue, size_t capacity);
void vertex_queue_destroy(VertexQueue *queue);
bool vertex_queue_push(VertexQueue *queue, size_t vertex);
bool vertex_queue_pop(VertexQueue *queue, size_t *vertex);
#endif
