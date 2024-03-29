#include <iostream>
#include <vector>
using namespace std;

// tc = O(n)
// sc = O(n) + O(n)

int solve(vector<int> &cost, int n, vector<int> &dp)
{
    // base case
    if (n == 0)
        return cost[0];

    if (n == 1)
        return cost[1];

    // step 3
    if (dp[n] != -1)
        return dp[n];

    // step 2
    dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return dp[n];
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();

    // step 1
    vector<int> dp(n + 1, -1);

    return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
}

int main()
{

    return 0;
}