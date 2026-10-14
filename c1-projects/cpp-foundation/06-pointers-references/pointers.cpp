#include "pointers.hpp"

namespace pointers {

void add_value(int &number, int amount) {
    number += amount;
}

bool swap_values(int *first, int *second) {
    if (first == nullptr || second == nullptr)
        return false;

    int temp = *first;

    *first = *second;
    *second = temp;

    return true;
}

bool redirect_pointer(int **pointer, int *target) {
    if (pointer == nullptr || target == nullptr)
        return false;

    *pointer = target;

    return true;
}

}
