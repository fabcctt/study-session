#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Trie trie;
    if (!trie_init(&trie)) {
        fputs("Could not initialize the trie.\n", stderr);
        return EXIT_FAILURE;
    }
    const char *words[] = {"car", "cart", "cat", "code"};
    for (size_t i = 0; i < sizeof(words) / sizeof(words[0]); ++i) {
        if (!trie_insert(&trie, words[i])) {
            fputs("Could not insert a word.\n", stderr);
            trie_destroy(&trie);
            return EXIT_FAILURE;
        }
    }
    printf("Word count: %zu\n", trie.word_count);
    printf("Contains car: %s\n", trie_contains(&trie, "car") ? "yes" : "no");
    printf("Has prefix ca: %s\n", trie_has_prefix(&trie, "ca") ? "yes" : "no");
    trie_remove(&trie, "car");
    printf("After removing car, cart remains: %s\n", trie_contains(&trie, "cart") ? "yes" : "no");
    trie_destroy(&trie);
    return EXIT_SUCCESS;
}
