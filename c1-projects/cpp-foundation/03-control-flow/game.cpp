#include "game.hpp"

#include <iostream>
#include <limits>
#include <random>

namespace game {

void play() {
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(1, 100);

    const int secret = distribution(generator);
    const int max_attempts = 7;

    int attempts = 0;
    int guess = 0;
    bool won = false;

    std::cout << "\nGuess a number between 1 and 100.\n";
    std::cout << "You have 7 attempts.\n";

    while (attempts < max_attempts) {
        std::cout << "\nEnter your guess: ";

        if (!(std::cin >> guess)) {
            if (std::cin.eof())
                return;

            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout << "Invalid input.\n";
            continue;
        }

        if (guess < 1 || guess > 100) {
            std::cout << "Number out of range.\n";
            continue;
        }

        attempts++;

        if (guess == secret) {
            std::cout << "Correct! You won!\n";
            won = true;
            break;
        }

        if (guess < secret) {
            std::cout << "Too low!\n";
        } else {
            std::cout << "Too high!\n";
        }

        std::cout << "Attempts remaining: "
                  << max_attempts - attempts << '\n';
    }

    if (!won) {
        std::cout << "\nGame over!\n";
        std::cout << "The number was: "
                  << secret << '\n';
    }
}

}
