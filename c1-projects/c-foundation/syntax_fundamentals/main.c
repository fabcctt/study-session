#include "syntax_fundamentals.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    unsigned total;
    if (!sum_to(10, &total)) return EXIT_FAILURE;
    printf("Sum from 1 to 10: %u\n", total);
    return EXIT_SUCCESS;
}
