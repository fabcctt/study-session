#ifndef SCORES_HPP
#define SCORES_HPP

#include <vector>
#include <map>
#include <cstddef>

namespace scores {

using ScoreList = std::vector<int>;

using FrequencyTable = std::map<int, std::size_t>;

bool add_score(ScoreList &list, int score);

void sort_scores(ScoreList &list);

bool contains_score(const ScoreList &list, int target);

double calculate_average(const ScoreList &list);

FrequencyTable count_frequencies(const ScoreList &list);

void print_scores(const ScoreList &list);

void print_frequencies(const FrequencyTable &table);

}

#endif
