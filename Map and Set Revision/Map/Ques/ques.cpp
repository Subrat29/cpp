#include <bits/stdc++.h>
using namespace std;

// Create a map to store the frequencies of characters in a given string.

int main()
{
    string str = "subratyadav";
    unordered_map<char, int> mp;
    for (auto &&i : str)
    {
        mp[i]++;
    }

    for (auto &&i : mp)
    {
        cout << i.first << ": " << i.second << endl;
    }

    return 0;
}