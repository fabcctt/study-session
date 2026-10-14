#include <iostream>
#include <iomanip>

#include "scores.hpp"

int main() {
    scores::ScoreList list;

    const int values[] = {
        75, 90, 80, 90, 65, 75
    };

    std::cout << "=== STL Score Tracker ===\n";

    for (int value : values) {
        if (!scores::add_score(list, value)) {
            std::cerr << "Invalid score.\n";
            return 1;
        }
    }

    std::cout << "\nOriginal scores:";
    scores::print_scores(list);

    scores::sort_scores(list);

    std::cout << "\nSorted scores:";
    scores::print_scores(list);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nAverage: "
              << scores::calculate_average(list)
              << '\n';

    int target = 90;

    if (scores::contains_score(list, target)) {
        std::cout << "\nScore " << target
                  << " found.\n";
    } else {
        std::cout << "\nScore not found.\n";
    }

    scores::FrequencyTable frequencies =
        scores::count_frequencies(list);

    scores::print_frequencies(frequencies);

    return 0;
}
