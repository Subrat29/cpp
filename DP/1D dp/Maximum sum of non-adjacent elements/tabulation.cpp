#include <iostream>
#include <vector>
using namespace std;

// sc = O(n)
// tc = O(n)

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    // step1 : create dp array
    vector<int> dp(n, -1);

    // step2 : check base case
    dp[0] = nums[0];

    // step3 : solve
    for (int i = 1; i < n; i++) // bc 0 case handle above
    {
        int incl = dp[i - 2] + nums[i];
        int exl = dp[i - 1] + 0;

        dp[i] = max(incl, exl);
    }
    return dp[n - 1];
}

int main()
{

    return 0;
}