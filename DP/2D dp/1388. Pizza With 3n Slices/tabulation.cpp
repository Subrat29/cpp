#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &slices)
{
    int k = slices.size();

    // step1: create separate dp vector to both cases
    // coordinate modify and add+2 bc dp[index+2][] & dp[index+1][] me hm vector ke bahar chale jayega.
    vector<vector<int>> dp1(k, vector<int>(k, -1));
    vector<vector<int>> dp2(k, vector<int>(k, -1));


    // step2: base case
    // no need of base case bc vector already initialize with 0


    // step3: check the base condition

    // k-2 to 0
    for (int index = k - 2; index >= 0; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slices[index] + dp1[index + 2][n - 1];
            int notTake = 0 + dp1[index + 1][n];
            dp1[index][n] = max(take, notTake);
        }
    }
    int case1 = dp1[0][k / 3];

    // k-1 to 1
    for (int index = k - 1; index >= 1; index--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slices[index] + dp2[index + 2][n - 1];
            int notTake = 0 + dp2[index + 1][n];
            dp2[index][n] = max(take, notTake);
        }
    }
    int case2 = dp2[1][k / 3];

    return max(case1, case2);
}

int maxSizeSlices(vector<int> &slices)
{
    return solve(slices);
}

int main()
{

    return 0;
}