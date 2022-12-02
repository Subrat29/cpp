#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    /*if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }*/

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');  //we can do above code like this also
}

string encodeString(string &s, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i]))
        {
            s[i] = char(s[i] + 1);
        }
        else
        {
            s[i] = char(s[i] - 1);
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    cout << encodeString(s,n);

    return 0;
}