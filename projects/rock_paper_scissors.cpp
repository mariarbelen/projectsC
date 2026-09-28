// Rock, Paper, Scissors
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science (Programming Project 4)
//
// Play a chosen number of rounds against the computer, which picks at
// random each round. Keeps score of wins, losses and ties.

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

std::string moveName(char move) {
    switch (move) {
        case 'R': return "Rock";
        case 'P': return "Paper";
        case 'S': return "Scissors";
    }
    return "?";
}

char computerChoice() {
    const char moves[] = {'R', 'P', 'S'};
    return moves[std::rand() % 3];
}

// Returns true if move a beats move b.
bool beats(char a, char b) {
    return (a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P');
}

// Reads R, P or S (any case, or the full word). Returns false at end of input.
bool readMove(char& move) {
    std::string input;
    while (std::cin >> input) {
        move = static_cast<char>(std::toupper(static_cast<unsigned char>(input[0])));
        if (move == 'R' || move == 'P' || move == 'S') {
            return true;
        }
        std::cout << "Please enter R, P or S: ";
    }
    return false;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int rounds;
    std::cout << "How many rounds do you want to play? ";
    while (!(std::cin >> rounds) || rounds < 1) {
        if (std::cin.eof()) {
            return 1;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a positive number: ";
    }

    int playerWins = 0, computerWins = 0, ties = 0;

    for (int round = 1; round <= rounds; round++) {
        std::cout << "\nRound " << round << " of " << rounds
                  << " - choose (R)ock, (P)aper or (S)cissors: ";
        char player;
        if (!readMove(player)) {
            break;
        }
        char computer = computerChoice();

        std::cout << "You chose " << moveName(player) << ", the computer chose "
                  << moveName(computer) << ". ";
        if (player == computer) {
            std::cout << "It's a tie.\n";
            ties++;
        } else if (beats(player, computer)) {
            std::cout << "You win!\n";
            playerWins++;
        } else {
            std::cout << "You lose.\n";
            computerWins++;
        }
        std::cout << "Score - You: " << playerWins << "  Computer: " << computerWins
                  << "  Ties: " << ties << '\n';
    }

    std::cout << "\nFinal result: ";
    if (playerWins > computerWins) {
        std::cout << "You won the match!\n";
    } else if (computerWins > playerWins) {
        std::cout << "The computer won the match.\n";
    } else {
        std::cout << "The match is a draw.\n";
    }
    return 0;
}
