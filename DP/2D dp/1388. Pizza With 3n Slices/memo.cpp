#include <iostream>
#include <vector>
using namespace std;

// 2 parameters changes : (index, n)  hence 2d dp use here
int solve(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp)
{
    // base case
    if (n == 0 || index > endIndex)
        return 0;

    // step3: check the base condition
    if (dp[index][n] != -1)
        return dp[index][n];

    // step2: store in dp
    int take = slices[index] + solve(index + 2, endIndex, slices, n - 1, dp);
    int notTake = 0 + solve(index + 1, endIndex, slices, n, dp);

    dp[index][n] = max(take, notTake);
    return dp[index][n];
}

int maxSizeSlices(vector<int> &slices)
{
    int k = slices.size();

    // step1: create separate dp vector to both cases else ans wrong aayega bv maybe case1 manipulate its data
    vector<vector<int>> dp1(k, vector<int>(k, -1));
    vector<vector<int>> dp2(k, vector<int>(k, -1));

    // eat
    int case1 = solve(0, k - 2, slices, k / 3, dp1);

    // not eat
    int case2 = solve(1, k - 1, slices, k / 3, dp2);

    return max(case1, case2);
}

int main()
{

    return 0;
}