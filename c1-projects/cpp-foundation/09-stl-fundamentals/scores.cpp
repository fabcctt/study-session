#include "scores.hpp"

#include <iostream>
#include <algorithm>
#include <numeric>

namespace scores {

bool add_score(ScoreList &list, int score) {
    if (score < 0 || score > 100)
        return false;

    list.push_back(score);
    return true;
}

void sort_scores(ScoreList &list) {
    std::sort(list.begin(), list.end());
}

bool contains_score(const ScoreList &list, int target) {
    return std::find(
        list.begin(),
        list.end(),
        target
    ) != list.end();
}

double calculate_average(const ScoreList &list) {
    if (list.empty())
        return 0.0;

    long long total = std::accumulate(
        list.begin(),
        list.end(),
        0LL
    );

    return static_cast<double>(total) / list.size();
}

FrequencyTable count_frequencies(const ScoreList &list) {
    FrequencyTable table;

    for (int score : list) {
        table[score]++;
    }

    return table;
}

void print_scores(const ScoreList &list) {
    std::cout << "\nScores: ";

    for (int score : list) {
        std::cout << score << " ";
    }

    std::cout << '\n';
}

void print_frequencies(const FrequencyTable &table) {
    std::cout << "\nScore Frequencies:\n";

    for (const auto &entry : table) {
        std::cout << entry.first
                  << ": "
                  << entry.second
                  << '\n';
    }
}

}
