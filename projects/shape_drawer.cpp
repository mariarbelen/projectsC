#include <iostream>
using namespace std;



int main(){  
    int input; 
    int rows;
    int x;
    int z;
    int Option;
    int choice;

do{
    cout<<"Welcome. Which following option would you like draw?"
        <<"\n1 - Filled Sqaure"
        <<"\n2 - Empty square"
        <<"\n3 - Triangle"
        <<"\n4 - Exit"<<endl;
        
        cout<<"Enter choice: ";
        cin>>choice;

    switch(choice)
    {
        case 1:
    {
    cout << "Enter number of rows for square: " ;
    cin >> rows;
    for(int x=0;x<rows;x++){

        for(int z=0;z<rows;z++){
            cout << "* ";
        }
         cout <<endl;
    }
    }
    break;

    case 2:
    {
    cout<< "Enter number of rows for empty square";
    cin >> rows;

      for(int x=1; x<=rows; x++){

        for(int z=1; z<=rows; z++){
            if(x==1 | x==rows | z==1 | z==rows){
                cout<<("*");
            }
            else{
                cout<<" ";
            }
        }
        cout<<"\n";

    }
    }
    break;
    
    case 3:
    {
    cout << "Enter number of rows for triangle: ";
    cin >> rows;

    for(int x = 1; x <= rows; ++x){

        for(int z = 1; z <= x; ++z)
        {
         cout << "* ";
        }
        cout << "\n";
    }
    }
            break;

            case 4:
            break;

            default:
            cout << "Not a valid choice. \n"
                << "choose again.\n";
            break;
    }
    }
while(choice != 4);
    return 0;

    return 0;
    }