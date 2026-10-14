#include "grades.hpp"

#include <iostream>
#include <iomanip>

namespace grades {

bool is_valid(int score) {
    return score >= 0 && score <= 100;
}

double calculate_average(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

int highest_score(int a, int b, int c) {
    int highest = a;

    if (b > highest)
        highest = b;

    if (c > highest)
        highest = c;

    return highest;
}

bool has_passed(double average) {
    return average >= 60.0;
}

void add_bonus(int &score, int bonus) {
    if (!is_valid(score) || bonus < 0)
        return;

    if (bonus >= 100 - score)
        score = 100;
    else
        score += bonus;
}

void print_report(
    const std::string &name,
    int first,
    int second,
    int third
) {
    double average =
        calculate_average(first, second, third);

    int highest =
        highest_score(first, second, third);

    std::cout << "\n=== Student Report ===\n";

    std::cout << "Student: " << name << '\n';

    std::cout << "Scores: "
              << first << ", "
              << second << ", "
              << third << '\n';

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Average: " << average << '\n';
    std::cout << "Highest: " << highest << '\n';

    std::cout << "Passed: "
              << (has_passed(average) ? "Yes" : "No")
              << '\n';
}

}
