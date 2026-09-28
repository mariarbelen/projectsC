//Maria Rodriguez 
//  Programming Project 2
//CS002 - Fundamentals of Computer Science 

#include <iostream>
using namespace std;

int main() {

    int hours;
    double grossPay, rate, federlIncomeTax, total;
    string netTake;

    cout << "Enter the hourly rate of pay: $";
    cin >> rate;

    cout<< "Enter the number of hours you have worked weekly";
    cin >> hours;

    //creating formulas

    if (hours > 40)
        grossPay = rate * 40 + 1.5 * (hours - 40);
    else
        grossPay = rate * hours;

    cout.setf(ios :: fixed);
    cout.setf(ios :: showpoint);
    cout.precision(2);
        

    cout<<"your salary before deduction is $"<< grossPay <<endl;

    double socialSecurityTax = (grossPay * 6.2) / 100;
    double federalIncomeTax= (grossPay * 22 ) / 100;
    double stateTax = (grossPay * 9.3) / 100;
    double unionDues =  10;

    int sum = socialSecurityTax + federalIncomeTax + stateTax - unionDues;
    cout<<"Deduction# 1=..........$"<< socialSecurityTax <<endl;
    cout<<"Deduction# 2=..........$"<< federalIncomeTax <<endl;
    cout<<"Deduction# 3=..........$"<< stateTax <<endl;
    cout<<"Deduction# 4=..........$"<< unionDues <<endl;

    cout<<"your paycheck is $"<<grossPay - sum<<endl;



    //find the net take home 


    cout << "Would you like health insurance for others or self? ";
    cin >> netTake;

    if (netTake == "others")
    {
    total = grossPay -sum - 251.6;
    cout<< "Your new total is "<< total <<endl;

    } 
    else if(netTake == "self")
    {
        cout<< "No additional charge" << endl;
    }
    return 0;

}
        
    


