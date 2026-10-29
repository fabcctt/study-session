#include "modular_c.h"
#include <errno.h>

void statistics_add(Statistics *stats, double value) {
    if (stats == NULL) return;
    stats->sum += value;
    ++stats->count;
}
bool statistics_mean(const Statistics *stats, double *out) {
    if (stats == NULL || out == NULL || stats->count == 0) return false;
    *out = stats->sum / (double)stats->count;
    return true;
}
