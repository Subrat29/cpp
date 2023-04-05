#include <iostream>
#include <vector>
using namespace std;

// sc = O(n) * O(n)
// tc = O(n)

int solve(vector<int> &nums, int n, vector<int> &dp)
{
    // base case
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[n];

    // step3 : check
    if (dp[n] != -1)
        return dp[n];

    // step2
    int incl = solve(nums, n - 2, dp) + nums[n];
    int exl = solve(nums, n - 1, dp) + 0;

    dp[n] = max(incl, exl);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    // step1 : create dp array
    vector<int> dp(n + 1, -1);

    return solve(nums, n - 1, dp); // dp ka size n bhi le skte the bc bheja n-1 hi h
}

int main()
{

    return 0;
}