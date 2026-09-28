// String Toolkit
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science (Programming Project 11)
//
// A menu-driven program that analyzes and transforms a line of text:
// count vowels and consonants, convert case, and replace the string.

#include <cctype>
#include <iostream>
#include <string>

bool isVowel(char c) {
    switch (std::tolower(static_cast<unsigned char>(c))) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}

int countVowels(const std::string& text) {
    int count = 0;
    for (char c : text) {
        if (isVowel(c)) {
            count++;
        }
    }
    return count;
}

// Consonants are letters that are not vowels (spaces, digits and
// punctuation are not counted).
int countConsonants(const std::string& text) {
    int count = 0;
    for (char c : text) {
        if (std::isalpha(static_cast<unsigned char>(c)) && !isVowel(c)) {
            count++;
        }
    }
    return count;
}

void toUpper(std::string& text) {
    for (char& c : text) {
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }
}

void toLower(std::string& text) {
    for (char& c : text) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
}

void showMenu() {
    std::cout << "\nA) Count the vowels in the string\n"
              << "B) Count the consonants in the string\n"
              << "C) Convert the string to uppercase\n"
              << "D) Convert the string to lowercase\n"
              << "E) Display the current string\n"
              << "F) Enter a new string\n"
              << "G) Exit\n"
              << "Enter your menu selection: ";
}

int main() {
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    std::string line;
    while (true) {
        showMenu();
        if (!std::getline(std::cin, line)) {
            break;
        }
        if (line.empty()) {
            continue;
        }
        char choice = static_cast<char>(std::toupper(static_cast<unsigned char>(line[0])));
        if (choice == 'G') {
            break;
        }

        switch (choice) {
            case 'A':
                std::cout << "The string has " << countVowels(text) << " vowel(s).\n";
                break;
            case 'B':
                std::cout << "The string has " << countConsonants(text) << " consonant(s).\n";
                break;
            case 'C':
                toUpper(text);
                std::cout << text << '\n';
                break;
            case 'D':
                toLower(text);
                std::cout << text << '\n';
                break;
            case 'E':
                std::cout << text << '\n';
                break;
            case 'F':
                std::cout << "Enter a new string: ";
                std::getline(std::cin, text);
                break;
            default:
                std::cout << "Invalid choice. Please pick A-G.\n";
                break;
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
