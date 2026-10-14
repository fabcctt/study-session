#include "words.hpp"
#include <iostream>

namespace words {

void print_words(const WordList &list) {
    std::cout << "\nWord List:\n";

    for (std::size_t i = 0; i < list.size(); i++) {
        std::cout << i + 1 << ". "
                  << list[i] << '\n';
    }
}

int find_word(
    const WordList &list,
    const std::string &target
) {
    for (std::size_t i = 0; i < list.size(); i++) {
        if (list[i] == target)
            return static_cast<int>(i);
    }

    return -1;
}

std::string longest_word(const WordList &list) {
    std::string longest = list[0];

    for (std::size_t i = 1; i < list.size(); i++) {
        if (list[i].length() > longest.length()) {
            longest = list[i];
        }
    }

    return longest;
}

int count_vowels(const std::string &word) {
    int count = 0;

    for (char character : word) {
        switch (character) {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o': case 'O':
            case 'u': case 'U':
                count++;
                break;
        }
    }

    return count;
}

}
