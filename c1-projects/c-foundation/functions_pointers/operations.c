#include "operations.h"

#include <stddef.h>

int add (int a, int b) {
    return a + b;
}
int multiply (int a, int b) {
    return a * b;
}

bool calculate (int a, int b, Operation operation, int *result) {
    if (!operation || !result) {
        return false;
    }

*result = operation(a, b);

return true;

}