#include "headers_separate_compilation.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    printf("Maximum: %d\n", maximum(14, 9));
    return EXIT_SUCCESS;
}
