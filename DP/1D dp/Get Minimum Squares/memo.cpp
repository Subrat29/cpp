#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> &dp)
{
    // base case
    if (n == 0)
        return 0;

    // step3
    if (dp[n] != -1)
        return dp[n];

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        int temp = i * i;
        ans = min(ans, 1 + solve(n - temp, dp));
    }
    dp[n] = ans;
    return dp[n];
}

int MinSquares(int n)
{
    // create dp array
    vector<int> dp(n + 1, -1);

    return solve(n, dp);
}

int main()
{

    return 0;
}