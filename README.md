# C++ Fundamentals Portfolio

[![CI](https://github.com/mariarbelen/projectsC/actions/workflows/ci.yml/badge.svg)](https://github.com/mariarbelen/projectsC/actions/workflows/ci.yml)

A collection of C++ console programs I wrote for **CS002: Fundamentals of Computer Science**, ranging from a text-based virtual pet game to payroll calculators and string-processing tools.

Every program compiles cleanly with `-Wall -Wextra -Wpedantic -Werror` on both GCC and Clang, validates user input, and is covered by an automated test suite that runs on every push via GitHub Actions.

## Highlights

### 🐾 Virtual Pet Simulator ([`projects/virtual_pet.cpp`](projects/virtual_pet.cpp))
My term project: a Tamagotchi-style game where you name a pet and keep it fed, clean and happy. Every action advances time, stats decay, and a neglected pet can get sick. The game ends when the pet reaches old age or passes away.

*Concepts:* `struct`s, `enum class`, pass-by-reference, random events, game loop, input validation

```
--- Mochi ---
Age:         3 / 40
Fullness:    14 / 20
Cleanliness: 16 / 20
Happiness:   19 / 20
Mochi is feeling okay.
It is not hungry.
It is thrilled!
It is fairly clean.
```

### 💵 Salary Calculator ([`projects/salary_calculator.cpp`](projects/salary_calculator.cpp))
Turns a yearly salary into a per-paycheck breakdown for weekly, bi-weekly, semi-monthly, monthly or yearly pay. It covers Social Security, Medicare, federal tax, **progressive state income tax brackets**, pension contributions and optional health, dental and vision insurance.

*Concepts:* data-driven tables (arrays of structs), progressive tax algorithm, formatted output with `<iomanip>`

## All Programs

### Projects

| Program | Description | Key concepts |
|---|---|---|
| [Virtual Pet Simulator](projects/virtual_pet.cpp) | Care-for-your-pet game with random events | structs, enums, references, RNG |
| [Salary Calculator](projects/salary_calculator.cpp) | Paycheck breakdown with progressive tax brackets | arrays of structs, algorithms, formatting |
| [Paycheck Calculator](projects/paycheck_calculator.cpp) | Weekly pay stub with overtime and deductions | functions, constants, conditionals |
| [Rock, Paper, Scissors](projects/rock_paper_scissors.cpp) | Multi-round game vs. the computer with scoring | RNG, loops, game logic |
| [Airplane Seat Reservation](projects/seat_reservation.cpp) | Book seats on a 7-row plane shown as a seat map | 2D arrays, bounds checking |
| [String Toolkit](projects/string_toolkit.cpp) | Menu-driven vowel/consonant counting and case conversion | `std::string`, `<cctype>`, menus |
| [ASCII Shape Drawer](projects/shape_drawer.cpp) | Draws filled/hollow squares and triangles | nested loops |

### Exercises

| Program | Description | Key concepts |
|---|---|---|
| [Shape Areas](exercises/shape_areas.cpp) | Circle, rectangle, trapezoid and triangle (Heron's formula) areas | function overloading |
| [Cookie Order](exercises/cookie_order.cpp) | Free-cookie-per-dozen order calculator | integer division & modulo |
| [Time Difference](exercises/time_difference.cpp) | Minutes between two 24-hour times, across midnight | modular arithmetic |
| [Swap Case](exercises/swap_case.cpp) | Inverts the case of every letter in a line | character manipulation |
| [Word Counter](exercises/word_counter.cpp) | Counts words and letter frequencies | state tracking, frequency arrays |
| [Phone Lookup](exercises/phone_lookup.cpp) | Case-insensitive name → phone number search | parallel arrays, linear search |

## Build and Run

Requires a C++17 compiler (GCC or Clang) and `make`.

```bash
make                  # build every program into bin/
./bin/virtual_pet     # run one
make test             # run the automated test suite
make clean            # remove build output
```

To compile a single program without `make`:

```bash
g++ -std=c++17 -Wall -o virtual_pet projects/virtual_pet.cpp
```

## Testing

[`tests/run_tests.sh`](tests/run_tests.sh) runs each program with scripted input and checks its output, including edge cases like invalid input, overtime pay, tax bracket math, overnight time differences and occupied seats. GitHub Actions runs the build and tests with both GCC and Clang on every push.

## Repository Layout

```
projects/     larger, menu-driven programs
exercises/    shorter single-concept programs
tests/        automated smoke tests
Makefile      build and test commands
```

## Author

**Maria Rodriguez**
