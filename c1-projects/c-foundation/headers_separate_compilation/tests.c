#include "headers_separate_compilation.h"
#include <assert.h>
#include <stdio.h>
#include <errno.h>

#ifdef NDEBUG
#error "Tests require enabled assertions"
#endif

int main(void) {
    assert(maximum(14, 9) == 14);
    assert(maximum(-3, -8) == -3);
    assert(maximum(4, 4) == 4);
    puts("All headers_separate_compilation tests passed.");
    return 0;
}
