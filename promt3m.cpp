#include <iostream>
using namespace std;

int main() {
int cookiesOrder;
int chocoChips;
int dozenCount;
int looseCookies;
int freeCookies;
int a;
int c;
int answer;

do{
    
cout <<"Enter the number of cookies you want to order:";
cin>> cookiesOrder;


if (cookiesOrder > 12 ){
    freeCookies= cookiesOrder / 12; 



    cout << "You also get " << freeCookies << "free cookies, one per dozen.";

    dozenCount = (freeCookies + cookiesOrder) / 12 ; 
looseCookies = (freeCookies + cookiesOrder) %  12;

cout<< "That comes up to" << dozenCount<< "and "<< looseCookies << "loose cookie (s)";

chocoChips = (freeCookies + cookiesOrder) * 10;

cout<< "Your total comes up to " << dozenCount<< "\n"
<< "dozens"<< "\n"
<< "and " <<"\n"
<<looseCookies <<"\n"
"loose cookies"<< endl;


cout << "There is a total of " << chocoChips << "chocolate chips "<< endl;

cout<< "Would you like to repeat the calculation: ";
cin>> answer;



}

else
{
    chocoChips = cookiesOrder *10;
    dozenCount = 0;
    looseCookies = cookiesOrder;

cout<< "Your total comes up to " << dozenCount<< "\n"
<< " dozens"<< "\n"
<< "and " <<"\n"
<<looseCookies <<"\n"
"loose cookies"<< endl;

cout << "There is a total of " << chocoChips << "chocolate chips "<< endl;
cout<< "Would you like to repeat the calculation: ";
cin>> answer;


}
}
while(answer=='Y'||answer=='y');

    return 0;



}
