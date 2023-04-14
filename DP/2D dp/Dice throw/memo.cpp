#include <iostream>
#include <vector>
using namespace std;

long long solve(int dice, int faces, int target, vector<vector<long long>> &dp)
{
    // base case
    if (target < 0)
        return 0;

    if (dice == 0 && target != 0)
        return 0;

    if (target == 0 && dice != 0)
        return 0;

    if (dice == 0 && target == 0) // tricky
        return 1;

    // step3: check base case
    if (dp[dice][target] != -1)
        return dp[dice][target];

    //step3: store in dp
    long long ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans = ans + solve(dice - 1, faces, target - i, dp);
    }
    return dp[dice][target] = ans;
}

long long noOfWays(int M, int N, int X)
{
    // step1: create dp vector
    vector<vector<long long>> dp(N+1, vector<long long>(X + 1, -1));
    return solve(N, M, X, dp);
}

int main()
{

    return 0;
}