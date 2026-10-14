#include <iostream>
#include <string>
#include <iomanip>

#include "grades.hpp"

int main() {
    std::string student;

    int first;
    int second;
    int third;

    std::cout << "Enter student name: ";
    std::getline(std::cin, student);

    if (student.empty()) {
        std::cerr << "Invalid student name.\n";
        return 1;
    }

    std::cout << "Enter three scores (0-100): ";

    if (!(std::cin >> first >> second >> third)) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    if (!grades::is_valid(first) ||
        !grades::is_valid(second) ||
        !grades::is_valid(third)) {

        std::cerr << "Scores must be between 0 and 100.\n";
        return 1;
    }

    double original_average =
        grades::calculate_average(first, second, third);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nOriginal average: "
              << original_average << '\n';

    grades::add_bonus(third);

    std::cout << "Bonus applied to third score: +5\n";

    grades::print_report(
        student,
        first,
        second,
        third
    );

    return 0;
}
