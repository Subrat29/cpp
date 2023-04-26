#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;

    // step3: check base case
    if (dp[n] != -1)
        return dp[n];

    int ans = 0;
    // Assume i as root node
    for (int i = 1; i <= n; i++)
    {
        ans += solve(i - 1, dp) * solve(n - i, dp);
    }

    // step2: store in dp
    return dp[n] = ans;
}

int numTrees(int n)
{
    // step1: create dp vector
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

int main()
{

    return 0;
}