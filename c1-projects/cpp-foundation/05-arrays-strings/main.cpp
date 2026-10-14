#include <iostream>
#include <string>

#include "words.hpp"

int main() {
    words::WordList list;

    std::cout << "=== Word Analyzer ===\n";
    std::cout << "Enter 5 words:\n";

    for (std::size_t i = 0; i < list.size(); i++) {
        std::cout << "Word " << i + 1 << ": ";

        if (!(std::cin >> list[i])) {
            std::cerr << "Invalid input.\n";
            return 1;
        }
    }

    words::print_words(list);

    std::cout << "\nLongest word: "
              << words::longest_word(list) << '\n';

    std::cout << "\nVowel count:\n";

    for (const std::string &word : list) {
        std::cout << word << ": "
                  << words::count_vowels(word)
                  << '\n';
    }

    std::string target;

    std::cout << "\nSearch for a word: ";

    if (!(std::cin >> target)) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    int position = words::find_word(list, target);

    if (position != -1) {
        std::cout << "Word found at position: "
                  << position + 1 << '\n';
    } else {
        std::cout << "Word not found.\n";
    }

    return 0;
}
