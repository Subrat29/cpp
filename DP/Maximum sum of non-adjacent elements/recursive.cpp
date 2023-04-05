#include <iostream>
#include <vector>
using namespace std;

// Approach : we can solve it by 2 appr, for left to right use n+2, n+1 & for right to left use n-2, n-1

int solve(vector<int> &nums, int n)
{
    // base case
    if (n < 0)
        return 0;

    // if only one elem in array
    if (n == 0)
        return nums[0];

    int incl = solve(nums, n - 2) + nums[n];
    int exl = solve(nums, n - 1) + 0;

    return max(incl, exl);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    return solve(nums, n - 1);
}

int main()
{

    return 0;
}