#include "trie.h"
#include <stdlib.h>

struct TrieNode {
    struct TrieNode *children[26];
    bool terminal;
};

static bool valid_word(const char *word)
{
    size_t length = 0;
    while (word[length] != '\0') {
        if (length == TRIE_MAX_WORD_LENGTH || word[length] < 'a' || word[length] > 'z')
            return false;
        ++length;
    }
    return true;
}

static void destroy_node(TrieNode *node)
{
    if (node == NULL) return;
    for (size_t i = 0; i < 26; ++i) destroy_node(node->children[i]);
    free(node);
}

bool trie_init(Trie *trie)
{
    *trie = (Trie){0};
    trie->root = calloc(1, sizeof(*trie->root));
    return trie->root != NULL;
}

void trie_destroy(Trie *trie)
{
    destroy_node(trie->root);
    *trie = (Trie){0};
}

static const TrieNode *find_node(const Trie *trie, const char *word)
{
    if (!valid_word(word)) return NULL;
    const TrieNode *node = trie->root;
    for (size_t i = 0; word[i] != '\0' && node != NULL; ++i)
        node = node->children[(size_t)(word[i] - 'a')];
    return node;
}

bool trie_insert(Trie *trie, const char *word)
{
    if (trie->root == NULL || !valid_word(word)) return false;
    TrieNode *node = trie->root;
    size_t i = 0;
    while (word[i] != '\0' && node->children[(size_t)(word[i] - 'a')] != NULL) {
        node = node->children[(size_t)(word[i] - 'a')];
        ++i;
    }
    if (word[i] != '\0') {
        /* Build a detached suffix so allocation failure changes nothing. */
        TrieNode *suffix = calloc(1, sizeof(*suffix));
        if (suffix == NULL) return false;
        TrieNode *last = suffix;
        for (size_t j = i + 1; word[j] != '\0'; ++j) {
            TrieNode *child = calloc(1, sizeof(*child));
            if (child == NULL) {
                destroy_node(suffix);
                return false;
            }
            last->children[(size_t)(word[j] - 'a')] = child;
            last = child;
        }
        node->children[(size_t)(word[i] - 'a')] = suffix;
        node = last;
    }
    if (!node->terminal) {
        node->terminal = true;
        ++trie->word_count;
    }
    return true;
}

bool trie_contains(const Trie *trie, const char *word)
{
    const TrieNode *node = find_node(trie, word);
    return node != NULL && node->terminal;
}

bool trie_has_prefix(const Trie *trie, const char *prefix)
{
    return find_node(trie, prefix) != NULL;
}

static bool prune(TrieNode *node, const char *word)
{
    if (*word == '\0') node->terminal = false;
    else {
        size_t index = (size_t)(*word - 'a');
        if (prune(node->children[index], word + 1)) {
            free(node->children[index]);
            node->children[index] = NULL;
        }
    }
    if (node->terminal) return false;
    for (size_t i = 0; i < 26; ++i)
        if (node->children[i] != NULL) return false;
    return true;
}

bool trie_remove(Trie *trie, const char *word)
{
    if (!trie_contains(trie, word)) return false;
    (void)prune(trie->root, word); /* Keep the root, even when empty. */
    --trie->word_count;
    return true;
}
