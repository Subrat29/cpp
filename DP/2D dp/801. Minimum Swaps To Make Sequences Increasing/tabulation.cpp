#include <iostream>
#include <vector>
using namespace std;

// tc: O(n), sc: O(n)

int solve(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    // step1: create dp vector

    // only 2 col required ie - 0, 1
    // n+1 to remove error in below condn
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // step2: analysis base case
    // no need vector already set to 0

    // step3: convert recursive call into dp relation
    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            // Catch
            if (swapped)
                swap(prev1, prev2);

            // noSwap
            if (nums1[index] > prev1 && nums2[index] > prev2)
                ans = dp[index + 1][0];

            // Swap
            if (nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + dp[index + 1][1]);

            dp[index][swapped] = ans;
        }
    }

    return dp[1][0];
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    return solve(nums1, nums2);
}

int main()
{

    return 0;
}