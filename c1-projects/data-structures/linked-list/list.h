#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
#include <stddef.h>

typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

/* Owns its nodes. All object and output pointers must be valid. */
typedef struct {
    ListNode *head;
    ListNode *tail;
    size_t size;
} List;

void list_init(List *list);
void list_destroy(List *list);
bool list_push_front(List *list, int value);
bool list_push_back(List *list, int value);
bool list_pop_front(List *list, int *value);
bool list_remove_first(List *list, int value);
bool list_contains(const List *list, int value);
#endif
