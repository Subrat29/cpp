#include <iostream>
#include <vector>
using namespace std;

int solve(int index, int buy, vector<int> &prices)
{
    // base case
    if (index == prices.size())
        return 0;

    int profit = 0;
    // buy allowed
    if (buy)
    {
        int buyKaro = -prices[index] + solve(index + 1, 0, prices);
        int skipKaro = 0 + solve(index + 1, 1, prices);
        profit = max(buyKaro, skipKaro);
    }
    // buy not allowed
    else
    {
        int sellKaro = prices[index] + solve(index + 1, 1, prices);
        int skipKaro = 0 + solve(index + 1, 0, prices);
        profit = max(sellKaro, skipKaro);
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    return solve(0, 1, prices);
}

int main()
{

    return 0;
}