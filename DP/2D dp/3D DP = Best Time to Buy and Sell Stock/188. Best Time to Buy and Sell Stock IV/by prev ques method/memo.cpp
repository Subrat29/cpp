#include <iostream>
#include <vector>
using namespace std;

int solve(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>> &dp)
{
    // base case
    if (index == prices.size())
        return 0;

    // base case
    if (limit == 0)
        return 0;

    // step2: check base case
    if (dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = 0;

    // buy allowed
    if (buy)
    {
        int buyKaro = -prices[index] + solve(index + 1, 0, prices, limit, dp);
        int skipKaro = 0 + solve(index + 1, 1, prices, limit, dp);
        profit = max(buyKaro, skipKaro);
    }
    // buy not allowed
    else
    {
        int sellKaro = prices[index] + solve(index + 1, 1, prices, limit - 1, dp);
        int skipKaro = 0 + solve(index + 1, 0, prices, limit, dp);
        profit = max(sellKaro, skipKaro);
    }
    // step3: store in dp
    return dp[index][buy][limit] = profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    // step1: create a dp array
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

    return solve(0, 1, prices, k, dp);
}

int main()
{

    return 0;
}