#include "syntax_fundamentals.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>

#ifdef NDEBUG
#error "Tests require enabled assertions"
#endif

int main(void) {
    unsigned total = 99;
    assert(sum_to(0, &total) && total == 0);
    assert(sum_to(10, &total) && total == 55);
    assert(!sum_to(1, NULL));
    assert(!sum_to(UINT_MAX, &total));
    assert(total == 55);
    puts("All syntax_fundamentals tests passed.");
    return 0;
}
