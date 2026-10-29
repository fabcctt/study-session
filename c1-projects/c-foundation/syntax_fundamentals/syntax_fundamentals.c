#include "syntax_fundamentals.h"
#include <limits.h>
#include <errno.h>

bool sum_to(unsigned n, unsigned *out) {
    if (out == NULL) return false;
    unsigned total = 0;
    for (unsigned i = 1; i <= n; ++i) {
        if (UINT_MAX - total < i) return false;
        total += i;
        if (i == n) break;
    }
    *out = total;
    return true;
}
