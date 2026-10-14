#include "list.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
    List list;
    list_init(&list);
    int value = -1;
    assert(!list_pop_front(&list, &value) && value == -1);
    assert(!list_remove_first(&list, 10));
    assert(list_push_back(&list, 10));
    assert(list_push_back(&list, 20));
    assert(list_push_front(&list, 0));
    assert(list_push_back(&list, 20));
    assert(list_remove_first(&list, 20));
    assert(list.size == 3 && list_contains(&list, 20));
    assert(list_remove_first(&list, 0));
    assert(list.head->value == 10);
    assert(list_remove_first(&list, 20));
    assert(list.tail == list.head && list.tail->next == NULL);
    assert(list_remove_first(&list, 10));
    assert(list.size == 0 && list.head == NULL && list.tail == NULL);
    for (int i = 0; i < 1000; ++i) assert(list_push_back(&list, i));
    for (int i = 0; i < 1000; ++i)
        assert(list_pop_front(&list, &value) && value == i);
    assert(list_push_front(&list, 99));
    list_destroy(&list);
    assert(list.head == NULL && list.tail == NULL && list.size == 0);
    list_destroy(&list);
    puts("Linked list: all tests passed.");
    return 0;
}
