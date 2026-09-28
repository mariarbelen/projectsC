#include <iostream>
using namespace std;

string swapCase(const string& s)
{
int length = s.length();
char s2[ln];
for (int i = 0; i < ln; i++) {
if (s[i] >= 'a' && s[i] <= 'z')

s2[i] = s[i] - 32;
else if (s[i] >= 'A' && s[i] <= 'Z')

s2[i] = s[i] + 32;
}
return s2;
}

int main()
{
string s;
cin>>s;
string s2=swapCase(s);
cout << s2;
return 0;
}