#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &prices)
{
    int n = prices.size();

    // step1: create dp array

    // above is give index overflow bc here n and neeche hm (index + 1) krrhe h
    // vector<vector<int>> dp(n, vector<int>(2, 0));

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // step2: analyze base case

    // step3: convert recursive solution into dp solution
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            // buy allowed
            if (buy)
            {
                int buyKaro = -prices[index] + dp[index + 1][0];
                int skipKaro = 0 + dp[index + 1][1];
                profit = max(buyKaro, skipKaro);
            }
            // buy not allowed
            else
            {
                int sellKaro = prices[index] + dp[index + 1][1];
                int skipKaro = 0 + dp[index + 1][0];
                profit = max(sellKaro, skipKaro);
            }
            // step2: store in dp array
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

int maxProfit(vector<int> &prices)
{
    return solve(prices);
}

int main()
{

    return 0;
}