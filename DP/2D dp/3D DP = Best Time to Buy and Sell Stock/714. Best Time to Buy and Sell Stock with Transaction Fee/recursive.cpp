#include <iostream>
#include <vector>
using namespace std;

//THIS QUESTION IS SAME AS 122. BEST TIME TO BUY...

int solve(int index, int buy, vector<int> &prices, int fees)
{
    // base case
    if (index == prices.size())
        return 0;

    int profit = 0;
    // buy allowed
    if (buy)
    {
        int buyKaro = -prices[index] + solve(index + 1, 0, prices, fees);
        int skipKaro = 0 + solve(index + 1, 1, prices, fees);
        profit = max(buyKaro, skipKaro);
    }
    // buy not allowed
    else
    {
        int sellKaro = prices[index] + solve(index + 1, 1, prices, fees);
        int skipKaro = 0 + solve(index + 1, 0, prices, fees);
        profit = max(sellKaro, skipKaro);
    }
    return profit;
}

int maxProfit(vector<int> &prices, int fees)
{
    return solve(0, 1, prices, fees);
}

int main()
{

    return 0;
}