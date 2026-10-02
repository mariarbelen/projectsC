// Phone Book Lookup
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science
//
// Stores names and phone numbers in parallel arrays and lets the user look
// up a phone number by name (case-insensitive) as many times as they like.

#include <cctype>
#include <iostream>
#include <string>

std::string toLower(std::string text) {
    for (char& c : text) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return text;
}

// Returns the phone number for targetName, or an empty string if not found.
std::string lookupName(const std::string& targetName, const std::string names[],
                       const std::string phoneNumbers[], int size) {
    for (int i = 0; i < size; i++) {
        if (toLower(names[i]) == toLower(targetName)) {
            return phoneNumbers[i];
        }
    }
    return "";
}

int main() {
    const int SIZE = 4;
    const std::string names[SIZE] = {"Michael Myers", "Ash Williams", "Jack Torrance", "Freddy Krueger"};
    const std::string phoneNumbers[SIZE] = {"333-8000", "333-2323", "333-6150", "339-7970"};

    std::string answer = "y";
    while (!answer.empty() && std::tolower(static_cast<unsigned char>(answer[0])) == 'y') {
        std::cout << "Enter a name to find the corresponding phone number: ";
        std::string targetName;
        if (!std::getline(std::cin, targetName)) {
            break;
        }

        std::string phone = lookupName(targetName, names, phoneNumbers, SIZE);
        if (!phone.empty()) {
            std::cout << "The number is: " << phone << '\n';
        } else {
            std::cout << "Name not found.\n";
        }

        std::cout << "Look up another name? (y/n): ";
        if (!std::getline(std::cin, answer)) {
            break;
        }
    }
    return 0;
}
