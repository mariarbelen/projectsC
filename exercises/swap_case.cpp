// Swap Case
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science
//
// Reads a line of text and prints it with every uppercase letter turned
// lowercase and every lowercase letter turned uppercase.

#include <cctype>
#include <iostream>
#include <string>

std::string swapCase(const std::string& text) {
    std::string result = text;
    for (char& c : result) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (std::islower(uc)) {
            c = static_cast<char>(std::toupper(uc));
        } else if (std::isupper(uc)) {
            c = static_cast<char>(std::tolower(uc));
        }
    }
    return result;
}

int main() {
    std::string text;
    std::cout << "Enter text: ";
    std::getline(std::cin, text);
    std::cout << swapCase(text) << '\n';
    return 0;
}
