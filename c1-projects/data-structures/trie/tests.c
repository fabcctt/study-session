#include "trie.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    Trie trie;
    assert(trie_init(&trie));
    assert(!trie_contains(&trie, ""));
    assert(trie_has_prefix(&trie, ""));
    assert(trie_insert(&trie, ""));
    assert(trie_contains(&trie, ""));
    assert(trie_insert(&trie, "car") && trie_insert(&trie, "cart"));
    assert(trie_insert(&trie, "cat") && trie_insert(&trie, "car"));
    assert(trie.word_count == 4);
    assert(trie_has_prefix(&trie, "ca") && !trie_contains(&trie, "ca"));
    assert(!trie_insert(&trie, "new!"));
    assert(!trie_has_prefix(&trie, "new"));
    assert(!trie_insert(&trie, "Car") && !trie_contains(&trie, "Car"));
    assert(!trie_remove(&trie, "missing"));
    assert(trie_remove(&trie, "car") && !trie_contains(&trie, "car"));
    assert(trie_contains(&trie, "cart") && trie_contains(&trie, "cat"));
    assert(trie_remove(&trie, "cart"));
    assert(!trie_has_prefix(&trie, "car") && trie_has_prefix(&trie, "ca"));
    assert(trie_remove(&trie, "cat") && trie_remove(&trie, ""));
    assert(trie.word_count == 0 && !trie_has_prefix(&trie, "c"));
    char word[TRIE_MAX_WORD_LENGTH + 2];
    memset(word, 'a', sizeof(word));
    word[TRIE_MAX_WORD_LENGTH] = '\0';
    assert(trie_insert(&trie, word) && trie_contains(&trie, word));
    assert(trie_remove(&trie, word));
    word[TRIE_MAX_WORD_LENGTH] = 'a';
    word[TRIE_MAX_WORD_LENGTH + 1] = '\0';
    assert(!trie_insert(&trie, word) && trie.word_count == 0);
    trie_destroy(&trie);
    trie_destroy(&trie);
    puts("Trie: all tests passed.");
    return 0;
}
