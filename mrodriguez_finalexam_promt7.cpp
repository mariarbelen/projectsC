#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int word_count = 0;
    bool in_word = false;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (isspace(c))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            word_count++;
            in_word = true;
        }
    }

    cout << "Number of words: " << word_count << endl;

    int letter_count[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        c = tolower(c);
        if (isalpha(c))
        {
            letter_count[c - 'a']++;
        }
    }

    cout << "each letter:" << endl;
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        cout << c << ": " << letter_count[i] << endl;
    }

    return 0;
}