#ifndef GRADES_HPP
#define GRADES_HPP

#include <string>

namespace grades {

bool is_valid(int score);

double calculate_average(int a, int b, int c);

int highest_score(int a, int b, int c);

bool has_passed(double average);

void add_bonus(int &score, int bonus = 5);

void print_report(
    const std::string &name,
    int first,
    int second,
    int third
);

}

#endif