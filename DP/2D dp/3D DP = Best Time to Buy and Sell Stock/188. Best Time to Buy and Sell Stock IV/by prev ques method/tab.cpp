#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &prices, int k)
{
    int n = prices.size();
    // step1: create dp array
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    // step2: anlyz base case
    // no need

    // step2: convert recursive soln in dp
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            // 0 is alredy handle in step2 check memo.cpp
            // bas issski wajay se chal nii rha tha broooooooo
            for (int limit = 1; limit <= k; limit++)
            {
                int profit = 0;
                // buy allowed
                if (buy)
                {
                    int buyKaro = -prices[index] + dp[index + 1][0][limit];
                    int skipKaro = 0 + dp[index + 1][1][limit];
                    profit = max(buyKaro, skipKaro);
                }
                // buy not allowed
                else
                {
                    int sellKaro = prices[index] + dp[index + 1][1][limit - 1];
                    int skipKaro = 0 + dp[index + 1][0][limit];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][k];
}

int maxProfit(int k, vector<int> &prices)
{
    return solve(prices, k);
}

int main()
{

    return 0;
}