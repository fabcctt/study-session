#ifndef TRIE_H
#define TRIE_H
#include <stdbool.h>
#include <stddef.h>

#define TRIE_MAX_WORD_LENGTH 128
typedef struct TrieNode TrieNode;
typedef struct {
    TrieNode *root;
    size_t word_count;
} Trie;

/* Lowercase ASCII words only, including the empty word; maximum 128 letters.
 * Owns all nodes. Object/string pointers must be valid. No shallow copies. */
bool trie_init(Trie *trie);
void trie_destroy(Trie *trie);
bool trie_insert(Trie *trie, const char *word);
bool trie_contains(const Trie *trie, const char *word);
bool trie_has_prefix(const Trie *trie, const char *prefix);
bool trie_remove(Trie *trie, const char *word);
#endif
