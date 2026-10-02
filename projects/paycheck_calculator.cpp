// Weekly Paycheck Calculator
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science (Programming Project 2)
//
// Computes a worker's weekly gross pay (with time-and-a-half overtime past
// 40 hours), itemized deductions and take-home pay, with an optional
// family health insurance charge.

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

const double REGULAR_HOURS = 40;
const double OVERTIME_MULTIPLIER = 1.5;

const double SOCIAL_SECURITY_RATE = 0.062;
const double FEDERAL_INCOME_RATE = 0.22;
const double STATE_INCOME_RATE = 0.093;
const double UNION_DUES = 10.00;
const double FAMILY_HEALTH_INSURANCE = 251.60;

double readNumber(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= 0) {
            return value;
        }
        if (std::cin.eof()) {
            std::exit(1);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a positive number.\n";
    }
}

double grossPay(double rate, double hours) {
    if (hours <= REGULAR_HOURS) {
        return rate * hours;
    }
    double overtimeHours = hours - REGULAR_HOURS;
    return rate * REGULAR_HOURS + rate * OVERTIME_MULTIPLIER * overtimeHours;
}

void printLine(const std::string& label, double amount) {
    std::cout << std::left << std::setw(28) << label << "$" << std::right << std::setw(10) << amount << '\n';
}

int main() {
    std::cout << std::fixed << std::setprecision(2);

    double rate = readNumber("Enter the hourly rate of pay: $");
    double hours = readNumber("Enter the number of hours worked this week: ");

    double gross = grossPay(rate, hours);
    double socialSecurity = gross * SOCIAL_SECURITY_RATE;
    double federalTax = gross * FEDERAL_INCOME_RATE;
    double stateTax = gross * STATE_INCOME_RATE;
    double deductions = socialSecurity + federalTax + stateTax + UNION_DUES;

    std::cout << "\nHealth insurance: is it for (s)elf only or self and (o)thers? ";
    std::string answer;
    std::cin >> answer;
    bool family = !answer.empty() && std::tolower(static_cast<unsigned char>(answer[0])) == 'o';
    double insurance = family ? FAMILY_HEALTH_INSURANCE : 0.0;

    std::cout << "\n--- Weekly Pay Stub ---\n";
    printLine("Gross pay:", gross);
    printLine("Social Security (6.2%):", socialSecurity);
    printLine("Federal income tax (22%):", federalTax);
    printLine("State income tax (9.3%):", stateTax);
    printLine("Union dues:", UNION_DUES);
    printLine(family ? "Health insurance (family):" : "Health insurance (self):", insurance);
    std::cout << std::string(39, '-') << '\n';
    printLine("Take-home pay:", gross - deductions - insurance);

    return 0;
}
