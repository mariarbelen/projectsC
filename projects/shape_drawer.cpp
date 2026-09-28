// ASCII Shape Drawer
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science
//
// Draws a filled square, a hollow square or a right triangle of asterisks
// in a size the user chooses. Demonstrates nested loops and a menu loop.

#include <iostream>
#include <limits>

void drawFilledSquare(int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

void drawHollowSquare(int size) {
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size; col++) {
            bool onEdge = row == 1 || row == size || col == 1 || col == size;
            std::cout << (onEdge ? "* " : "  ");
        }
        std::cout << '\n';
    }
}

void drawTriangle(int size) {
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= row; col++) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

// Reads an integer in [low, high], re-prompting on bad input.
// Returns false at end of input.
bool readInt(int low, int high, int& value) {
    while (true) {
        if (std::cin >> value) {
            if (value >= low && value <= high) {
                return true;
            }
        } else if (std::cin.eof()) {
            return false;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Please enter a number from " << low << " to " << high << ": ";
    }
}

int main() {
    const int MAX_SIZE = 30;

    while (true) {
        std::cout << "\nWhich shape would you like to draw?\n"
                  << "  1 - Filled square\n"
                  << "  2 - Hollow square\n"
                  << "  3 - Triangle\n"
                  << "  4 - Exit\n"
                  << "Enter choice: ";

        int choice;
        if (!readInt(1, 4, choice) || choice == 4) {
            break;
        }

        std::cout << "Enter the size (1-" << MAX_SIZE << "): ";
        int size;
        if (!readInt(1, MAX_SIZE, size)) {
            break;
        }
        std::cout << '\n';

        switch (choice) {
            case 1: drawFilledSquare(size); break;
            case 2: drawHollowSquare(size); break;
            case 3: drawTriangle(size); break;
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
