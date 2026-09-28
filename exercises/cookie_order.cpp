// Cookie Order Calculator
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science
//
// A bakery gives one free cookie for every dozen ordered. Given an order,
// this program reports the free cookies, how the total packs into dozens
// plus loose cookies, and how many chocolate chips (10 per cookie) are needed.

#include <cctype>
#include <iostream>
#include <limits>

const int DOZEN = 12;
const int CHIPS_PER_COOKIE = 10;

int main() {
    char again = 'y';

    while (again == 'y') {
        int ordered;
        std::cout << "Enter the number of cookies you want to order: ";
        if (!(std::cin >> ordered)) {
            if (std::cin.eof()) {
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a whole number.\n";
            continue;
        }
        if (ordered < 0) {
            std::cout << "The order can't be negative.\n";
            continue;
        }

        int freeCookies = ordered / DOZEN;
        int total = ordered + freeCookies;

        if (freeCookies > 0) {
            std::cout << "You also get " << freeCookies << " free cookie(s), one per dozen.\n";
        }
        std::cout << "That comes to " << total / DOZEN << " dozen and "
                  << total % DOZEN << " loose cookie(s).\n"
                  << "The order needs " << total * CHIPS_PER_COOKIE << " chocolate chips.\n";

        std::cout << "Would you like to calculate another order? (y/n): ";
        if (!(std::cin >> again)) {
            break;
        }
        again = static_cast<char>(std::tolower(static_cast<unsigned char>(again)));
    }
    return 0;
}
