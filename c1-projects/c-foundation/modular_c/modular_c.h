#ifndef MODULAR_C_H
#define MODULAR_C_H
#include <stdbool.h>
#include <stddef.h>
typedef struct { size_t count; double sum; } Statistics;
void statistics_add(Statistics *stats, double value);
bool statistics_mean(const Statistics *stats, double *out);

#endif
