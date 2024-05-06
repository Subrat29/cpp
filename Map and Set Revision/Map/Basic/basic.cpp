#include <bits/stdc++.h>
using namespace std;

// Learnings:
// 1) If mp[key] is not present then it creates it and set its value to 0;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    unordered_map<int, bool> mp1;
    map<int, bool> mp2;

    // for (auto &&i : arr)
    // {
    //     if(!mp[i])
    //     mp[i] = true;
    // }

    // for (auto &&i : arr)
    // {

    // }

    cout << mp1[2] << endl;
    cout << mp1.count(2) << endl;
    cout << mp2[2] << endl;
    cout << mp2.count(2) << endl;

    // Method 1: Traverse the map
    for (auto &&i : mp1)
    {
        cout << i.first << ": " << i.second << endl;
    }

    for (auto &&j : mp2)
    {
        cout << j.first << ": " << j.second << endl;
    }

    // Method 2: Traverse the map
    // for (auto i = mp1.begin(); i != mp1.end(); i++)
    // {
    //     cout << i->first << ": " << i->second;
    // }

    return 0;
}