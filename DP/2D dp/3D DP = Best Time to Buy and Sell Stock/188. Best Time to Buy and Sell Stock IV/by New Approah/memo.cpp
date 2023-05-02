#include <iostream>
#include <vector>
using namespace std;

// New approch : by use of transaction number

int solve(int index, int transactionNo, int k, vector<int> &prices, vector<vector<int>> &dp)
{
    // base case
    if (index == prices.size())
        return 0;

    // base case
    if (transactionNo == 2 * k)
        return 0;

    // step3: check base case
    if (dp[index][transactionNo] != -1)
        return dp[index][transactionNo];

    int profit = 0;

    // buy allowed
    if (transactionNo % 2 == 0)
    {
        int buyKaro = -prices[index] + solve(index + 1, transactionNo + 1, k, prices, dp);
        int skipKaro = 0 + solve(index + 1, transactionNo, k, prices, dp);
        profit = max(buyKaro, skipKaro);
    }
    // buy not allowed
    else
    {
        int sellKaro = prices[index] + solve(index + 1, transactionNo + 1, k, prices, dp);
        int skipKaro = 0 + solve(index + 1, transactionNo, k, prices, dp);
        profit = max(sellKaro, skipKaro);
    }
    // step2: store in dp
    return dp[index][transactionNo] = profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    // step1: create dp array
    vector<vector<int>> dp(n, vector<int>(2*k, -1));

    return solve(0, 0, k, prices, dp);
}

int main()
{

    return 0;
}