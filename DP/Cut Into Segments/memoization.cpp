#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    // base case
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    // step 3
    if (dp[n] != -1)
        return dp[n];

    int a = solveMem(n - x, x, y, z, dp) + 1; // add 1 bc to calculate n wala soln also
    int b = solveMem(n - y, x, y, z, dp) + 1;
    int c = solveMem(n - z, x, y, z, dp) + 1;

    // step 2
    dp[n] = max(a, max(b, c));
    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    // step 1
    vector<int> dp(n + 1, -1);

    int ans = solveMem(n, x, y, z, dp);

    if (ans < 0)
        return 0;

    return ans;
}

int main()
{

    return 0;
}