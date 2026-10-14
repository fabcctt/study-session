#include "union_find.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    UnionFind sets;
    size_t root = 99;
    assert(uf_init(&sets, 0));
    assert(!uf_find(&sets, 0, &root) && root == 99);
    uf_destroy(&sets);
    assert(!uf_init(&sets, SIZE_MAX));
    uf_destroy(&sets);
    assert(uf_init(&sets, 32));
    size_t label[32];
    for (size_t i = 0; i < 32; ++i) label[i] = i;
    /* Compare every connectivity query against a simple label model. */
    for (size_t step = 0; step < 64; ++step) {
        size_t left = (step * 13) % 32;
        size_t right = (step * 7 + 3) % 32;
        size_t old_label = label[right];
        size_t new_label = label[left];
        for (size_t i = 0; i < 32; ++i)
            if (label[i] == old_label) label[i] = new_label;
        assert(uf_union(&sets, left, right));
        size_t components = 0;
        for (size_t i = 0; i < 32; ++i) {
            bool first = true;
            for (size_t j = 0; j < i; ++j)
                if (label[j] == label[i]) first = false;
            if (first) ++components;
            for (size_t j = 0; j < 32; ++j) {
                bool connected;
                assert(uf_connected(&sets, i, j, &connected));
                assert(connected == (label[i] == label[j]));
            }
        }
        assert(sets.components == components);
    }
    size_t before = sets.components;
    assert(uf_union(&sets, 0, 0) && sets.components == before);
    assert(!uf_union(&sets, 0, 32) && sets.components == before);
    bool connected = true;
    assert(!uf_connected(&sets, 32, 0, &connected) && connected);
    for (size_t i = 1; i < 32; ++i) assert(uf_union(&sets, 0, i));
    assert(sets.components == 1);
    uf_destroy(&sets);
    uf_destroy(&sets);
    puts("Union-find: all tests passed.");
    return 0;
}
