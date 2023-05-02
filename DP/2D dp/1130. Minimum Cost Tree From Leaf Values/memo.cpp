#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
{
    // leaf node
    if (left == right)
        return 0;

    // step3: check base case
    if (dp[left][right] != -1)
        return dp[left][right];

    int ans = INT_MAX;

    for (int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i + 1, right, dp));
    }

    // step2: store in dp
    return dp[left][right] = ans;
}

int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;

    for (int i = 0; i < arr.size(); i++)
    {
        // if indexes are equal then current value hi hogi
        maxi[{i, i}] = arr[i];

        // if indexes are different
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }

    int n = arr.size();

    // step1: create 2d vector
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return solve(arr, maxi, 0, arr.size() - 1, dp);
}

int main()
{

    return 0;
}