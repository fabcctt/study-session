#include "modular_c.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    Statistics stats = {0};
    statistics_add(&stats, 10.0);
    statistics_add(&stats, 20.0);
    double mean;
    if (!statistics_mean(&stats, &mean)) return EXIT_FAILURE;
    printf("Count: %zu, mean: %.1f\n", stats.count, mean);
    return EXIT_SUCCESS;
}
