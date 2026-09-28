#include <iostream>
#include<string>
#include <cstring>

using namespace std;

void menu();
void convertUpper(string str);
void convertLower(string str);
int countVowel(string str);
int countConsonants(string str);
void newline();

string str;

void menu(){
    cout << "A) Counting the number of vowels in the string.\n";
    cout << "B) Counting the number of consonants in the string.\n";
    cout << "C) Converting the string to all uppercase.\n";
    cout << "D) Converting the string to all lowercase.\n";
    cout << "E) Displaying the current string.\n";
    cout << "F) Enter a new string.\n";
    cout << "G) Exit the program.\n";
}

int countVowel(string str)
{
    int i=0,sum =0;
while(str[i]!='\0')
{
if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
sum++;
i++;
    }
    return sum;
}

int countConsonants(string str)
{

 int i=0,consonants =0;

while(str[i]!='\0')
{
str[i] = toupper(str[i]);
if(!(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'))
consonants++;
i++;
}
    return consonants;
}

void convertUpper(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
    cout << str;
}

void convertLower(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    cout << str;
}
void newline()
{
    char symbol;
    do
    {
        cin.get(symbol);
    } while (symbol != '\n');
}
int main()
{

char choice = 'F';

cout<<"\nEnter a string : ";
getline(cin,str);

while (choice!='G')
{
    menu();
cout<<"\nEnter your menu selection : ";
cin>>choice;

switch(choice)
{
case 'A':
cout << countVowel(str) << " vowels in the string.\n";
break;

case 'B':
cout << countConsonants(str) << " consonants in the string.\n";
break;

case 'C':
convertUpper(str);
break;

case 'D':
convertLower(str);
break;

case 'E':
cout << str << endl;
break;

case 'F':
    cout<<"Enter new string : "<<endl;
    cin.ignore();
    getline(cin,str);

 break;
        default:
            break;
        }
    }
}

