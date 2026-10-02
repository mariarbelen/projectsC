// Virtual Pet Simulator
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science (Term Project)
//
// A text-based Tamagotchi-style game. The player names a pet and keeps it
// fed, clean and happy. Every action lets time pass: the pet's stats drop,
// it ages, and if it gets too dirty it may fall sick. The game ends when the
// pet reaches old age, passes away, or the player quits.

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

// Stats run from 0 (worst) to MAX_STAT (best).
const int MAX_STAT = 20;
const int MAX_AGE = 40;

enum class Mood { Happy, Okay, Frustrated, Mad };

struct VirtualPet {
    std::string name;
    int age = 0;
    int fullness = MAX_STAT;
    int cleanliness = MAX_STAT;
    int happiness = MAX_STAT;
};

// Reads an integer in [low, high], re-prompting on invalid input.
// Returns false if input ends (e.g. Ctrl+D).
bool readChoice(int low, int high, int& choice) {
    while (true) {
        if (std::cin >> choice) {
            if (choice >= low && choice <= high) {
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

int clampStat(int value) {
    return std::clamp(value, 0, MAX_STAT);
}

Mood getMood(const VirtualPet& pet) {
    int average = (pet.fullness + pet.cleanliness + pet.happiness) / 3;

    if (average > 16) return Mood::Happy;
    if (average > 11) return Mood::Okay;
    if (average > 6) return Mood::Frustrated;
    return Mood::Mad;
}

std::string moodName(Mood mood) {
    switch (mood) {
        case Mood::Happy: return "happy";
        case Mood::Okay: return "okay";
        case Mood::Frustrated: return "frustrated";
        case Mood::Mad: return "mad";
    }
    return "unknown";
}

// Picks one of four descriptions depending on how high a stat is.
std::string describe(int stat, const std::string& great, const std::string& good,
                     const std::string& fair, const std::string& poor) {
    if (stat > 16) return great;
    if (stat > 11) return good;
    if (stat > 6) return fair;
    return poor;
}

void talk(const VirtualPet& pet) {
    std::cout << "\n--- " << pet.name << " ---\n"
              << "Age:         " << pet.age << " / " << MAX_AGE << '\n'
              << "Fullness:    " << pet.fullness << " / " << MAX_STAT << '\n'
              << "Cleanliness: " << pet.cleanliness << " / " << MAX_STAT << '\n'
              << "Happiness:   " << pet.happiness << " / " << MAX_STAT << '\n'
              << pet.name << " is feeling " << moodName(getMood(pet)) << ".\n"
              << describe(pet.fullness, "It is full!", "It is not hungry.",
                          "It is somewhat hungry.", "It is starving!") << '\n'
              << describe(pet.happiness, "It is thrilled!", "It is content.",
                          "It is bored.", "It is unhappy!") << '\n'
              << describe(pet.cleanliness, "It is spotless!", "It is fairly clean.",
                          "It is kind of smelly.", "It is filthy!") << '\n';
}

// Shows a small menu of activities and returns the stat boost of the one chosen.
bool chooseActivity(const std::string& question, const std::string options[],
                    const int amounts[], int count, int& boost) {
    std::cout << question << '\n';
    for (int i = 0; i < count; i++) {
        std::cout << "  " << i + 1 << ". " << options[i] << " (+" << amounts[i] << ")\n";
    }
    std::cout << "> ";

    int choice;
    if (!readChoice(1, count, choice)) {
        return false;
    }
    boost = amounts[choice - 1];
    return true;
}

bool feed(VirtualPet& pet) {
    const std::string options[] = {"Rice", "Fruit", "Treat"};
    const int amounts[] = {6, 4, 2};
    int boost;
    if (!chooseActivity("What do you want to feed " + pet.name + "?", options, amounts, 3, boost)) {
        return false;
    }
    pet.fullness = clampStat(pet.fullness + boost);
    if (boost == 2) {
        pet.happiness = clampStat(pet.happiness + 2);  // treats are fun too
    }
    std::cout << pet.name << " has been fed!\n";
    return true;
}

bool play(VirtualPet& pet) {
    const std::string options[] = {"Fetch the ball", "Go for a run"};
    const int amounts[] = {5, 4};
    int boost;
    if (!chooseActivity("What do you want to do with " + pet.name + "?", options, amounts, 2, boost)) {
        return false;
    }
    pet.happiness = clampStat(pet.happiness + boost);
    pet.cleanliness = clampStat(pet.cleanliness - 2);  // playing gets you dirty
    std::cout << pet.name << " had fun!\n";
    return true;
}

bool clean(VirtualPet& pet) {
    const std::string options[] = {"Bath", "Spa day"};
    const int amounts[] = {7, 10};
    int boost;
    if (!chooseActivity("How do you want to clean " + pet.name + "?", options, amounts, 2, boost)) {
        return false;
    }
    pet.cleanliness = clampStat(pet.cleanliness + boost);
    std::cout << pet.name << " is squeaky clean!\n";
    return true;
}

// Advances time by one step. Returns false if the pet passed away.
bool passTime(VirtualPet& pet) {
    pet.age++;
    pet.fullness = clampStat(pet.fullness - 2);
    pet.cleanliness = clampStat(pet.cleanliness - 1);
    pet.happiness = clampStat(pet.happiness - 1);

    if (pet.fullness == 0) {
        pet.happiness = clampStat(pet.happiness - 2);
        std::cout << pet.name << " is starving and getting grumpy!\n";
    }

    // A filthy pet has a 50% chance to get sick; a sick pet has a 50% chance
    // to pass away, otherwise it is nursed back to health.
    if (pet.cleanliness == 0 && std::rand() % 2 == 0) {
        std::cout << pet.name << " has gotten sick!\n";
        if (std::rand() % 2 == 0) {
            std::cout << pet.name << " has passed away. Keep your pet clean next time.\n";
            return false;
        }
        std::cout << "After a trip to the vet, " << pet.name << " has been cured.\n";
        pet.cleanliness = MAX_STAT / 2;
        pet.happiness = clampStat(pet.happiness - 5);
    }
    return true;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    VirtualPet pet;
    std::cout << "Welcome to the Virtual Pet Simulator!\nWhat is your pet's name? ";
    if (!std::getline(std::cin, pet.name) || pet.name.empty()) {
        pet.name = "Pet";
    }

    while (pet.age < MAX_AGE) {
        std::cout << "\nWhat would you like to do?\n"
                  << "  1. Check on " << pet.name << '\n'
                  << "  2. Feed\n"
                  << "  3. Play\n"
                  << "  4. Clean\n"
                  << "  5. Quit\n> ";

        int choice;
        if (!readChoice(1, 5, choice) || choice == 5) {
            std::cout << "Goodbye! " << pet.name << " will miss you.\n";
            return 0;
        }

        bool ok = true;
        switch (choice) {
            case 1: talk(pet); break;
            case 2: ok = feed(pet); break;
            case 3: ok = play(pet); break;
            case 4: ok = clean(pet); break;
        }
        if (!ok) {
            std::cout << "Goodbye!\n";
            return 0;
        }

        // Checking on the pet is free; every other action takes time.
        if (choice != 1 && !passTime(pet)) {
            return 0;
        }
    }

    std::cout << "\n" << pet.name << " has lived a long, "
              << moodName(getMood(pet)) << " life. Thanks for playing!\n";
    return 0;
}
