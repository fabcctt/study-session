#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    List list;
    list_init(&list);
    if (!list_push_back(&list, 20) || !list_push_front(&list, 10) ||
        !list_push_back(&list, 30)) {
        fputs("Could not allocate a list node.\n", stderr);
        list_destroy(&list);
        return EXIT_FAILURE;
    }
    printf("List:");
    for (const ListNode *node = list.head; node != NULL; node = node->next)
        printf(" %d", node->value);
    printf("\nContains 20: %s\n", list_contains(&list, 20) ? "yes" : "no");
    list_remove_first(&list, 20);
    printf("After removing 20:");
    int value;
    while (list_pop_front(&list, &value)) printf(" %d", value);
    puts("");
    list_destroy(&list);
    return EXIT_SUCCESS;
}
