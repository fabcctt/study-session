#ifndef WORDS_HPP
#define WORDS_HPP

#include <array>
#include <string>
#include <cstddef>

namespace words {

constexpr std::size_t WORD_COUNT = 5;

using WordList = std::array<std::string, WORD_COUNT>;

void print_words(const WordList &list);

int find_word(
    const WordList &list,
    const std::string &target
);

std::string longest_word(const WordList &list);

int count_vowels(const std::string &word);

}

#endif
