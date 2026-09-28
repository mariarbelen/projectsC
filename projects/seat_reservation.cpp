#include <iostream>
#include <cstdlib>
using namespace std;

const int ROWS = 7;
const int NUMSEATS = 4;


int main()
{

char plane[ROWS][NUMSEATS];
int x;
int y;
int row;
char seat;
int taken_seat;


for(x = 0; x < ROWS; x++)
for (y = 0; y < 4; y++)

plane[x][y] = char ('A' + y);

cout << "Airplane Reservation Program."<< "Reserved seats are marked as X";

for(x = 1; x < ROWS; x++)
{

for (y = 0; y < 4; y++) //Asked my cousin for help
{
cout << plane[x][y] <<" ";


if(y == 1)

cout <<" ";
}

cout << endl;
}

char ans = 'a';

while(ans!= 'n' && ans != 'N')
{

cout << "Airplane Seat Reservation"<< 
"Reserved seats are marked 'X'. \n";

cout <<"Select seats" << "There are 7 rows. Seats are A, B, C, D. \n";

cin >> row >> seat;

taken_seat = seat - 'A';

if('X' != plane[row][taken_seat])

plane[row][taken_seat]= 'X';

else

cout << "That seat is occupied, make another request\n";

for (x= 1; x < ROWS; x++)
{
    for (y=0; y< 4; y++)
{
    cout<< plane[x][y]<<" ";

    if (y== 1)
    cout << " ";

}
cout <<endl;


}
cout << "press N or n to quit \n";

cin >> ans;
}
return 0;
}
