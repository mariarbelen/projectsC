#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double area(double a){
    return (3.14 * ((a*a)/4));
}

double area(int a, int b){
    return a * b ;
}

double area(int a, int b, int c){
    return (0.5 * a) * (b + c) ;
}

double area(int a, int b, int c, double s){
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double semiperimeter(int a, int b, int c){
    return (a + b + c) * 0.5 ;
}

int main()
{
    cout << "area (4)"<< setprecision(4) << area(4) << endl ;
    cout << "area (4,6) " << setprecision(4) << area(4, 6) << endl ;
    cout << "area (4 , 6, 8)" << setprecision(4) << area(4, 6, 8) << endl ;
    cout << "area ( 4,6,8, semiperimeter(4,6,8)"<< setprecision(4) << area(4, 6, 8, semiperimeter(4, 6, 8)) << endl ;

    return 0;
}


