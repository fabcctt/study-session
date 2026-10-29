#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <stdbool.h>

typedef int (*Operation) (int, int);

int add (int a, int b);
int multiply (int a, int b);

bool calculate(int a, int b, Operation operation, int *result);

#endif