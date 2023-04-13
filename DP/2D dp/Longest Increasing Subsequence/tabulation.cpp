#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int a[])
{
    // step1 : create dp vector
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // step2 : base case
    // we already set dp to 0

    // step3 : convert recursive call into dp
    // coordinate change to add +1 to remove invalid ans
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int take = 0;
            if (prev == -1 || a[curr] > a[prev])
                take = 1 + dp[curr + 1][curr + 1];

            // exclude
            int notTake = 0 + dp[curr + 1][prev + 1];

            dp[curr][prev + 1] = max(take, notTake);
        }
    }
    // return dp[0][-1+1];

    return dp[0][0];
}

int longestSubsequence(int n, int a[])
{
    return solve(n, a);
}

int main()
{

    return 0;
}