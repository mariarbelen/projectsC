// Salary Calculator
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science
//
// Converts a yearly gross salary into a per-paycheck breakdown: Social
// Security, Medicare, federal income tax, progressive state income tax,
// pension contribution and optional health/dental/vision insurance.
//
// Tax rules are simplified for learning purposes (flat federal rate,
// California-style state brackets) and are not financial advice.

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

const double SOCIAL_SECURITY_RATE = 0.062;
const double MEDICARE_RATE = 0.0145;
const double FEDERAL_INCOME_RATE = 0.22;

// Monthly insurance premiums.
const double HEALTH_FAMILY_MONTHLY = 251.63;  // coverage for yourself is employer-paid
const double DENTAL_SELF_MONTHLY = 17.58;
const double DENTAL_FAMILY_MONTHLY = 70.88;
const double VISION_MONTHLY = 5.61;

struct PayPeriod {
    std::string name;
    int perYear;
};

const PayPeriod PAY_PERIODS[] = {
    {"Weekly", 52}, {"Bi-weekly", 26}, {"Semi-monthly", 24}, {"Monthly", 12}, {"Yearly", 1},
};
const int NUM_PAY_PERIODS = 5;

struct TaxBracket {
    double upTo;  // upper limit of the bracket (yearly income)
    double rate;
};

const TaxBracket STATE_BRACKETS[] = {
    {8544, 0.010},   {20255, 0.020},  {31969, 0.040},  {44377, 0.060},
    {56085, 0.080},  {286492, 0.093}, {343788, 0.103}, {572980, 0.113},
    {1000000, 0.123}, {std::numeric_limits<double>::max(), 0.133},
};

// Progressive tax: each rate applies only to the part of income inside its bracket.
double stateIncomeTax(double yearlyIncome) {
    double tax = 0;
    double lower = 0;
    for (const TaxBracket& bracket : STATE_BRACKETS) {
        if (yearlyIncome <= lower) {
            break;
        }
        double taxedHere = std::min(yearlyIncome, bracket.upTo) - lower;
        tax += taxedHere * bracket.rate;
        lower = bracket.upTo;
    }
    return tax;
}

void clearLine() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double readNumber(const std::string& prompt, double low, double high) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= low && value <= high) {
            return value;
        }
        if (std::cin.eof()) {
            std::exit(1);
        }
        clearLine();
        std::cout << "Please enter a number from " << low << " to " << high << ".\n";
    }
}

// Asks a question and returns the (lowercase) first letter of the answer,
// which must be one of the allowed letters.
char readLetter(const std::string& prompt, const std::string& allowed) {
    std::string answer;
    while (true) {
        std::cout << prompt;
        if (!(std::cin >> answer)) {
            std::exit(1);
        }
        char letter = static_cast<char>(std::tolower(static_cast<unsigned char>(answer[0])));
        if (allowed.find(letter) != std::string::npos) {
            return letter;
        }
        std::cout << "Please answer with one of: " << allowed << '\n';
    }
}

void printLine(const std::string& label, double amount) {
    std::cout << std::left << std::setw(26) << label << std::right << std::setw(12) << amount << '\n';
}

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "=== Salary Calculator ===\n";

    double grossYearly = readNumber("Enter your yearly gross salary: $", 0, 1e9);

    std::cout << "\nHow often are you paid?\n";
    for (int i = 0; i < NUM_PAY_PERIODS; i++) {
        std::cout << "  " << i + 1 << " - " << PAY_PERIODS[i].name << '\n';
    }
    int periodChoice = static_cast<int>(readNumber("Enter choice: ", 1, NUM_PAY_PERIODS));
    const PayPeriod& period = PAY_PERIODS[periodChoice - 1];

    // Premiums are monthly, so convert them to the chosen pay period.
    double monthsPerPeriod = 12.0 / period.perYear;

    double health = 0;
    if (readLetter("\nDo you want health insurance? (y/n): ", "yn") == 'y' &&
        readLetter("For (s)elf only or self and (o)thers? ", "so") == 'o') {
        health = HEALTH_FAMILY_MONTHLY * monthsPerPeriod;
    }

    double dental = 0;
    if (readLetter("Do you want dental insurance? (y/n): ", "yn") == 'y') {
        bool family = readLetter("For (s)elf only or self and (o)thers? ", "so") == 'o';
        dental = (family ? DENTAL_FAMILY_MONTHLY : DENTAL_SELF_MONTHLY) * monthsPerPeriod;
    }

    double vision = 0;
    if (readLetter("Do you want vision insurance? (y/n): ", "yn") == 'y') {
        vision = VISION_MONTHLY * monthsPerPeriod;
    }

    double pensionPercent = readNumber("What percentage of your salary goes to your pension (0-100)? ", 0, 100);

    double gross = grossYearly / period.perYear;
    double socialSecurity = gross * SOCIAL_SECURITY_RATE;
    double medicare = gross * MEDICARE_RATE;
    double federal = gross * FEDERAL_INCOME_RATE;
    double state = stateIncomeTax(grossYearly) / period.perYear;
    double pension = gross * pensionPercent / 100;

    double totalDeductions = socialSecurity + medicare + federal + state + pension + health + dental + vision;
    double net = gross - totalDeductions;

    std::cout << "\n--- " << period.name << " paycheck ---\n";
    printLine("Gross salary:", gross);
    std::cout << "Deductions:\n";
    printLine("  Social Security:", socialSecurity);
    printLine("  Medicare:", medicare);
    printLine("  Federal income tax:", federal);
    printLine("  State income tax:", state);
    printLine("  Pension plan:", pension);
    printLine("  Health insurance:", health);
    printLine("  Dental insurance:", dental);
    printLine("  Vision insurance:", vision);
    std::cout << std::string(38, '-') << '\n';
    printLine("Total deductions:", totalDeductions);
    printLine("Net pay:", net);

    return 0;
}
