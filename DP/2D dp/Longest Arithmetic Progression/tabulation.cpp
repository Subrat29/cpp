#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// This code is run well in gfg but gives error in this studio

// Tc = O(n^2)
// Sc = O(n^2)

int lengthOfLongestAP(int A[], int n)
{
    if (n <= 2)
        return n;

    int ans = 0;

    unordered_map<int, int> dp[n + 1];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = A[i] - A[j];
            int cnt = 1;

            // check if answer already present
            if (dp[j].count(diff))
                cnt = dp[j][diff];

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

int main()
{

    return 0;
}