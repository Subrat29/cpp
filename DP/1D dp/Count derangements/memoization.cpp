#include <iostream>
#include <vector>
#define MOD 1000000007

//tc - O(n)
//sc - O(n) + O(n)  dp array + recursion depth tc
long long int solve(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    // step 3
    if (dp[n] != -1)
        return dp[n];

    // step 2
    dp[n] = ((n - 1) * (solve(n - 1, dp) + solve(n - 2, dp))) % MOD;

    return dp[n];
}

long long int countDerangements(int n)
{
    // step 1: create dp array
    vector<long long int> dp(n + 1, -1);

    return solve(n, dp);
}

int main()
{

    return 0;
}