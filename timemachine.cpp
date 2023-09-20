#include<iostream>
#include<iomanip>

using namespace std;

int timeMachine(int x, int y);

int main(){

if(x < y) 
return ((y /100- x /100)*60 + y%100 - x%100);

else 
return ((2400/100- x /100)*60 - x%100 + y/100 *60 + y %100);

}

int main(){
int x , y;
cout<<"Enter start time";
cin>>x;

cout<<"Enter end time";
cin >> y;
cout<<"The time difference between "<<setfill('0')<<setw(4)<< x <<" and "<<setfill('0')<<setw(4)<< y <<" is "<< timeMachine (x ,y )<< endl;
return 0;
}