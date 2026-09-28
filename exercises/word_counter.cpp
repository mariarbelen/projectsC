// Word and Letter Counter
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science
//
// Reads a line of text, counts the words in it, and shows how many times
// each letter appears (ignoring case).

#include <cctype>
#include <iostream>
#include <string>

int countWords(const std::string& text) {
    int words = 0;
    bool inWord = false;
    for (char c : text) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            inWord = false;
        } else if (!inWord) {
            words++;
            inWord = true;
        }
    }
    return words;
}

int main() {
    std::string text;
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, text);

    std::cout << "Number of words: " << countWords(text) << '\n';

    int letterCount[26] = {0};
    for (char c : text) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (std::isalpha(uc)) {
            letterCount[std::tolower(uc) - 'a']++;
        }
    }

    std::cout << "Letter counts:\n";
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > 0) {
            std::cout << "  " << static_cast<char>('a' + i) << ": " << letterCount[i] << '\n';
        }
    }
    return 0;
}
