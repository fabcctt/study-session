#include <iostream>

#include "pointers.hpp"

int main() {
    int first = 10;
    int second = 20;

    int *current = &first;

    std::cout << "=== Pointer & Reference Lab ===\n";

    std::cout << "\nInitial values:\n";
    std::cout << "First: " << first << '\n';
    std::cout << "Second: " << second << '\n';

    std::cout << "\nPointer information:\n";
    std::cout << "Address: "
              << static_cast<const void *>(current) << '\n';
    std::cout << "Pointed value: " << *current << '\n';

    // Modify using a reference
    pointers::add_value(first, 5);

    std::cout << "\nAfter reference update:\n";
    std::cout << "First: " << first << '\n';

    // Swap using pointers
    if (!pointers::swap_values(&first, &second)) {
        std::cerr << "Error swapping values.\n";
        return 1;
    }

    std::cout << "\nAfter pointer swap:\n";
    std::cout << "First: " << first << '\n';
    std::cout << "Second: " << second << '\n';

    // Redirect using a double pointer
    if (!pointers::redirect_pointer(&current, &second)) {
        std::cerr << "Error redirecting pointer.\n";
        return 1;
    }

    std::cout << "\nAfter pointer redirection:\n";
    std::cout << "Pointed value: " << *current << '\n';

    // Modify the new target
    *current = 99;

    std::cout << "\nFinal values:\n";
    std::cout << "First: " << first << '\n';
    std::cout << "Second: " << second << '\n';

    return 0;
}
