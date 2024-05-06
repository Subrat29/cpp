#include <bits/stdc++.h>
using namespace std;

// Find maximum freqency number in array
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    int ans = arr[0];
    for (auto &&i : arr)
    {
        mp[i]++;
        if (mp[i] > mp[ans])
            ans = i;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 2, 1, 1, 5, 3, 2, 4, 9,2};
    int n = 7;
    cout << "Ans: " << maximumFrequency(arr, n);
    return 0;
}