#include <iostream>
#include <vector>
using namespace std;

long long solve(int d, int f, int t)
{
    // step1: create dp vector
    vector<vector<long long>> dp(d + 1, vector<long long>(t + 1, 0));

    // step2: Analyze base case
    dp[0][0] = 1;

    // step3: convert recursive call into dp
    // start from 1 bc 0 ke liye upar already ans h
    for (int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {
            long long ans = 0;
            for (int i = 1; i <= f; i++)
            {
                if (target - i >= 0)
                    ans = ans + dp[dice - 1][target - i];
            }
            dp[dice][target] = ans;
        }
    }
    return dp[d][t];
}

long long noOfWays(int M, int N, int X)
{
    return solve(N, M, X);
}

int main()
{

    return 0;
}