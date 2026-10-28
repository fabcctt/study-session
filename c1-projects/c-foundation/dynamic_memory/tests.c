#include "dynamic_memory.h"

#include <assert.h>
#include <stdio.h>

static void test_initialization(void) {
    IntBuffer buffer = {0};

    assert(buffer_init(&buffer, 3));
    assert(buffer.size == 0);
    assert(buffer.capacity == 3);

    for (size_t i = 0; i < 3; i++) {
        assert(buffer.data[i] == 0);
    }

    buffer_free(&buffer);
}

static void test_growth(void) {
    IntBuffer buffer = {0};

    assert(buffer_init(&buffer, 1));

    for (int i = 0; i < 10; i++) {
        assert(buffer_push(&buffer, i * 5));
    }

    assert(buffer.size == 10);
    assert(buffer.capacity >= 10);

    int value = 0;

    assert(buffer_get(&buffer, 4, &value));
    assert(value == 20);

    assert(!buffer_get(&buffer, 10, &value));
    assert(!buffer_get(&buffer, 0, NULL));

    buffer_free(&buffer);
}

static void test_clone(void) {
    IntBuffer original = {0};
    IntBuffer copy = {0};

    assert(buffer_init(&original, 2));
    assert(buffer_push(&original, 42));
    assert(buffer_clone(&original, &copy));

    assert(original.data != copy.data);
    assert(copy.data[0] == 42);

    copy.data[0] = 99;

    assert(original.data[0] == 42);
    assert(copy.data[0] == 99);

    buffer_free(&copy);
    buffer_free(&original);
}

static void test_empty_buffer(void) {
    IntBuffer buffer = {0};

    assert(buffer_init(&buffer, 0));
    assert(buffer.data == NULL);

    assert(buffer_push(&buffer, 15));
    assert(buffer.size == 1);

    buffer_free(&buffer);

    assert(buffer.data == NULL);
    assert(buffer.size == 0);
    assert(buffer.capacity == 0);
}

int main(void) {
    test_initialization();
    test_growth();
    test_clone();
    test_empty_buffer();

    printf("All dynamic memory tests passed.\n");

    return 0;
}