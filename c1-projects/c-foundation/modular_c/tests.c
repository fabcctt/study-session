#include "modular_c.h"
#include <assert.h>
#include <stdio.h>
#include <errno.h>

#ifdef NDEBUG
#error "Tests require enabled assertions"
#endif

int main(void) {
    Statistics stats = {0};
    double mean = 99;
    assert(!statistics_mean(&stats, &mean) && mean == 99);
    statistics_add(&stats, -10);
    statistics_add(&stats, 20);
    assert(statistics_mean(&stats, &mean) && mean == 5);
    assert(stats.count == 2);
    assert(!statistics_mean(NULL, &mean));
    assert(!statistics_mean(&stats, NULL));
    puts("All modular_c tests passed.");
    return 0;
}
