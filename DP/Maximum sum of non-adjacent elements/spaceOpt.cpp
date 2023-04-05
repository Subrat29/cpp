#include <iostream>
#include <vector>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{

    int n = nums.size();

    int prev2 = 0;       // fetch from base case 1
    int prev1 = nums[0]; // base case 2

    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + nums[i];
        int exl = prev1 + 0;

        int ans = max(incl, exl);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int main()
{

    return 0;
}