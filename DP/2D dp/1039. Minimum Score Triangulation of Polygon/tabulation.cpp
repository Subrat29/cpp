#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &v)
{
    int n = v.size();

    // step1 : create dp array
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // step2 : base case

    // step3: convert recursive call into dp
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    int ans = 0;
    return solve(values);
}

int main()
{

    return 0;
}