// Time Machine (Time Difference)
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science
//
// Reads two times in 24-hour HHMM format and prints how many minutes pass
// from the first to the second. If the end time is earlier than the start
// time, it is assumed to be on the next day.

#include <iomanip>
#include <iostream>

const int MINUTES_PER_DAY = 24 * 60;

bool isValidTime(int hhmm) {
    return hhmm >= 0 && hhmm / 100 < 24 && hhmm % 100 < 60;
}

int toMinutes(int hhmm) {
    return (hhmm / 100) * 60 + hhmm % 100;
}

// Minutes elapsed going forward from start to end (wrapping past midnight).
int timeMachine(int start, int end) {
    int difference = toMinutes(end) - toMinutes(start);
    if (difference < 0) {
        difference += MINUTES_PER_DAY;
    }
    return difference;
}

bool readTime(const char* prompt, int& hhmm) {
    std::cout << prompt;
    if (!(std::cin >> hhmm) || !isValidTime(hhmm)) {
        std::cout << "Invalid time. Use 24-hour HHMM format, e.g. 0930 or 2145.\n";
        return false;
    }
    return true;
}

int main() {
    int start, end;
    if (!readTime("Enter start time (HHMM): ", start) || !readTime("Enter end time (HHMM): ", end)) {
        return 1;
    }

    int minutes = timeMachine(start, end);
    std::cout << std::setfill('0') << "The time difference between " << std::setw(4) << start
              << " and " << std::setw(4) << end << " is " << minutes << " minutes ("
              << minutes / 60 << "h " << minutes % 60 << "m).\n";
    return 0;
}
