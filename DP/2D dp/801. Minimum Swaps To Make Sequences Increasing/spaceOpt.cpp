#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    // step1: create vectors
    int swap = 0;
    int noSwap = 0;
    int currSwap = 0;
    int currNoswap = 0;

    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int ans = INT_MAX;
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            // Catch
            if (swapped)
            {
                int temp = prev2;
                prev2 = prev1;
                prev1 = temp;
            }

            // noSwap
            if (nums1[index] > prev1 && nums2[index] > prev2)
                ans = noSwap;

            // Swap
            if (nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + swap);

            if (swapped)
                currSwap = ans;
            else
                currNoswap = ans;
        }
        swap = currSwap;
        noSwap = currNoswap;
    }

    return min(swap, noSwap);
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