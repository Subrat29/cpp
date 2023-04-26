#include <iostream>
#include <vector>
using namespace std;

int solve(int n)
{
    // step1: create dp array
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // step2: analyse base case
    // no need

    // step3: convert recursive relation in dp
    for (int start = n; start >= 1; start--)
    {
        for (int end = start; end <= n; end++)
        {
            if (start == end)
                continue;
            else
            {
                int ans = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = ans;
            }
        }
    }
    return dp[1][n];
    // yha return vhi krte h jo memo me find krte h means jo parameter solve fn me bhejte h
}

int getMoneyAmount(int n)
{
    return solve(n);
}

int main()
{

    return 0;
}