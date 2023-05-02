#include <iostream>
#include <vector>
#include <map>
using namespace std;

// tc: O(n^3)

int solve(vector<int> &arr, map<pair<int, int>, int> &maxi)
{
    int n = arr.size() - 1; //-1

    // step1: create 2d vector
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // step2: analyze base case
    for (int left = n; left >= 0; left--)
    {
        for (int right = left; right <= n; right++)
        {
            if (left == right)
                continue;

            else
            {
                int ans = INT_MAX;

                for (int i = left; i < right; i++)
                {
                    ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right]);
                }
                dp[left][right] = ans;
            }
        }
    }
    return dp[0][n];
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

    return solve(arr, maxi);
}

int main()
{

    return 0;
}