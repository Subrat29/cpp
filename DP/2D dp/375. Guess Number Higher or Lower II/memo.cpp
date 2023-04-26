#include <iostream>
#include <vector>
using namespace std;

int solve(int start, int end, vector<vector<int>> &dp)
{
    // base case
    if (start >= end)
        return 0;

    // step3: check base case
    if (dp[start][end] != -1)
        return dp[start][end];

    // step2: store in dp
    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solve(start, i - 1, dp), solve(i + 1, end, dp)));
    }
    return dp[start][end] = ans;
}

int getMoneyAmount(int n)
{
    // step1: create dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return solve(1, n, dp);
}

int main()
{

    return 0;
}