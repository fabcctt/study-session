#include <iostream>
#include <limits>

#include "game.hpp"

int main() {
    int option = 0;

    do {
        std::cout << "\n=== Number Guessing Game ===\n";
        std::cout << "1. Play\n";
        std::cout << "2. Exit\n";
        std::cout << "Choose an option: ";

        if (!(std::cin >> option)) {
            if (std::cin.eof())
                break;

            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout << "Invalid input.\n";
            continue;
        }

        switch (option) {
            case 1:
                game::play();
                break;

            case 2:
                std::cout << "Goodbye!\n";
                break;

            default:
                std::cout << "Invalid option.\n";
                break;
        }

    } while (option != 2);

    return 0;
}
