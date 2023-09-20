#include <iostream>

using namespace std;
 
    char computerChoice() {
    int random = (rand() % 6);
    char possibleChoices[] = {'R', 'r', 'P', 'p', 'S', 's'};
    char choice = possibleChoices[random];
    return choice;
    }
    
int main()
{
    char computer, choice;
    //string computer, choice;
   int rounds, tie=0, computerWin= 0, playerWin= 0;    
    computer = computerChoice();
    
        cout << "How many rounds do you want to play?" <<endl;
        cout << "Enter rounds>";
        cin >> rounds;
 do {
        cout << "\nSelect rock, paper or scissors:";
        cin >> choice;
        cout << "\nYour selection is:" << choice << endl;

        cout <<"Computer's choice is: "<< computer<< endl;
cout << "Computer wins: " << computerWin << endl << "User wins: " << playerWin << endl;
    rounds--; 

 
    while (computer == choice)
    {
      cout << "It's a tie.\n";
      tie ++ ;
    }
    while ((computer == 'R') && (choice == 'S')) 
      cout << "You Lose.\n";
      computerWin ++;
    while ((computer == 'P') && (choice == 'R')) 
      cout << "You Lose.\n";
      computerWin ++;
    while ((computer == 'S') && (choice == 'P')) 
      cout << "You lose. \n";
      computerWin ++;
     while ((computer == 'R') && (choice == 'P')) 
      cout << "You Win.\n";
      playerWin ++;
    while ((computer == 'P') && (choice == 'S')) 
      cout << " You Win.\n";
      playerWin ++;
    while ((computer == 'S') && (choice == 'R')) 
      cout << "You Win.\n";
      playerWin ++;
    }

   

    
while(rounds>0)
;
    return choice;
}