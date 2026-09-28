// Airplane Seat Reservation
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science (Programming Project 10)
//
// Uses a 2D array to model a small plane with 7 rows of 4 seats (A-D).
// The user books seats one at a time; booked seats are shown as X.
// The program rejects invalid or already-taken seats and stops when the
// user quits or the plane is full.

#include <cctype>
#include <iostream>
#include <limits>

const int ROWS = 7;
const int SEATS_PER_ROW = 4;
const char TAKEN = 'X';

void initSeats(char plane[ROWS][SEATS_PER_ROW]) {
    for (int row = 0; row < ROWS; row++) {
        for (int seat = 0; seat < SEATS_PER_ROW; seat++) {
            plane[row][seat] = static_cast<char>('A' + seat);
        }
    }
}

void showSeats(const char plane[ROWS][SEATS_PER_ROW]) {
    std::cout << '\n';
    for (int row = 0; row < ROWS; row++) {
        std::cout << row + 1 << "  ";
        for (int seat = 0; seat < SEATS_PER_ROW; seat++) {
            std::cout << plane[row][seat] << ' ';
            if (seat == SEATS_PER_ROW / 2 - 1) {
                std::cout << "  ";  // aisle
            }
        }
        std::cout << '\n';
    }
}

bool isFull(const char plane[ROWS][SEATS_PER_ROW]) {
    for (int row = 0; row < ROWS; row++) {
        for (int seat = 0; seat < SEATS_PER_ROW; seat++) {
            if (plane[row][seat] != TAKEN) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char plane[ROWS][SEATS_PER_ROW];
    initSeats(plane);

    std::cout << "Airplane Seat Reservation\n"
              << "There are " << ROWS << " rows with seats A-D. Reserved seats are marked X.\n";

    while (!isFull(plane)) {
        showSeats(plane);
        std::cout << "\nEnter a seat (e.g. 3C), or Q to quit: ";

        int row;
        char seatLetter;
        if (!(std::cin >> row)) {
            if (std::cin.eof()) {
                break;
            }
            std::cin.clear();
            char next;
            std::cin >> next;
            if (std::toupper(static_cast<unsigned char>(next)) == 'Q') {
                break;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }
        std::cin >> seatLetter;
        int seat = std::toupper(static_cast<unsigned char>(seatLetter)) - 'A';

        if (row < 1 || row > ROWS || seat < 0 || seat >= SEATS_PER_ROW) {
            std::cout << "That seat does not exist. Try again.\n";
        } else if (plane[row - 1][seat] == TAKEN) {
            std::cout << "That seat is occupied. Please choose another.\n";
        } else {
            plane[row - 1][seat] = TAKEN;
            std::cout << "Seat " << row << static_cast<char>('A' + seat) << " is booked.\n";
        }
    }

    showSeats(plane);
    if (isFull(plane)) {
        std::cout << "\nThe plane is now full.\n";
    }
    std::cout << "Thank you for using the reservation system.\n";
    return 0;
}
