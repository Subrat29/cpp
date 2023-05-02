#include <iostream>
#include <vector>
using namespace std;

int solve(int index, int buy, vector<int> &prices, vector<vector<int>>&dp)
{
    // base case
    if (index == prices.size())
        return 0;

    // step3: check base case
    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;
    // buy allowed
    if (buy)
    {
        int buyKaro = -prices[index] + solve(index + 1, 0, prices, dp);
        int skipKaro = 0 + solve(index + 1, 1, prices, dp);
        profit = max(buyKaro, skipKaro);
    }
    // buy not allowed
    else
    {
        int sellKaro = prices[index] + solve(index + 1, 1, prices, dp);
        int skipKaro = 0 + solve(index + 1, 0, prices, dp);
        profit = max(sellKaro, skipKaro);
    }
    // step2: store in dp array
    return dp[index][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    // step1: create dp array
    // row = n
    // col = 2
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return solve(0, 1, prices, dp);
}

int main()
{

    return 0;
}