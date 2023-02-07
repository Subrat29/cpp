#include <bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> m;
    int ans = 0;
    int freq = 0;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        freq = max(freq, m[arr[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (freq == m[arr[i]])
        {
            ans = arr[i];
            break;
        }
    }
    return ans;
}

int main()
{

    return 0;
}