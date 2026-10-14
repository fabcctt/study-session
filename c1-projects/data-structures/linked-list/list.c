#include "list.h"
#include <stdlib.h>

void list_init(List *list)
{
    *list = (List){0};
}

void list_destroy(List *list)
{
    ListNode *node = list->head;
    while (node != NULL) {
        ListNode *next = node->next;
        free(node);
        node = next;
    }
    list_init(list);
}

bool list_push_front(List *list, int value)
{
    ListNode *node = malloc(sizeof(*node));
    if (node == NULL) return false;
    *node = (ListNode){value, list->head};
    list->head = node;
    if (list->tail == NULL) list->tail = node;
    ++list->size;
    return true;
}

bool list_push_back(List *list, int value)
{
    ListNode *node = malloc(sizeof(*node));
    if (node == NULL) return false;
    *node = (ListNode){value, NULL};
    if (list->tail != NULL) list->tail->next = node;
    else list->head = node;
    list->tail = node;
    ++list->size;
    return true;
}

bool list_pop_front(List *list, int *value)
{
    if (list->head == NULL) return false;
    ListNode *node = list->head;
    *value = node->value;
    list->head = node->next;
    if (list->head == NULL) list->tail = NULL;
    free(node);
    --list->size;
    return true;
}

bool list_remove_first(List *list, int value)
{
    ListNode *previous = NULL;
    ListNode *node = list->head;
    while (node != NULL && node->value != value) {
        previous = node;
        node = node->next;
    }
    if (node == NULL) return false;
    if (previous != NULL) previous->next = node->next;
    else list->head = node->next;
    if (list->tail == node) list->tail = previous;
    free(node);
    --list->size;
    return true;
}

bool list_contains(const List *list, int value)
{
    for (const ListNode *node = list->head; node != NULL; node = node->next)
        if (node->value == value) return true;
    return false;
}
