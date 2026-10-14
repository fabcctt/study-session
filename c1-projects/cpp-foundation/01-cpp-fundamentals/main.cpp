#include <iostream>
#include "calculator.hpp"

int main() {
    double first;
    double second;
    double result;

    char operation;

    std::cout << "Enter an expression (e.g. 12 + 5): ";

    if (!(std::cin >> first >> operation >> second)) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    switch (operation) {
        case '+':
            result = calculator::add(first, second);
            break;

        case '-':
            result = calculator::subtract(first, second);
            break;

        case '*':
            result = calculator::multiply(first, second);
            break;

        case '/':
            if (second == 0) {
                std::cerr << "Error: Division by zero.\n";
                return 1;
            }

            result = calculator::divide(first, second);
            break;

        default:
            std::cerr << "Invalid operation.\n";
            return 1;
    }

    std::cout << "Result: " << result << '\n';

    return 0;
}
