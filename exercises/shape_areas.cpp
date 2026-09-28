// Shape Areas (Function Overloading)
// Author: Maria Rodriguez
// Course: CS002 - Fundamentals of Computer Science
//
// Uses overloaded area() functions to compute the area of a circle (from
// its diameter), a rectangle, a trapezoid, and a triangle (Heron's formula).

#include <cmath>
#include <iomanip>
#include <iostream>

const double PI = 3.14159265358979323846;

// Circle, given its diameter.
double area(double diameter) {
    return PI * diameter * diameter / 4;
}

// Rectangle, given width and height.
double area(double width, double height) {
    return width * height;
}

// Trapezoid, given its height and the two parallel sides.
double area(double height, double base1, double base2) {
    return 0.5 * height * (base1 + base2);
}

double semiperimeter(double a, double b, double c) {
    return (a + b + c) / 2;
}

// Triangle, given its three sides and semiperimeter s (Heron's formula).
double area(double a, double b, double c, double s) {
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Circle with diameter 4:              " << area(4.0) << '\n';
    std::cout << "Rectangle 4 x 6:                     " << area(4.0, 6.0) << '\n';
    std::cout << "Trapezoid height 4, bases 6 and 8:   " << area(4.0, 6.0, 8.0) << '\n';
    std::cout << "Triangle with sides 4, 6, 8:         "
              << area(4.0, 6.0, 8.0, semiperimeter(4.0, 6.0, 8.0)) << '\n';
    return 0;
}
