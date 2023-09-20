#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the max stat values for the pet
const int MAX_HUNGER = 20;
const int MAX_CLEANLINESS = 20;
const int MAX_HAPPINESS = 20;
const int MAX_AGE = 40;

enum Mood {
    HAPPY,
    OKAY,
    FRUSTRATED,
    MAD
};

struct VirtualPet {
    int age;
    int hunger;
    int cleanliness;
    int happiness;
};

// Initialize a new pet with default stat values
VirtualPet initPet() {
    VirtualPet pet;
    pet.age = 0;
    pet.hunger = MAX_HUNGER;
    pet.cleanliness = MAX_CLEANLINESS;
    pet.happiness = MAX_HAPPINESS;
    return pet;
}

Mood getMood(VirtualPet pet) {
    //average of the pet's stats 
    int avg = (pet.hunger + pet.cleanliness + pet.happiness) / 3;

    if (avg > 16) {
        return HAPPY;
    } else if (avg > 11) {
        return OKAY;
    } else if (avg > 6) {
        return FRUSTRATED;
    } else {
        return MAD;
    }
}

// stat values of the pet
void talk(VirtualPet pet) {
    cout << "Age: " << pet.age << endl;
    cout << "Hunger: " << pet.hunger << endl;
    cout << "Cleanliness: " << pet.cleanliness << endl;
    cout << "Happiness: " << pet.happiness << endl;

    if (pet.hunger > 16) {
        cout << "The pet is full up!" << endl;
    } else if (pet.hunger > 11) {
        cout << "The pet is not hungry." << endl;
    } else if (pet.hunger > 6) {
        cout << "The pet is somewhat hungry." << endl;
    } else {
        cout << "The pet is hungry!" << endl;
    }

    if (pet.happiness > 16) {
        cout << "The pet is happy!" << endl;
    } else if (pet.happiness > 11) {
        cout << "The pet is okay." << endl;
    } else if (pet.happiness > 6) {
        cout << "The pet is content." << endl;
    } else {
        cout << "The pet is unhappy!" << endl;
    }

    if (pet.cleanliness > 16) {
        cout << "The pet is clean!" << endl;
    } else if (pet.cleanliness > 11) {
        cout << "The pet is kind of clean." << endl;
    } else if (pet.cleanliness > 6) {
        cout << "The pet is kind of smelly." << endl;
    } else {
        cout << "The pet is smelly!" << endl;
    }
}
   


void time(VirtualPet& pet, int minutes = 1) {
    // Increase the pet's age
    pet.age += minutes;

    // Increase 
    pet.hunger += minutes;
    pet.happiness -= minutes;


    if (pet.cleanliness < 0) {
       
        if (rand() % 2 == 0) {
            cout << "The pet has gotten sick!" << endl;

            while (pet.cleanliness < 0) {
                pet.cleanliness--;

                // 50% chance of the pet passing away
                if (rand() % 2 == 0) {
                    cout << "The pet has passed away!" << endl;
                    exit(0);
                }
            }

            cout << "The pet has been cured!" << endl;
        }
    }
}

void feed(VirtualPet& pet) {
    string feedOptions[] = {"Rice", "Fruit"};
    int feedAmount[] = {3, 2};

    cout << "What do you want to feed the pet?" << endl;

    //available options
    for (int i = 0; i < 2; i++) {
        cout << i + 1 << ". " << feedOptions[i] << endl;
    }

    int choice;
    cin >> choice;

    pet.hunger -= feedAmount[choice - 1];

    cout << "The pet has been fed!" << endl;
}

    void play(VirtualPet& pet) {
    // different play options and the amounts
    string playOptions[] = {"Ball", "Running"};
    int playAmount[] = {5, 4};

    cout << "What do you want to do with the pet?" << endl;

    for (int i = 0; i < 2; i++) {
        cout << i + 1 << ". " << playOptions[i] << endl;
    }
    int choice;
    cin >> choice;

    pet.happiness += playAmount[choice - 1];

    cout << "The pet has had fun!" << endl;
}


    void clean(VirtualPet& pet) {
  
    string cleanOptions[] = {"Bath", "Spa"};
    int cleanAmount[] = {7, 6};

    cout << "How do you want to clean the pet?" << endl;

    for (int i = 0; i < 2; i++) {
        cout << i + 1 << ". " << cleanOptions[i] << endl;
    }

    int choice;
    cin >> choice;

    pet.cleanliness += cleanAmount[choice - 1];

    cout << "The pet has been cleaned!" << endl;
}

    int main() {
    srand(time(0));

    VirtualPet pet = initPet();

    while (true) {
        // Print the main menu
        cout << "Virtual Pet Simulator" << endl;
        cout << "1. Talk" << endl;
        cout << "2. Feed" << endl;
        cout << "3. Play" << endl;
        cout << "4. Clean" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                talk(pet);
                break;
            case 2:
                feed(pet);
                break;
            case 3:
                play(pet);
                break;
            case 4:
                clean(pet);
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }

        //passage of time after every action
        time(pet);
    }

    return 0;
}


